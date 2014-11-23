#ifndef __ENCOSHARED_VERTEXDECLARATION_H__
#define __ENCOSHARED_VERTEXDECLARATION_H__

#pragma once

#include "stdafx.h"

#include <vector>

namespace enco {
	struct VertexElement {
		VertexElement(i32 offset, VertexElementFormat format, VertexElementUsage usage, i32 usageIndex) : offset(offset), format(format), usage(usage), usageIndex(usageIndex) { }

		i32 offset, usageIndex;
		VertexElementFormat format;
		VertexElementUsage usage;
	};

	class VertexDeclaration {
	public:
		VertexDeclaration(std::vector<VertexElement> elems) : m_elements(elems) {}
		VertexDeclaration() : VertexDeclaration(std::vector<VertexElement>()) {}
		~VertexDeclaration() { m_elements.clear(); }

		inline void addElement(VertexElement element) { m_elements.push_back(element); }
		inline std::vector<VertexElement> getElements() { return m_elements; }

	private:
		std::vector<VertexElement> m_elements;
	};

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

	enum VertexElementUsage {
		position // TODO: textureCoordinate, normal, color, etc.
	};

	class IVertexType {
	public:
		virtual const VertexDeclaration &getVertexDeclaration() = 0;
	};
}

#endif