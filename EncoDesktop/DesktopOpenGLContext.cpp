#include "stdafx.h"
#include "DesktopOpenGLContext.h"

namespace enco {
	ENCODESKTOPAPI DesktopOpenGLContext::DesktopOpenGLContext(SDL_Window *window, const OpenGLContextParameters &parameters) : m_window(window) {
		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, (int)parameters.redSize);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, (int)parameters.greenSize);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, (int)parameters.blueSize);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, (int)parameters.alphaSize);

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, (int)parameters.doublebufferSize);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, (int)parameters.depthbufferSize);
		SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, (int)parameters.stencilbufferSize);

		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, (int)parameters.samples);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, (int)parameters.majorVersion);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, (int)parameters.minorVersion);

		m_sdlGLContext = SDL_GL_CreateContext(window);
		if (!m_sdlGLContext) {
			// TODO: Error handling
			return;
		}
	}

	ENCODESKTOPAPI DesktopOpenGLContext::~DesktopOpenGLContext() {
		if (m_sdlGLContext) {
			SDL_GL_DeleteContext(m_sdlGLContext);
			m_sdlGLContext = nullptr;
		}
	}

	ENCODESKTOPAPI void DesktopOpenGLContext::makeCurrent() {
		SDL_GL_MakeCurrent(m_window, m_sdlGLContext);
	}
}