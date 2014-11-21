#ifndef __ENCOSHARED_IVIEW_H__
#define __ENCOSHARED_IVIEW_H__

#pragma once

#include "stdafx.h"
#include "Vector2.h"

namespace enco {
	class IView {
	protected:
		Vector2ui m_size;

	public:
		IView() {  }
		virtual ~IView() {  }
		
		virtual void create() = 0;
		virtual void destroy() = 0;

		virtual void update(float deltaTime) = 0;

		inline void setSize(const Vector2ui &size) { m_size = size; }
		inline Vector2ui getSize() const { return m_size; }
	};
}

#endif