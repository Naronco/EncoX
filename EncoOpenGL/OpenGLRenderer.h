#ifndef __ENCOOPENGL_OPENGLRENDERER_H__
#define __ENCOOPENGL_OPENGLRENDERER_H__

#pragma once

#include "stdafx.h"

#include <EncoShared\EncoShared.h>

namespace enco {
	class OpenGLRenderer : public IRenderer {
	public:
		ENCOOPENGLAPI virtual void setClearColor(const Color3f &clearColor);
		ENCOOPENGLAPI virtual void setClearDepth(float64 clearDepth);

		ENCOOPENGLAPI virtual void clearBuffer(int buffers);
	};
}

#endif