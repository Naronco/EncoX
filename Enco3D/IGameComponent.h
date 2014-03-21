#ifndef _IGAMECOMPONENT_H_
#define _IGAMECOMPONENT_H_

#include "RenderingEngine.h"
#include "PhysicsEngine.h"
#include "GLWindow.h"
#include "Timer.h"
#include "Transform.h"

class IGameComponent
{
protected:
	RenderingEngine *m_renderingEngine{ nullptr };
	PhysicsEngine *m_physicsEngine{ nullptr };
	GLWindow *m_window{ nullptr };
	Timer *m_timer{ nullptr };
	Transform *m_transform{ nullptr };

public:
	virtual void Init() {  }
	virtual void Deinit() {  }

	virtual void InitPhysics() {  }

	virtual void Update() {  }
	virtual void Render() {  }

	inline void SetRenderingEngine(RenderingEngine *renderingEngine) { m_renderingEngine = renderingEngine; }
	inline void SetPhysicsEngine(PhysicsEngine *physicsEngine) { m_physicsEngine = physicsEngine; }
	inline void SetWindow(GLWindow *window) { m_window = window; }
	inline void SetTimer(Timer *timer) { m_timer = timer; }
	inline void SetTransform(Transform *transform) { m_transform = transform; }

	inline RenderingEngine *GetRenderingEngine() const { return m_renderingEngine; }
	inline PhysicsEngine *GetPhysicsEngine() const { return m_physicsEngine; }
	inline GLWindow *GetWindow() const { return m_window; }
	inline Timer *GetTimer() const { return m_timer; }
	inline Transform *GetTransform() const { return m_transform; }
};

#endif