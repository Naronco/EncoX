#pragma once

#ifdef _WIN32
#	include "targetver.h"

#	define WIN32_LEAN_AND_MEAN
#	include <windows.h>

#	include <glm\glm.hpp>

#	ifdef ENCOSHARED_EXPORTS
#		define ENCOSHAREDAPI __declspec(dllexport)
#	else
#		define ENCOSHAREDAPI __declspec(dllimport)
#	endif
#else
#	define ENCOSHAREDAPI

#   include <glm/glm.hpp>
#endif

#include <codecvt>

namespace enco {
	typedef char int8, i8;
	typedef short int16, i16;
	typedef int int32, i32;
	typedef long long int64, i64;

	typedef unsigned char uchar, uint8, u8;
	typedef unsigned short ushort, uint16, u16;
	typedef unsigned int uint, uint32, u32;
	typedef unsigned long long ulong, uint64, u64;

	typedef float f32, float32;
	typedef double f64, float64;
	
	ENCOSHAREDAPI extern std::string wstrToStr(const std::wstring &str);
}
