#ifndef __ENCOOPENGL_OPENGLRENDERER_H__
#define __ENCOOPENGL_OPENGLRENDERER_H__

#pragma once

#include "stdafx.h"

#include <EncoShared\EncoShared.h>
#include <map>

namespace enco {
	typedef void *SDL_GLCONTEXT;

	struct OGL_VertexBuffer {
		VertexDeclaration vertexDecl;
		u32 vertexCount;
	};

	class OpenGLRenderer : public IRenderer {
	public:
		inline OpenGLRenderer() : m_sdlWindow(nullptr), m_sdlGlContext(nullptr) {  }

		ENCOOPENGLAPI virtual void createContext(int x, int y, uint width, uint height, uint colorBits, uint depthBits, uint stencilBits, bool fullscreen, SDL_WINDOW sdlWindow);
		ENCOOPENGLAPI virtual void deleteContext();

		ENCOOPENGLAPI virtual int getSDLOptions();

		ENCOOPENGLAPI virtual void beginFrame();
		ENCOOPENGLAPI virtual void endFrame();

		ENCOOPENGLAPI virtual void setClearColor(f32 r, f32 g, f32 b);
		ENCOOPENGLAPI virtual void setClearDepth(f64 clearDepth);

		ENCOOPENGLAPI virtual void clearBuffer(int buffers);

		ENCOOPENGLAPI virtual int32 createVertexBuffer(const void *vertexData, const VertexDeclaration &vertexDeclaration, u32 vertexCount);
		ENCOOPENGLAPI virtual void renderVertexBuffer(int32 vertexBuffer);
		ENCOOPENGLAPI virtual void deleteVertexBuffer(int32 vertexBuffer);

	private:
		SDL_WINDOW m_sdlWindow;
		SDL_GLCONTEXT m_sdlGlContext;
		std::map<GLuint, OGL_VertexBuffer> m_vertexBuffers;
	};
}

#endif