#ifndef __ENCODESKTOP_DESKTOPVIEW_H__
#define __ENCODESKTOP_DESKTOPVIEW_H__

#pragma once

#include "stdafx.h"
#include "DesktopOpenGLContext.h"

#include <EncoShared\EncoShared.h>

namespace enco {
	class DesktopView : public IView {
	public:
		inline DesktopView(const glm::u32vec2 &size = glm::u32vec2(320, 240)) : m_window(nullptr), m_openGLContext(nullptr) { m_size = size; }
		inline DesktopView(u32 width, u32 height) : DesktopView(glm::u32vec2(width, height)) {  }

		ENCODESKTOPAPI virtual void create();
		ENCODESKTOPAPI virtual void destroy();

		ENCODESKTOPAPI virtual bool update(float deltaTime);

		ENCODESKTOPAPI virtual void beginScene();
		ENCODESKTOPAPI virtual void endScene();

		ENCODESKTOPAPI virtual void createOpenGLContext(const OpenGLContextParameters &parameters);

		inline virtual std::shared_ptr<IOpenGLContext> getOpenGLContext() const { return m_openGLContext; }

	private:
		SDL_Window *m_window;
		std::shared_ptr<IOpenGLContext> m_openGLContext;
	};
}

#endif