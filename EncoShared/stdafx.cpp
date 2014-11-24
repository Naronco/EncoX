#include "stdafx.h"
#include <codecvt>

namespace enco {

#ifdef _WIN32

	std::wstring_convert<std::codecvt_utf8<wchar_t>> g_utf8conv;

	ENCOSHAREDAPI std::string wstrToStr(const std::wstring &str) {
		return g_utf8conv.to_bytes(str);
	}

#else

	ENCOSHAREDAPI std::string wstrToStr(const std::wstring &str) {
		return std::string(str.begin(), str.end());
	}

#endif

}