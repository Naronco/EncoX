#include "ConvexMeshCollisionShape.h"

Enco3D::Physics::ConvexMeshCollisionShape::ConvexMeshCollisionShape()
{
}

Enco3D::Physics::ConvexMeshCollisionShape::ConvexMeshCollisionShape(Enco3D::Rendering::Mesh* mesh)
{
	m_mesh = mesh;
}

btCollisionShape *Enco3D::Physics::ConvexMeshCollisionShape::ToBulletPhysicsCollisionShape()
{
	btTriangleMesh *triangleMesh = new btTriangleMesh;
	for (unsigned int i = 0; i < m_mesh->GetIndexCount(); i += 3)
	{
		unsigned int index0 = m_mesh->GetIndices()[i + 0];
		unsigned int index1 = m_mesh->GetIndices()[i + 1];
		unsigned int index2 = m_mesh->GetIndices()[i + 2];

		btVector3 vertex0(m_mesh->GetVertices()[index0].x, m_mesh->GetVertices()[index0].y, m_mesh->GetVertices()[index0].z);
		btVector3 vertex1(m_mesh->GetVertices()[index1].x, m_mesh->GetVertices()[index1].y, m_mesh->GetVertices()[index1].z);
		btVector3 vertex2(m_mesh->GetVertices()[index2].x, m_mesh->GetVertices()[index2].y, m_mesh->GetVertices()[index2].z);

		triangleMesh->addTriangle(vertex0, vertex1, vertex2);
	}

	return new btConvexTriangleMeshShape(triangleMesh, true);
}