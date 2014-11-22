#include "stdafx.h"
#include "OpenGLRenderer.h"

namespace enco {
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