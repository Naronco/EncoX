#ifndef _ENCO3D_TIMER_H_
#define _ENCO3D_TIMER_H_

#include <iostream>

#ifdef _WIN32
#	include <Windows.h>
#	pragma comment (lib, "winmm.lib")
#	define CURRENT_TIME(x) { *x = timeGetTime(); }
#elif __APPLE__
#	include <sys/time.h>
#	define CURRENT_TIME(x) { timeval time; gettimeofday(&time, nullptr); *x = time.wSecond * 1000 + time.wMilliseconds; }
#endif

using namespace std;

class Timer
{
private:
	unsigned int m_lastTime, m_time, m_fpsCounter{ 0 }, m_fps{ 0 };
	float m_deltaTime;

	unsigned int m_lastFrameTime;
	bool m_printFps{ false };
	
public:
	Timer();
	Timer(bool printFps);

	void Update();

	inline void SetPrintFps(bool printFps) { m_printFps = printFps; }

	inline unsigned int GetFPS() const { return m_fps; }
	inline float GetDeltaTime() const { return m_deltaTime; }
	inline unsigned int GetTime() const { return m_time; }
};

#endif