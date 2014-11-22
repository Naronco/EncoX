#ifndef __ENCOOPENGL_OPENGLRENDERER_H__
#define __ENCOOPENGL_OPENGLRENDERER_H__

#pragma once

#include "stdafx.h"

#include <EncoShared\EncoShared.h>

namespace enco {
	class OpenGLRenderer : public IRenderer {
	public:
		ENCOOPENGLAPI virtual void setClearColor(f32 r, f32 g, f32 b);
		ENCOOPENGLAPI virtual void setClearDepth(f64 clearDepth);

		ENCOOPENGLAPI virtual void clearBuffer(int buffers);
	};
}

#endif