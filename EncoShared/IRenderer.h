#ifndef __ENCOSHARED_IRENDERER_H__
#define __ENCOSHARED_IRENDERER_H__

#pragma once

#include "stdafx.h"
#include "Color3.h"

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

		virtual void setClearColor(const Color3f &clearColor) = 0;
		virtual void setClearDepth(float64 clearDepth) = 0;

		virtual void clearBuffer(int buffers) = 0;
	};
}

#endif