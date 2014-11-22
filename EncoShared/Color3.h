#ifndef __ENCOSHARED_COLOR3_H__
#define __ENCOSHARED_COLOR3_H__

#pragma once

#include "stdafx.h"

namespace enco {
	template <typename T> struct Color3;

	typedef Color3<i8> Color3c;
	typedef Color3<i16> Color3s;
	typedef Color3<i32> Color3i;
	typedef Color3<i64> Color3l;

	typedef Color3<u8> Color3uc;
	typedef Color3<u16> Color3us;
	typedef Color3<u32> Color3ui;
	typedef Color3<u64> Color3ul;

	typedef Color3<f32> Color3f;
	typedef Color3<f64> Color3d;

	template <typename T> struct Color3 {
		union {
			struct {
				T r, g, b;
			};
			T rgb[3];
		};

		inline Color3(T _r = 0, T _g = 0, T _b = 0) : r(_r), g(_g), b(_b) {  }
		inline Color3(const Color3<T> &v) : r(v.r), g(v.g), b(v.b) {  }
	};

	template <typename T>
	inline Color3<T> operator + (const Color3<T> &v0, const Color3<T> &v1) {
		return Color3<T>(v0.r + v1.r, v0.y + v1.y, v0.z + v1.z);
	}

	template <typename T>
	inline Color3<T> operator - (const Color3<T> &v0, const Color3<T> &v1) {
		return Color3<T>(v0.r - v1.r, v0.y - v1.y, v0.z - v1.z);
	}

	template <typename T>
	inline Color3<T> operator * (const Color3<T> &v0, const Color3<T> &v1) {
		return Color3<T>(v0.r * v1.r, v0.y * v1.y, v0.z * v1.z);
	}

	template <typename T>
	inline Color3<T> operator / (const Color3<T> &v0, const Color3<T> &v1) {
		return Color3<T>(v0.r / v1.r, v0.y / v1.y, v0.z / v1.z);
	}

	template <typename T>
	inline Color3<T> &operator += (Color3<T> &v0, const Color3<T> &v1) {
		return v0 = Color3<T>(v0.r + v1.r, v0.y + v1.y, v0.z + v1.z);
	}

	template <typename T>
	inline Color3<T> &operator -= (Color3<T> &v0, const Color3<T> &v1) {
		return v0 = Color3<T>(v0.r - v1.r, v0.y - v1.y, v0.z - v1.z);
	}

	template <typename T>
	inline Color3<T> &operator *= (Color3<T> &v0, const Color3<T> &v1) {
		return v0 = Color3<T>(v0.r * v1.r, v0.g * v1.g, v0.b * v1.b);
	}

	template <typename T>
	inline Color3<T> &operator /= (Color3<T> &v0, const Color3<T> &v1) {
		return v0 = Color3<T>(v0.r / v1.r, v0.g / v1.g, v0.b / v1.b);
	}

	template <typename T>
	inline bool operator == (const Color3<T> &v0, const Color3<T> &v1) {
		return (v0.r == v1.r) && (v0.g == v1.g) && (v0.b == v1.b);
	}

	template <typename T>
	inline bool operator != (const Color3<T> &v0, const Color3<T> &v1) {
		return (v0.r != v1.r) || (v0.g != v1.g) || (v0.b != v1.b);
	}
}

#endif