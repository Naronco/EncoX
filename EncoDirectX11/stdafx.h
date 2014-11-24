#ifndef __ENCODIRECTX11_STDAFX_H__
#define __ENCODIRECTX11_STDAFX_H__

#pragma once

#ifdef _WIN32

#	define WIN32_LEAN_AND_MEAN
#	include <windows.h>
#	include <d3d11.h>

#	pragma comment (lib, "d3d11.lib")

#	ifdef ENCODIRECTX11_EXPORTS
#		define ENCODIRECTX11API __declspec(dllexport)
#	else
#		define ENCODIRECTX11API __declspec(dllimport)
#	endif
#else
#	define ENCODIRECTX11API
#endif

#endif