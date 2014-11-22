#include "stdafx.h"
#include "DesktopView.h"

namespace enco {
	ENCODESKTOPAPI void DesktopView::create() {
		SDL_Init(SDL_INIT_VIDEO);

		m_window = SDL_CreateWindow("EncoX", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)m_size.x, (int)m_size.y, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
		if (!m_window) {
			// TODO: Error handling
			return;
		}

		if (glewInit() == GL_FALSE) {
#ifdef _DEBUG
			printf("GLEW Error: Initialization\n");
#endif
			return;
		}
	}

	ENCODESKTOPAPI void DesktopView::destroy() {
		if (m_openGLContext) {
			m_openGLContext.reset();
		}

		if (m_window) {
			SDL_DestroyWindow(m_window);
			m_window = nullptr;
		}

		SDL_Quit();
	}

	ENCODESKTOPAPI bool DesktopView::update(float deltaTime) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				return false;
			}
		}

		return true;
	}

	ENCODESKTOPAPI void DesktopView::beginScene() {
	}

	ENCODESKTOPAPI void DesktopView::endScene() {
		SDL_GL_SwapWindow(m_window);
	}

	ENCODESKTOPAPI void DesktopView::createOpenGLContext(const OpenGLContextParameters &parameters) {
		m_openGLContext = std::shared_ptr<DesktopOpenGLContext>(new DesktopOpenGLContext(m_window, parameters));
		m_openGLContext->makeCurrent();
	}
}