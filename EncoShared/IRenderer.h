#ifndef __ENCOSHARED_IRENDERER_H__
#define __ENCOSHARED_IRENDERER_H__

#pragma once

#include "stdafx.h"

namespace enco {
	enum RenderingBuffer : uint8 {
		colorBuffer   = 1 << 0,
		depthBuffer   = 1 << 1,
		stencilBuffer = 1 << 2,
	};

	class IRenderer {
	public:
		IRenderer() {  }
		virtual ~IRenderer() {  }

		inline void setClearColor(const glm::vec3 &clearColor) { setClearColor(clearColor.r, clearColor.g, clearColor.b); }
		virtual void setClearColor(f32 r, f32 g, f32 b) = 0;

		virtual void setClearDepth(f64 clearDepth) = 0;

		virtual void clearBuffer(int buffers) = 0;
	};
}

#endif