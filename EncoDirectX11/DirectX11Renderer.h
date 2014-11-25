#ifndef __ENCODIRECTX11_DIRECTX11RENDERER_H__
#define __ENCODIRECTX11_DIRECTX11RENDERER_H__

#pragma once

#include "stdafx.h"

#include <EncoShared\EncoShared.h>
#include <map>

namespace enco {
	class DirectX11Renderer : public IRenderer {
	public:
		inline DirectX11Renderer() : m_hwnd(nullptr) {  }

		ENCODIRECTX11API virtual void createContext(int x, int y, uint width, uint height, uint colorBits, uint depthBits, uint stencilBits, bool fullscreen, SDL_WINDOW sdlWindow);
		ENCODIRECTX11API virtual void deleteContext();

		ENCODIRECTX11API virtual int getSDLOptions();

		ENCODIRECTX11API virtual void beginFrame() {}
		ENCODIRECTX11API virtual void endFrame();

		ENCODIRECTX11API virtual void makeCurrent() {}

		ENCODIRECTX11API virtual void setClearColor(f32 r, f32 g, f32 b);
		ENCODIRECTX11API virtual void setClearDepth(f64 clearDepth);

		ENCODIRECTX11API virtual void clearBuffer(int buffers);

		ENCODIRECTX11API virtual int32 createVertexBuffer(const void *vertexData, const VertexDeclaration &vertexDeclaration, u32 vertexCount);
		ENCODIRECTX11API virtual void renderVertexBuffer(int32 vertexBuffer);
		ENCODIRECTX11API virtual void deleteVertexBuffer(int32 vertexBuffer);

		ENCODIRECTX11API inline int getFeatureLevel() { return m_featureLevel; }
		ENCODIRECTX11API inline int getDriverType() { return m_driverType; }

	private:
		ID3D11Device* m_device;
		ID3D11DeviceContext* m_immediateContext;
		IDXGISwapChain* m_swapChain;
		ID3D11RenderTargetView* m_renderTargetView;

		D3D_DRIVER_TYPE m_driverType = D3D_DRIVER_TYPE_NULL;
		D3D_FEATURE_LEVEL m_featureLevel = D3D_FEATURE_LEVEL_11_0;

		f32* m_clearColor;
		f64 m_clearDepth;

		HWND m_hwnd;
	};
}

#endif