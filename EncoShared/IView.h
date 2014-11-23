#ifndef __ENCOSHARED_IVIEW_H__
#define __ENCOSHARED_IVIEW_H__

#pragma once

#include "stdafx.h"
#include "IRenderer.h"

#include <memory>
#include <string>
#include <map>

namespace enco {
	/*struct OpenGLContextParameters {
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
	};*/

	class IView {
	protected:
		glm::u32vec2 m_size;
		std::string m_name;

		virtual void onResize() {  }
		virtual void onRename() {  }

	public:
		IView() {  }
		virtual ~IView() {  }

		virtual void create(IRenderer *renderer) = 0;
		virtual void destroy() = 0;

		virtual bool update(float deltaTime) = 0;

		inline void setSize(const glm::u32vec2 &size) { m_size = size; onResize(); }
		inline void setName(const std::string &name) { m_name = name; onRename(); }

		inline glm::u32vec2 getSize() const { return m_size; }
		inline std::string getName() const { return m_name; }
	};
}

#endif