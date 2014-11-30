#ifndef __ENCOSHARED_MESH_H__
#define __ENCOSHARED_MESH_H__

#pragma once

#include "stdafx.h"
#include "VertexDeclaration.h"

#include <memory>

namespace enco {
	typedef i32 RenderableMesh;

	class Mesh {
	public:
		Mesh() { }
		~Mesh() { }

		inline void addIndex(u32 index) { m_indices.push_back(index); }
		inline void addIndices(u32* indices, u32 count) { m_indices.insert(m_indices.end(), &indices[0], &indices[count]); }

		inline void addVertex(glm::vec3 vertex) { m_vertices.push_back(vertex); }
		inline void addVertices(glm::vec3* vertices, u32 count) { m_vertices.assign(vertices, vertices + count); }

	protected:
		VertexDeclaration* m_declaration;

		std::vector<u32> m_indices;

		// Lists for all enco::VertexElementUsage members
		std::vector<glm::vec3> m_vertices;
	};
}

#endif