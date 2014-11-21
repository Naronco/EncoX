// stdafx.h : Includedatei für Standardsystem-Includedateien
// oder häufig verwendete projektspezifische Includedateien,
// die nur in unregelmäßigen Abständen geändert werden.
//

#pragma once

#ifdef _WIN32

#	include "targetver.h"

#	define WIN32_LEAN_AND_MEAN
#	include <windows.h>

#	ifdef ENCODESKTOP_EXPORTS
#		define ENCODESKTOPAPI __declspec(dllexport)
#	else
#		define ENCODESKTOPAPI __declspec(dllimport)
#	endif

#else

#	define ENCODESKTOPAPI

#endif


// TODO: Hier auf zusätzliche Header, die das Programm erfordert, verweisen.
