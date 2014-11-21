#ifndef __ENCOSHARED_VECTOR2_H__
#define __ENCOSHARED_VECTOR2_H__

#pragma once

#include "stdafx.h"

namespace enco {
	template <typename T> struct Vector2;
	
	typedef Vector2<i8> Vector2c;
	typedef Vector2<i16> Vector2s;
	typedef Vector2<i32> Vector2i;
	typedef Vector2<i64> Vector2l;
	
	typedef Vector2<u8> Vector2uc;
	typedef Vector2<u16> Vector2us;
	typedef Vector2<u32> Vector2ui;
	typedef Vector2<u64> Vector2ul;
	
	typedef Vector2<f32> Vector2f;
	typedef Vector2<f64> Vector2d;

	template <typename T> struct Vector2 {
		union {
			struct {
				T x, y;
			};
			T xy[2];
		};

		inline Vector2(T _x = 0, T _y = 0) : x(_x), y(_y) {  }
		inline Vector2(const Vector2<T> &v) : x(v.x), y(v.y) {  }
	};

	template <typename T>
	inline Vector2<T> operator + (const Vector2<T> &v0, const Vector2<T> &v1) {
		return Vector2<T>(v0.x + v1.x, v0.y + v1.y);
	}

	template <typename T>
	inline Vector2<T> operator - (const Vector2<T> &v0, const Vector2<T> &v1) {
		return Vector2<T>(v0.x - v1.x, v0.y - v1.y);
	}
	
	template <typename T>
	inline Vector2<T> operator * (const Vector2<T> &v, const T s) {
		return Vector2<T>(v.x * s, v.y * s);
	}

	template <typename T>
	inline Vector2<T> operator * (const T s, const Vector2<T> &v) {
		return Vector2<T>(v.x * s, v.y * s);
	}

	template <typename T>
	inline Vector2<T> operator / (const Vector2<T> &v, const T s) {
		const T is = (T)(1.0 / s);
		return Vector2<T>(v.x * is, v.y * is);
	}
	
	template <typename T>
	inline Vector2<T> &operator += (Vector2<T> &v0, const Vector2<T> &v1) {
		return v0 = Vector2<T>(v0.x + v1.x, v0.y + v1.y);
	}
	
	template <typename T>
	inline Vector2<T> &operator -= (Vector2<T> &v0, const Vector2<T> &v1) {
		return v0 = Vector2<T>(v0.x - v1.x, v0.y - v1.y);
	}
	
	template <typename T>
	inline Vector2<T> &operator *= (Vector2<T> &v, const T s) {
		return v = Vector2<T>(v.x * s, v.y * s);
	}
	
	template <typename T>
	inline Vector2<T> &operator /= (Vector2<T> &v, const T s) {
		const T is = (T)(1.0 / s);
		return v = Vector2<T>(v.x * is, v.y * is);
	}

	template <typename T>
	inline bool operator == (const Vector2<T> &v0, const Vector2<T> &v1) {
		return (v0.x == v1.x) && (v0.y == v1.y);
	}

	template <typename T>
	inline bool operator != (const Vector2<T> &v0, const Vector2<T> &v1) {
		return (v0.x != v1.x) || (v0.y != v1.y);
	}
}

#endif

