#ifndef __ENCOSHARED_IVIEW_H__
#define __ENCOSHARED_IVIEW_H__

#pragma once

#include "stdafx.h"
#include "Vector2.h"
#include "IOpenGLContext.h"

#include <memory>

namespace enco {
	class IView;
	struct OpenGLContextParameters;

	struct OpenGLContextParameters {
		uint8 redSize, greenSize, blueSize, alphaSize;
		uint8 doublebufferSize, depthbufferSize, stencilbufferSize;
		uint8 samples;
		uint8 majorVersion, minorVersion;

		inline OpenGLContextParameters() {
			redSize = greenSize = blueSize = alphaSize = 8;
			doublebufferSize = 1;
			depthbufferSize = 16;
			stencilbufferSize = 0;
			samples = 0;
			majorVersion = 3;
			minorVersion = 2;
		}
	};

	class IView {
	protected:
		Vector2ui m_size;

	public:
		IView() {  }
		virtual ~IView() {  }

		virtual void create() = 0;
		virtual void destroy() = 0;

		virtual bool update(float deltaTime) = 0;

		virtual void beginScene() = 0;
		virtual void endScene() = 0;

		virtual void createOpenGLContext(const OpenGLContextParameters &parameters) = 0;
		virtual std::shared_ptr<IOpenGLContext> getOpenGLContext() const = 0;

		inline void setSize(const Vector2ui &size) { m_size = size; }
		inline Vector2ui getSize() const { return m_size; }
	};
}

#endif