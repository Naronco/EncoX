#include "stdafx.h"
#include "DesktopView.h"

namespace enco {
	ENCODESKTOPAPI void DesktopView::create() {
		SDL_Init(SDL_INIT_EVERYTHING);

		m_window = SDL_CreateWindow("EncoX", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)m_size.x, (int)m_size.y, SDL_WINDOW_SHOWN);
		if (!m_window) {
			// TODO: Error handling
			return;
		}
	}

	ENCODESKTOPAPI void DesktopView::destroy() {
		if (m_window) {
			SDL_DestroyWindow(m_window);
			m_window = nullptr;
		}
	}

	ENCODESKTOPAPI void DesktopView::update(float deltaTime) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				exit(0); // TODO: Better quit
				break;
			}
		}
	}
}