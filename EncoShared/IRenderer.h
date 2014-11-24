#ifndef __ENCOSHARED_IRENDERER_H__
#define __ENCOSHARED_IRENDERER_H__

#pragma once

#include "stdafx.h"
#include "VertexDeclaration.h"

namespace enco {
	typedef void *SDL_WINDOW;

	enum RenderingBuffer : uint8 {
		colorBuffer   = 1 << 0,
		depthBuffer   = 1 << 1,
		stencilBuffer = 1 << 2,
	};

	class IRenderer {
	public:
		IRenderer() {  }
		virtual ~IRenderer() {  }

		virtual void createContext(int x, int y, uint width, uint height, uint colorBits, uint depthBits, uint stencilBits, bool fullscreen, SDL_WINDOW sdlWindow = nullptr) = 0;
		virtual void deleteContext() = 0;

		virtual int getSDLOptions() = 0;

		virtual void beginFrame() = 0;
		virtual void endFrame() = 0;

		virtual void makeCurrent() = 0; // Only relevant for OpenGL

		inline void setClearColor(const glm::vec3 &clearColor) { setClearColor(clearColor.r, clearColor.g, clearColor.b); }
		virtual void setClearColor(f32 r, f32 g, f32 b) = 0;

		virtual void setClearDepth(f64 clearDepth) = 0;

		virtual void clearBuffer(int buffers) = 0;

		virtual int32 createVertexBuffer(const void *vertexData, const VertexDeclaration &vertexDeclaration, u32 vertexCount) = 0;
		virtual void renderVertexBuffer(int32 vertexBuffer) = 0;
		virtual void deleteVertexBuffer(int32 vertexBuffer) = 0;
	};
}

#endif