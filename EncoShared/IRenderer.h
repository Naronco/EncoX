#ifndef __ENCOSHARED_IRENDERER_H__
#define __ENCOSHARED_IRENDERER_H__

#pragma once

#include "stdafx.h"
#include "Color3.h"

namespace enco {
	class IRenderer {
	public:
		IRenderer() {  }
		virtual ~IRenderer() {  }

		virtual void setClearColor(const Color3f &clearColor) = 0;
	};
}

#endif