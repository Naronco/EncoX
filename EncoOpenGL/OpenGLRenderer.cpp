#include "stdafx.h"
#include "OpenGLRenderer.h"

#include <SDL2/SDL.h>
#ifdef _WIN32
#	pragma comment (lib, "SDL2.lib")
#	include <glew/glew.h>
#	pragma comment (lib, "glew32.lib")
#	pragma comment (lib, "opengl32.lib")
#endif

namespace enco {
	ENCOOPENGLAPI void OpenGLRenderer::createContext(int x, int y, uint width, uint height, uint colorBits, uint depthBits, uint stencilBits, bool fullscreen, SDL_WINDOW sdlWindow) {
		if (sdlWindow) {
			m_sdlWindow = sdlWindow;

			SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, (int)depthBits);
			SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, (int)stencilBits);

			SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

			m_sdlGlContext = SDL_GL_CreateContext((SDL_Window *)m_sdlWindow);
			if (!m_sdlGlContext) {
#ifdef _DEBUG
				const char *error = SDL_GetError();
				if (*error != '\0') {
					fprintf(stderr, "SDL Error: %s\n", error);
					SDL_ClearError();
				}
#endif
			}

			GLenum glewErr = glewInit();
			if (glewErr != GLEW_OK) {
#ifdef _DEBUG
				fprintf(stderr, "GLEW Error: %s\n", glewGetErrorString(glewErr));
#endif
			}

			fprintf(stdout, "Using GLEW %s\n", glewGetString(GLEW_VERSION));
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

	ENCOOPENGLAPI void OpenGLRenderer::makeCurrent() {
		if (m_sdlGlContext) {
			SDL_GL_MakeCurrent((SDL_Window *)m_sdlWindow, m_sdlGlContext);
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

	ENCOOPENGLAPI RenderableMesh createMesh(Mesh* mesh)
	{
		return 0;
	}

	ENCOOPENGLAPI void deleteMesh(RenderableMesh id)
	{
	}

	/*ENCOOPENGLAPI int32 OpenGLRenderer::createVertexBuffer(const void *vertexData, const VertexDeclaration &vertexDeclaration, u32 vertexCount) {
		GLuint vertexBufferID;
		glGenBuffers(1, &vertexBufferID);

		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
		glBufferData(GL_ARRAY_BUFFER, vertexDeclaration.getSize(), vertexData, GL_STATIC_DRAW);

		m_vertexBuffers[vertexBufferID] = { vertexDeclaration, vertexCount };

		return (int32)vertexBufferID;
		}

		ENCOOPENGLAPI void OpenGLRenderer::renderVertexBuffer(int32 vertexBuffer) {
		glBindBuffer(GL_ARRAY_BUFFER, (GLuint)vertexBuffer);

		auto vertexDecl = m_vertexBuffers[(u32)vertexBuffer].vertexDecl;
		for (auto element : vertexDecl.getElements()) {
		glEnableVertexAttribArray(element.usage);
		glVertexAttribPointer(element.usage, g_vertexElementFormatGLSizes[element.format], g_vertexElementFormatTypes[element.format], GL_FALSE, vertexDecl.getSize(), (uchar *)nullptr + element.offset);
		}

		glDrawArrays(GL_TRIANGLES, 0, m_vertexBuffers[(u32)vertexBuffer].vertexCount);

		for (auto element : vertexDecl.getElements()) {
		glDisableVertexAttribArray(element.usage);
		}
		}

		ENCOOPENGLAPI void OpenGLRenderer::deleteVertexBuffer(int32 vertexBuffer) {
		GLuint vertexBufferID = (GLuint)vertexBuffer;
		m_vertexBuffers.erase(m_vertexBuffers.find(vertexBufferID));
		glDeleteBuffers(1, &vertexBufferID);
		}*/

	const GLenum g_vertexElementFormatTypes[] = {
		GL_FLOAT, GL_FLOAT, GL_FLOAT, GL_FLOAT, GL_FLOAT, GL_FLOAT, GL_FLOAT, GL_FLOAT, GL_INT
	};

	const GLenum g_vertexElementFormatGLSizes[] = {
		1, 2, 3, 4, 1, 2, 3, 4, 1
	};
}