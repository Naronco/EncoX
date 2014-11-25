#include <EncoShared\EncoShared.h>
#include <EncoDesktop\EncoDesktop.h>
#include <EncoOpenGL\EncoOpenGL.h>
#include <EncoDirectX11\DirectX11Renderer.h>

#ifdef _WIN32
#	pragma comment (lib, "EncoDesktop.lib")
#	pragma comment (lib, "EncoOpenGL.lib")
#	pragma comment (lib, "EncoDirectX11.lib")
#	pragma comment (lib, "EncoShared.lib")
#endif

using namespace enco;

#ifdef main
#	undef main
#endif

int main(int argc, char *argv[]) {
	std::shared_ptr<DesktopView> view;
	std::shared_ptr<IRenderer> renderer;

	std::string rendererType = "dx";

	if (argc > 1)
	{
		rendererType = argv[1];
	}

	if (rendererType == "ogl")
	{
		view = std::make_shared<DesktopView>(L"EncoX (OpenGL)", 1280, 720);
		renderer = std::make_shared<OpenGLRenderer>();
	}
	else if (rendererType == "dx")
	{
		view = std::make_shared<DesktopView>(L"EncoX (DirectX 11)", 1280, 720);
		renderer = std::make_shared<DirectX11Renderer>();
	}
	else
	{
		fprintf(stdout, "No such rendering engine: ", rendererType);
		return 0;
	}

	auto context = std::make_unique<EncoContext>(view, renderer);

	context->start();

	while (context->update()) {
		renderer->beginFrame();

		renderer->setClearColor(0.5f, 0.8f, 1.0f);
		renderer->clearBuffer(RenderingBuffer::colorBuffer | RenderingBuffer::depthBuffer);

		renderer->endFrame();
	}

	context->stop();

	return 0;
}