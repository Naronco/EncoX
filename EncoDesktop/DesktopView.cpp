#include "stdafx.h"
#include "DesktopView.h"

namespace enco {
	ENCODESKTOPAPI void DesktopView::create(IRenderer *renderer) {
		m_renderer = renderer;
		
		SDL_Init(SDL_INIT_VIDEO);

		m_window = SDL_CreateWindow(m_name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)m_size.x, (int)m_size.y, SDL_WINDOW_SHOWN | renderer->getSDLOptions());
		if (!m_window) {
			// TODO: Error handling
			return;
		}

		m_renderer->createContext(0, 0, m_size.x, m_size.y, 32, 16, 0, false, m_window);
	}

	ENCODESKTOPAPI void DesktopView::destroy() {
		/*if (m_openGLContext) {
			m_openGLContext.reset();
		}*/

		m_renderer->deleteContext();

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

	/*ENCODESKTOPAPI void DesktopView::createOpenGLContext(const OpenGLContextParameters &parameters) {
		m_openGLContext = std::shared_ptr<DesktopOpenGLContext>(new DesktopOpenGLContext(m_window, parameters));
		m_openGLContext->makeCurrent();
	}*/

	ENCODESKTOPAPI void DesktopView::onResize() {
		SDL_SetWindowSize(m_window, (int)m_size.x, (int)m_size.y);
	}

	ENCODESKTOPAPI void DesktopView::onRename() {
		SDL_SetWindowTitle(m_window, m_name.c_str());
	}
}