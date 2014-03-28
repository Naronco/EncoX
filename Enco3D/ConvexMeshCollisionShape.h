#ifndef _ENCO3D_CONVEXMESHCOLLISIONSHAPE_H_
#define _ENCO3D_CONVEXMESHCOLLISIONSHAPE_H_

#include "ICollisionShape.h"
#include "Vector3.h"
#include "PhysicsHelper.h"
#include "Mesh.h"

#include <vector>

using namespace std;

namespace Enco3D
{
	namespace Physics
	{
		using namespace Core;
		using namespace Rendering;

		class ConvexMeshCollisionShape : public ICollisionShape
		{
		private:
			Mesh *m_mesh{ nullptr };

		public:
			ConvexMeshCollisionShape();
			ConvexMeshCollisionShape(Mesh *mesh);

			btCollisionShape *ToBulletPhysicsCollisionShape();

			inline void SetMesh(Mesh *mesh) { m_mesh = mesh; }
			inline Mesh *GetMesh() const { return m_mesh; }
		};
	}
}

#endif