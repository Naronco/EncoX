#ifndef __ENCOOPENGL_STDAFX_H__
#define __ENCOOPENGL_STDAFX_H__

#pragma once

#ifdef _WIN32
#	include "targetver.h"

#	define WIN32_LEAN_AND_MEAN
#	include <windows.h>

#	include <glew\glew.h>
#	pragma comment (lib, "glew32.lib")
#	pragma comment (lib, "opengl32.lib")

#	ifdef ENCOOPENGL_EXPORTS
#		define ENCOOPENGLAPI __declspec(dllexport)
#	else
#		define ENCOOPENGLAPI __declspec(dllimport)
#	endif
#else
#	define ENCOOPENGLAPI
#endif

#endif