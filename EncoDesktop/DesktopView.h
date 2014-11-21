#ifndef __ENCODESKTOP_DESKTOPVIEW_H__
#define __ENCODESKTOP_DESKTOPVIEW_H__

#pragma once

#include "stdafx.h"

#include <SDL2\SDL.h>
#include <EncoShared\EncoShared.h>

#pragma comment (lib, "SDL2.lib")

namespace enco {
	class DesktopView : public IView {
	public:
		inline DesktopView() : m_window(nullptr) {  }

		ENCODESKTOPAPI virtual void create();
		ENCODESKTOPAPI virtual void destroy();

		ENCODESKTOPAPI virtual void update(float deltaTime);

	private:
		SDL_Window *m_window;
	};
}

#endif