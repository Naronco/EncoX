#pragma once

#ifdef _WIN32

#	include "targetver.h"

#	define WIN32_LEAN_AND_MEAN
#	include <windows.h>

#	include <SDL2\SDL.h>
#	pragma comment (lib, "SDL2.lib")

#	include <glew\glew.h>
#	pragma comment (lib, "glew32.lib")
#	pragma comment (lib, "opengl32.lib")

#	ifdef ENCODESKTOP_EXPORTS
#		define ENCODESKTOPAPI __declspec(dllexport)
#	else
#		define ENCODESKTOPAPI __declspec(dllimport)
#	endif

#else

#	define ENCODESKTOPAPI

#endif
