#ifndef __ENCOSHARED_VERTEXDECLARATION_H__
#define __ENCOSHARED_VERTEXDECLARATION_H__

#pragma once

#include "stdafx.h"

#include <vector>

namespace enco {
	struct VertexElement;
	class VertexDeclaration;
	enum VertexElementFormat;
	enum VertexElementUsage;

	enum VertexElementFormat {
		vec1,
		vec2,
		vec3,
		vec4,
		normalizedVec1,
		normalizedVec2,
		normalizedVec3,
		normalizedVec4,
		/// <summary>Four-component packed int32 (ARGB)</summary>
		color
	};

	const int32 g_vertexElementFormatSizes[] = {
		sizeof(float) * 1, // vec1
		sizeof(float) * 2, // vec2
		sizeof(float) * 3, // vec3
		sizeof(float) * 4, // vec4
		sizeof(float) * 1, // normalizedVec1
		sizeof(float) * 2, // normalizedVec2
		sizeof(float) * 3, // normalizedVec3
		sizeof(float) * 4, // normalizedVec4
		sizeof(int32),     // color
	};

	struct VertexElement {
		VertexElement(i32 offset, VertexElementFormat format, VertexElementUsage usage, i32 usageIndex) : offset(offset), format(format), usage(usage), usageIndex(usageIndex) { }

		i32 offset, usageIndex;
		VertexElementFormat format;
		VertexElementUsage usage;
	};

	class VertexDeclaration {
	public:
		VertexDeclaration(std::vector<VertexElement> elems) : m_elements(elems) { calculateSize(); }
		VertexDeclaration() : VertexDeclaration(std::vector<VertexElement>()) {  }
		~VertexDeclaration() { m_elements.clear(); }

		inline void addElement(VertexElement element) { m_elements.push_back(element); m_size += g_vertexElementFormatSizes[element.format]; }
		inline std::vector<VertexElement> getElements() { return m_elements; }

		inline int32 getSize() const { return m_size; }

	private:
		std::vector<VertexElement> m_elements;
		mutable int32 m_size;

		inline void calculateSize() {
			m_size = 0;
			for (auto element : m_elements) {
				m_size += g_vertexElementFormatSizes[element.format];
			}
		}
	};

	enum VertexElementUsage {
		position // TODO: textureCoordinate, normal, color, etc.
	};

	class IVertexType {
	public:
		virtual const VertexDeclaration &getVertexDeclaration() = 0;
	};
}

#endif