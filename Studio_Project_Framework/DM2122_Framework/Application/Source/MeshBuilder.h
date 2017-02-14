#ifndef MESH_BUILDER_H
#define MESH_BUILDER_H

#include "Mesh.h"
#include "Vertex.h"
#include "LoadOBJ.h"
#include "DetectMemoryLeak.h"
/******************************************************************************/
/*!
		Class MeshBuilder:
\brief	Provides methods to generate mesh of different shapes
*/
/******************************************************************************/
class MeshBuilder
{
public:
	static Mesh* GenerateAxes(const std::string &meshName, Vector3 lengthX, Vector3 lengthY, Vector3 lengthZ);
	static Mesh* GenerateQuad(const std::string &meshName, Color color, float lengthX, float lengthY);
	static Mesh* GenerateCube(const std::string &meshName, Color color);
	static Mesh* GenerateCircle(const std::string &meshName,Color color, unsigned numSlices = 10, float radius = 1.f);
	static Mesh* GenerateRing(const std::string &meshName, Color color, unsigned numSlices = 10,
		float outerRadius = 1.f, float innerRadius = 0.5f);
	static Mesh* GenerateHemiSphere(const std::string &meshName, Color color, unsigned numSlices = 10, float radius = 1.f);
	static Mesh* GenerateSphere(const std::string &meshName, Color color, unsigned numSlices = 10, 
		unsigned numStacks = 10, float radius = 1.f);
	static Mesh* GenerateCylinder(const std::string &meshName, Color color, unsigned numSlices = 10,
		float radius = 1.f, float height = 3.f);
	static Mesh* GenerateOBJ(const std::string &meshName, const std::string &file_path);
	static Mesh* GenerateText(const std::string &meshName, unsigned numRow, unsigned numCol);
	static Mesh*GenerateUI(const std::string &meshName, unsigned numRow, unsigned numCol);
};

#endif