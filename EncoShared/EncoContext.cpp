#include "stdafx.h"
#include "EncoContext.h"

namespace enco {
	ENCOSHAREDAPI EncoContext::EncoContext(std::shared_ptr<IView> mainView, std::shared_ptr<IRenderer> renderer) : m_mainView(mainView), m_renderer(renderer) {
	}

	ENCOSHAREDAPI EncoContext::~EncoContext() {
	}

	ENCOSHAREDAPI void EncoContext::start() {
		m_mainView->create(m_renderer.get());
	}

	ENCOSHAREDAPI void EncoContext::stop() {
		m_mainView->destroy();
	}

	ENCOSHAREDAPI bool EncoContext::update() {
		return m_mainView->update(0); // TODO: Add proper delta time
	}
}