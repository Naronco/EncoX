#ifndef __ENCODESKTOP_DESKTOPOPENGLCONTEXT_H__
#define __ENCODESKTOP_DESKTOPOPENGLCONTEXT_H__

#pragma once

#include "stdafx.h"

#include <EncoShared\EncoShared.h>

namespace enco {
	class DesktopOpenGLContext : public IOpenGLContext {
	public:
		ENCODESKTOPAPI DesktopOpenGLContext(SDL_Window *window, const OpenGLContextParameters &parameters);
		ENCODESKTOPAPI ~DesktopOpenGLContext();

		ENCODESKTOPAPI virtual void makeCurrent();

		inline SDL_GLContext getSDLGLContext() const { return m_sdlGLContext; }

	private:
		SDL_Window *m_window;
		SDL_GLContext m_sdlGLContext;
	};
}

#endif