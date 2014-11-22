#ifndef __ENCOSHARED_IOPENGLCONTEXT_H__
#define __ENCOSHARED_IOPENGLCONTEXT_H__

#pragma once

#include "stdafx.h"

namespace enco {
	class IOpenGLContext {
	public:
		IOpenGLContext() {  }
		virtual ~IOpenGLContext() {  }

		virtual void makeCurrent() = 0;
	};
}

#endif