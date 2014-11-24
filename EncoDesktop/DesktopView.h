#ifndef __ENCODESKTOP_DESKTOPVIEW_H__
#define __ENCODESKTOP_DESKTOPVIEW_H__

#pragma once

#include "stdafx.h"

#include <EncoShared\EncoShared.h>
#include <codecvt>

namespace enco {
	class DesktopView : public IView {
	public:
		inline DesktopView(const std::string &title, const glm::u32vec2 &size = glm::u32vec2(320, 240)) : m_window(nullptr) { m_name = title; m_size = size; }
		inline DesktopView(const std::string &title, u32 width, u32 height) : DesktopView(title, glm::u32vec2(width, height)) {  }
		inline DesktopView(const std::wstring &title, const glm::u32vec2 &size = glm::u32vec2(320, 240)) : DesktopView(wstrToStr(title), size) {  }
		inline DesktopView(const std::wstring &title, u32 width, u32 height) : DesktopView(wstrToStr(title), glm::u32vec2(width, height)) {  }

		ENCODESKTOPAPI virtual void create(IRenderer *renderer);
		ENCODESKTOPAPI virtual void destroy();

		ENCODESKTOPAPI virtual bool update(float deltaTime);

		ENCODESKTOPAPI virtual void onResize();
		ENCODESKTOPAPI virtual void onRename();

	private:
		SDL_Window *m_window;
		IRenderer *m_renderer;
	};
}

#endif