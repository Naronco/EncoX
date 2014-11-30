#include "stdafx.h"
#include "DirectX11Renderer.h"

namespace enco {
	ENCODIRECTX11API void DirectX11Renderer::createContext(int x, int y, uint width, uint height, uint colorBits, uint depthBits, uint stencilBits, bool fullscreen, SDL_WINDOW sdlWindow) {
		if (sdlWindow) {
			HRESULT hr = S_OK;

			m_hwnd = GetActiveWindow();
			m_clearColor = new f32[] { 0.0f, 0.0f, 0.0f, 1.0f };
			m_device = 0;
			m_immediateContext = 0;
			m_renderTargetView = 0;
			m_swapChain = 0;

			RECT rc;
			GetClientRect(m_hwnd, &rc);
			u32 width = rc.right - rc.left;
			u32 height = rc.bottom - rc.top;

			u32 createDeviceFlags = 0;
#ifdef _DEBUG
			createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif
			D3D_DRIVER_TYPE driverTypes[] =
			{
				D3D_DRIVER_TYPE_HARDWARE,
				D3D_DRIVER_TYPE_WARP,
				D3D_DRIVER_TYPE_REFERENCE,
			};
			UINT numDriverTypes = ARRAYSIZE(driverTypes);

			D3D_FEATURE_LEVEL featureLevels[] =
			{
				D3D_FEATURE_LEVEL_11_0,
				D3D_FEATURE_LEVEL_10_1,
				D3D_FEATURE_LEVEL_10_0,
			};
			UINT numFeatureLevels = ARRAYSIZE(featureLevels);

			for (UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
			{
				m_driverType = driverTypes[driverTypeIndex];
				hr = D3D11CreateDevice(nullptr, m_driverType, nullptr, createDeviceFlags, featureLevels, numFeatureLevels,
					D3D11_SDK_VERSION, &m_device, &m_featureLevel, &m_immediateContext);

				if (SUCCEEDED(hr))
					break;
			}
			if (FAILED(hr))
			{
				fprintf(stdout, "Failed to initialize DirectX11 device\n");
				deleteContext();
				return;
			}

			// Obtain DXGI factory from device (since we used nullptr for pAdapter above)
			IDXGIFactory1* dxgiFactory = nullptr;
			{
				IDXGIDevice* dxgiDevice = nullptr;
				hr = m_device->QueryInterface(__uuidof(IDXGIDevice), reinterpret_cast<void**>(&dxgiDevice));
				if (SUCCEEDED(hr))
				{
					IDXGIAdapter* adapter = nullptr;
					hr = dxgiDevice->GetAdapter(&adapter);
					if (SUCCEEDED(hr))
					{
						hr = adapter->GetParent(__uuidof(IDXGIFactory1), reinterpret_cast<void**>(&dxgiFactory));
						adapter->Release();
					}
					dxgiDevice->Release();
				}
			}
			if (FAILED(hr))
			{
				fprintf(stdout, "Failed to initialize DirectX11 factory\n");
				deleteContext();
				return;
			}

			DXGI_SWAP_CHAIN_DESC sd;
			ZeroMemory(&sd, sizeof(sd));
			sd.BufferCount = 1;
			sd.BufferDesc.Width = width;
			sd.BufferDesc.Height = height;
			sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
			sd.BufferDesc.RefreshRate.Numerator = 60;
			sd.BufferDesc.RefreshRate.Denominator = 1;
			sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
			sd.OutputWindow = m_hwnd;
			sd.SampleDesc.Count = 1;
			sd.SampleDesc.Quality = 0;
			sd.Windowed = TRUE;

			hr = dxgiFactory->CreateSwapChain(m_device, &sd, &m_swapChain);

			dxgiFactory->Release();

			if (FAILED(hr))
			{
				fprintf(stdout, "Failed to initialize DirectX11 swap chain\n");
				deleteContext();
				return;
			}

			// Create a render target view
			ID3D11Texture2D* pBackBuffer = nullptr;
			hr = m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&pBackBuffer));
			if (FAILED(hr))
			{
				fprintf(stdout, "Failed to get DirectX11 back buffer\n");
				deleteContext();
				return;
			}

			hr = m_device->CreateRenderTargetView(pBackBuffer, nullptr, &m_renderTargetView);
			pBackBuffer->Release();
			if (FAILED(hr))
			{
				fprintf(stdout, "Failed to initialize DirectX11 render target view\n");
				deleteContext();
				return;
			}

			m_immediateContext->OMSetRenderTargets(1, &m_renderTargetView, nullptr);

			// Setup the viewport
			D3D11_VIEWPORT vp;
			vp.Width = (FLOAT)width;
			vp.Height = (FLOAT)height;
			vp.MinDepth = 0.0f;
			vp.MaxDepth = 1.0f;
			vp.TopLeftX = 0;
			vp.TopLeftY = 0;
			m_immediateContext->RSSetViewports(1, &vp);

			fprintf(stdout, "Initialized DirectX11 renderer\n");
		}
	}

	ENCODIRECTX11API void DirectX11Renderer::deleteContext() {
		if (m_immediateContext) m_immediateContext->ClearState();

		if (m_renderTargetView) m_renderTargetView->Release();
		if (m_swapChain) m_swapChain->Release();
		if (m_immediateContext) m_immediateContext->Release();
		if (m_device) m_device->Release();

		m_device = 0;
		m_renderTargetView = 0;
		m_swapChain = 0;
		m_immediateContext = 0;
	}

	ENCODIRECTX11API int DirectX11Renderer::getSDLOptions() {
		return 0;
	}

	ENCODIRECTX11API void DirectX11Renderer::endFrame() {
		if (m_swapChain) {
			m_swapChain->Present(0, 0);
		}
	}

	ENCODIRECTX11API void DirectX11Renderer::setClearColor(f32 r, f32 g, f32 b) {
		m_clearColor[0] = r;
		m_clearColor[1] = g;
		m_clearColor[2] = b;
	}

	ENCODIRECTX11API void DirectX11Renderer::setClearDepth(f64 clearDepth) {
		m_clearDepth = clearDepth;
	}

	ENCODIRECTX11API void DirectX11Renderer::clearBuffer(int buffers) {
		if (m_immediateContext)
		{
			if ((buffers & RenderingBuffer::colorBuffer) == RenderingBuffer::colorBuffer) {
				m_immediateContext->ClearRenderTargetView(m_renderTargetView, m_clearColor);
			}
			if ((buffers & RenderingBuffer::depthBuffer) == RenderingBuffer::depthBuffer || (buffers & RenderingBuffer::stencilBuffer) == RenderingBuffer::stencilBuffer) {
				// m_immediateContext->ClearDepthStencilView(NULL, (D3D11_CLEAR_DEPTH * (buffers & RenderingBuffer::depthBuffer) == RenderingBuffer::depthBuffer) | (D3D11_CLEAR_STENCIL * (buffers & RenderingBuffer::stencilBuffer) == RenderingBuffer::stencilBuffer), m_clearDepth, 0);
				// TODO: Add Depth/Stencil buffer
			}
		}
	}

	/*	ENCODIRECTX11API int32 DirectX11Renderer::createVertexBuffer(const void *vertexData, const VertexDeclaration &vertexDeclaration, u32 vertexCount) {
			return 0;
			}

			ENCODIRECTX11API void DirectX11Renderer::renderVertexBuffer(int32 vertexBuffer) {
			}

			ENCODIRECTX11API void DirectX11Renderer::deleteVertexBuffer(int32 vertexBuffer) {
			}*/

	ENCODIRECTX11API RenderableMesh createMesh(Mesh* mesh)
	{
		return 0;
	}

	ENCODIRECTX11API void deleteMesh(RenderableMesh id)
	{
	}
}