#ifndef __ENCOSHARED_ENCOCONTEXT_H__
#define __ENCOSHARED_ENCOCONTEXT_H__

#pragma once

#include "stdafx.h"
#include "IView.h"
#include "IRenderer.h"

#include <memory>

namespace enco {
	class EncoContext {
	public:
		ENCOSHAREDAPI EncoContext(std::shared_ptr<IView> mainView, std::shared_ptr<IRenderer> renderer);
		ENCOSHAREDAPI ~EncoContext();

		ENCOSHAREDAPI void start();
		ENCOSHAREDAPI void stop();
		ENCOSHAREDAPI bool update();

		inline std::shared_ptr<IView> getMainView() const { return m_mainView; }
		
	private:
		std::shared_ptr<IView> m_mainView;
		std::shared_ptr<IRenderer> m_renderer;
	};
}

#endif