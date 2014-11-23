#include "stdafx.h"
#include "OpenGLRenderer.h"

#include <SDL2/SDL.h>
#ifdef _WIN32
#	pragma comment (lib, "SDL2.lib")
#	include <glew/glew.h>
#endif

namespace enco {
	ENCOOPENGLAPI void OpenGLRenderer::createContext(int x, int y, uint width, uint height, uint colorBits, uint depthBits, uint stencilBits, bool fullscreen, SDL_WINDOW sdlWindow) {
		if (sdlWindow) {
			m_sdlWindow = sdlWindow;

			m_sdlGlContext = SDL_GL_CreateContext((SDL_Window *)m_sdlWindow);
			if (!m_sdlGlContext) {
#ifdef _DEBUG
				const char *error = SDL_GetError();
				if (*error != '\0') {
					printf("SDL Error: %s\n", error);
					SDL_ClearError();
				}
#endif
			}
		}
	}

	ENCOOPENGLAPI void OpenGLRenderer::deleteContext() {
		if (m_sdlGlContext) {
			SDL_GL_DeleteContext((SDL_GLContext)m_sdlGlContext);
			m_sdlGlContext = nullptr;
		}
	}

	ENCOOPENGLAPI int OpenGLRenderer::getSDLOptions() {
		return SDL_WINDOW_OPENGL;
	}

	ENCOOPENGLAPI void OpenGLRenderer::beginFrame() {
	}

	ENCOOPENGLAPI void OpenGLRenderer::endFrame() {
		if (m_sdlGlContext) {
			SDL_GL_SwapWindow((SDL_Window *)m_sdlWindow);
		}
	}

	ENCOOPENGLAPI void OpenGLRenderer::setClearColor(f32 r, f32 g, f32 b) {
		glClearColor(r, g, b, 1);
	}

	ENCOOPENGLAPI void OpenGLRenderer::setClearDepth(f64 clearDepth) {
		glClearDepth(clearDepth);
	}

	ENCOOPENGLAPI void OpenGLRenderer::clearBuffer(int buffers) {
		if ((buffers & RenderingBuffer::colorBuffer) == RenderingBuffer::colorBuffer) {
			glClear(GL_COLOR_BUFFER_BIT);
		}
		if ((buffers & RenderingBuffer::depthBuffer) == RenderingBuffer::depthBuffer) {
			glClear(GL_DEPTH_BUFFER_BIT);
		}
		if ((buffers & RenderingBuffer::stencilBuffer) == RenderingBuffer::stencilBuffer) {
			glClear(GL_STENCIL_BUFFER_BIT);
		}
	}
}