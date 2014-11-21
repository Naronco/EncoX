#ifndef __ENCOSHARED_VECTOR3_H__
#define __ENCOSHARED_VECTOR3_H__

#pragma once

#include "stdafx.h"

namespace enco {
	template <typename T> struct Vector3;
	
	typedef Vector3<i8> Vector3c;
	typedef Vector3<i16> Vector3s;
	typedef Vector3<i32> Vector3i;
	typedef Vector3<i64> Vector3l;
	
	typedef Vector3<u8> Vector3uc;
	typedef Vector3<u16> Vector3us;
	typedef Vector3<u32> Vector3ui;
	typedef Vector3<u64> Vector3ul;
	
	typedef Vector3<f32> Vector3f;
	typedef Vector3<f64> Vector3d;

	template <typename T> struct Vector3 {
		union {
			struct {
				T x, y, z;
			};
			T xyz[3];
		};

		inline Vector3(T _x = 0, T _y = 0, T _z = 0) : x(_x), y(_y), z(_z) {  }
		inline Vector3(const Vector3<T> &v) : x(v.x), y(v.y), z(v.z) {  }
	};

	template <typename T>
	inline Vector3<T> operator + (const Vector3<T> &v0, const Vector3<T> &v1) {
		return Vector3<T>(v0.x + v1.x, v0.y + v1.y, v0.z + v1.z);
	}

	template <typename T>
	inline Vector3<T> operator - (const Vector3<T> &v0, const Vector3<T> &v1) {
		return Vector3<T>(v0.x - v1.x, v0.y - v1.y, v0.z - v1.z);
	}
	
	template <typename T>
	inline Vector3<T> operator * (const Vector3<T> &v, const T s) {
		return Vector3<T>(v.x * s, v.y * s, v.z * s);
	}

	template <typename T>
	inline Vector3<T> operator * (const T s, const Vector3<T> &v) {
		return Vector3<T>(v.x * s, v.y * s, v.z * s);
	}

	template <typename T>
	inline Vector3<T> operator / (const Vector3<T> &v, const T s) {
		const T is = (T)(1.0 / s);
		return Vector3<T>(v.x * is, v.y * is, v.z * is);
	}
	
	template <typename T>
	inline Vector3<T> &operator += (Vector3<T> &v0, const Vector3<T> &v1) {
		return v0 = Vector3<T>(v0.x + v1.x, v0.y + v1.y, v0.z + v1.z);
	}
	
	template <typename T>
	inline Vector3<T> &operator -= (Vector3<T> &v0, const Vector3<T> &v1) {
		return v0 = Vector3<T>(v0.x - v1.x, v0.y - v1.y, v0.z - v1.z);
	}
	
	template <typename T>
	inline Vector3<T> &operator *= (Vector3<T> &v, const T s) {
		return v = Vector3<T>(v.x * s, v.y * s, v.z * s);
	}
	
	template <typename T>
	inline Vector3<T> &operator /= (Vector3<T> &v, const T s) {
		const T is = (T)(1.0 / s);
		return v = Vector3<T>(v.x * is, v.y * is, v.z * is);
	}

	template <typename T>
	inline bool operator == (const Vector3<T> &v0, const Vector3<T> &v1) {
		return (v0.x == v1.x) && (v0.y == v1.y) && (v0.z == v1.z);
	}

	template <typename T>
	inline bool operator != (const Vector3<T> &v0, const Vector3<T> &v1) {
		return (v0.x != v1.x) || (v0.y != v1.y) || (v0.z != v1.z);
	}
}

#endif

