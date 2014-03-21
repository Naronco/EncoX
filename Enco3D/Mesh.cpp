#include "Mesh.h"

map<string, MeshResource *> Mesh::s_loadedModels;

Mesh::Mesh()
{
}

Mesh::Mesh(Vertex *vertices, unsigned int vertexCount)
{
	unsigned int *indices = new unsigned int[vertexCount];
	for (unsigned int i = 0; i < vertexCount; i++)
	{
		indices[i] = i;
	}

	BuildBuffers(vertices, vertexCount, indices, vertexCount);
}

Mesh::Mesh(Vertex *vertices, unsigned int vertexCount, unsigned int *indices, unsigned int indexCount)
{
	BuildBuffers(vertices, vertexCount, indices, indexCount);
}

Mesh::Mesh(const string &filename)
{
	m_filename = filename;

	map<string, MeshResource *>::iterator it = s_loadedModels.find(filename);
	if (it != s_loadedModels.end())
	{
		m_resource = s_loadedModels.at(filename);
		m_resource->AddReference();
	}
	else
	{
		LoadMesh(filename);
		s_loadedModels.insert(pair<string, MeshResource *>(m_filename, m_resource));
	}
}

Mesh::~Mesh()
{
	if (m_resource->RemoveReference() && m_filename.size() > 0)
	{
		s_loadedModels.erase(m_filename);
	}
}

void Mesh::BuildBuffers(Vertex *vertices, unsigned int vertexCount, unsigned int *indices, unsigned int indexCount)
{
	m_resource = new MeshResource(vertexCount, indexCount);

	glBindBuffer(GL_ARRAY_BUFFER, m_resource->GetVBO());
	glBufferData(GL_ARRAY_BUFFER, m_resource->GetVertexCount() * sizeof(Vertex), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_resource->GetIBO());
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_resource->GetIndexCount() * sizeof(unsigned int), indices, GL_STATIC_DRAW);
}

void Mesh::LoadMesh(const string &filename)
{
	OBJModel objModel(filename);

	IndexedModel indexedModel = objModel.ToIndexedModel();
	//indexedModel.CalcNormals();

	Vertex *vertices = new Vertex[indexedModel.GetPositions().size()];

	for (unsigned int i = 0; i < indexedModel.GetPositions().size(); i++)
	{
		vertices[i].SetPosition(indexedModel.GetPositions()[i].x, indexedModel.GetPositions()[i].y, indexedModel.GetPositions()[i].z);
		vertices[i].SetTexCoord(indexedModel.GetTexCoords()[i].x, indexedModel.GetTexCoords()[i].y);
		vertices[i].SetNormal(indexedModel.GetNormals()[i].x, indexedModel.GetNormals()[i].y, indexedModel.GetNormals()[i].z);
	}

	unsigned int *indices = new unsigned int[indexedModel.GetIndices().size()];

	for (unsigned int i = 0; i < indexedModel.GetIndices().size(); i++)
	{
		indices[i] = indexedModel.GetIndices()[i];
	}

	BuildBuffers(vertices, indexedModel.GetPositions().size(), indices, indexedModel.GetIndices().size());

	if (vertices)
	{
		delete vertices;
		vertices = nullptr;
	}

	if (indices)
	{
		delete indices;
		indices = nullptr;
	}
}

void Mesh::Render()
{
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, m_resource->GetVBO());
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)(sizeof(float) * 3));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)(sizeof(float) * 5));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_resource->GetIBO());
	glDrawElements(GL_TRIANGLES, m_resource->GetIndexCount(), GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
}