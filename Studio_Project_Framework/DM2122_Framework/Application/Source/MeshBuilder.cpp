#include "MeshBuilder.h"
#include <GL\glew.h>
#include <vector>
#include "MyMath.h"
/******************************************************************************/
/*!
\brief
Generate the vertices of a reference Axes; Use red for x-axis, green for y-axis, blue for z-axis
Then generate the VBO/IBO and store them in Mesh object

\param meshName - name of mesh
\param lengthX - x-axis should start at -lengthX / 2 and end at lengthX / 2
\param lengthY - y-axis should start at -lengthY / 2 and end at lengthY / 2
\param lengthZ - z-axis should start at -lengthZ / 2 and end at lengthZ / 2

\return Pointer to mesh storing VBO/IBO of reference axes
*/
/******************************************************************************/
Mesh* MeshBuilder::GenerateAxes(const std::string &meshName, Vector3 lengthX, Vector3 lengthY, Vector3 lengthZ)
{
	std::vector<Vertex> vertex_buffer_data;
	std::vector<GLuint> index_buffer_data;
	Vertex v;

	v.pos.Set(0, 0, 0);	v.color.Set(1, 0, 0);	vertex_buffer_data.push_back(v);
	v.pos.Set(lengthX.x, lengthX.y, lengthX.z);	v.color.Set(1, 0, 0);	vertex_buffer_data.push_back(v);
	v.pos.Set(0, 0, 0);	v.color.Set(0, 1, 0);	vertex_buffer_data.push_back(v);
	v.pos.Set(lengthY.x, lengthY.y, lengthY.z);	v.color.Set(0, 1, 0);	vertex_buffer_data.push_back(v);
	v.pos.Set(0, 0, 0);	v.color.Set(0, 0, 1);	vertex_buffer_data.push_back(v);
	v.pos.Set(lengthZ.x, lengthZ.y, lengthZ.z);	v.color.Set(0, 0, 1);	vertex_buffer_data.push_back(v);

	index_buffer_data.push_back(0);
	index_buffer_data.push_back(1);
	index_buffer_data.push_back(2);
	index_buffer_data.push_back(3);
	index_buffer_data.push_back(4);
	index_buffer_data.push_back(5);

	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);

	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_LINES;

	return mesh;
}

/******************************************************************************/
/*!
\brief
Generate the vertices of a quad; Use random color for each vertex
Then generate the VBO/IBO and store them in Mesh object

\param meshName - name of mesh
\param lengthX - width of quad
\param lengthY - height of quad

\return Pointer to mesh storing VBO/IBO of quad
*/
/******************************************************************************/
Mesh* MeshBuilder::GenerateQuad(const std::string &meshName, Color color, float lengthX, float lengthY)
{
	/*const GLfloat vertex_buffer_data[] = {
		0
	};
	const GLfloat color_buffer_data[] = {
		0
	};
	const GLuint index_buffer_data[] = {
		0
	};*/

	std::vector<Vertex> vertex_buffer_data;
	std::vector<GLuint> index_buffer_data;
	Vertex v;

	v.pos.Set(-0.5f, -0.5f, 0.5f);	v.color = color; v.normal.Set(0.f, 0.5f, 0.f); v.texCoord.Set(0, 1); vertex_buffer_data.push_back(v);
	v.pos.Set(0.5f, -0.5f, 0.5f);	v.color = color; v.normal.Set(0.f, 0.5f, 0.f); v.texCoord.Set(0, 0); vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5f, -0.5f, -0.5f);	v.color = color; v.normal.Set(0.f, 0.5f, 0.f); v.texCoord.Set(1, 1); vertex_buffer_data.push_back(v);

	v.pos.Set(-0.5f, -0.5f, -0.5f);	v.color = color; v.normal.Set(0.f, 0.5f, 0.f); v.texCoord.Set(1, 1); vertex_buffer_data.push_back(v);
	v.pos.Set(0.5f, -0.5f, 0.5f);	v.color = color; v.normal.Set(0.f, 0.5f, 0.f); v.texCoord.Set(0, 0); vertex_buffer_data.push_back(v);
	v.pos.Set(0.5f, -0.5f, -0.5f);	v.color = color; v.normal.Set(0.f, 0.5f, 0.f); v.texCoord.Set(1, 0); vertex_buffer_data.push_back(v);

	for (unsigned i = 0; i < 6; ++i)
	{
		index_buffer_data.push_back(i);
	}

	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);

	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLES;

	return mesh;
}

/******************************************************************************/
/*!
\brief
Generate the vertices of a cube; Use random color for each vertex
Then generate the VBO/IBO and store them in Mesh object

\param meshName - name of mesh
\param lengthX - width of cube
\param lengthY - height of cube
\param lengthZ - depth of cube

\return Pointer to mesh storing VBO/IBO of cube
*/
/******************************************************************************/
Mesh* MeshBuilder::GenerateCube(const std::string &meshName, Color color)
{
	std::vector<Vertex> vertex_buffer_data;
	std::vector<GLuint> index_buffer_data;
	Vertex v;

	v.pos.Set(-0.5f, -0.5f, -0.5f);	v.color = color; v.normal.Set(-0.5f, 0.f, 0.f); vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5f, -0.5f, 0.5f);	v.color = color; v.normal.Set(-0.5f, 0.f, 0.f); vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5f, 0.5f, 0.5f);	v.color = color; v.normal.Set(-0.5f, 0.f, 0.f); vertex_buffer_data.push_back(v);
	v.pos.Set(0.5f, 0.5f, -0.5f);	v.color = color; v.normal.Set(0.f, 0.f, -0.5f); vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5f, -0.5f, -0.5f);	v.color = color; v.normal.Set(0.f, 0.f, -0.5f); vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5f, 0.5f, -0.5f);	v.color = color; v.normal.Set(0.f, 0.f, -0.5f); vertex_buffer_data.push_back(v);

	v.pos.Set(0.5f, -0.5f, 0.5f);	v.color = color; v.normal.Set(0.f, -0.5f, 0.f);	vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5f, -0.5f, -0.5f);	v.color = color; v.normal.Set(0.f, -0.5f, 0.f);	vertex_buffer_data.push_back(v);
	v.pos.Set(0.5f, -0.5f, -0.5f);	v.color = color; v.normal.Set(0.f, -0.5f, 0.f);	vertex_buffer_data.push_back(v);
	v.pos.Set(0.5f, 0.5f, -0.5f);	v.color = color; v.normal.Set(0.f, 0.f, -0.5f);	vertex_buffer_data.push_back(v);
	v.pos.Set(0.5f, -0.5f, -0.5f);	v.color = color; v.normal.Set(0.f, 0.f, -0.5f);	vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5f, -0.5f, -0.5f);	v.color = color; v.normal.Set(0.f, 0.f, -0.5f);	vertex_buffer_data.push_back(v);

	v.pos.Set(-0.5f, -0.5f, -0.5f);	v.color = color; v.normal.Set(-0.5f, 0.f, 0.f);	vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5f, 0.5f, 0.5f);	v.color = color; v.normal.Set(-0.5f, 0.f, 0.f);	vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5f, 0.5f, -0.5f);	v.color = color; v.normal.Set(-0.5f, 0.f, 0.f);	vertex_buffer_data.push_back(v);
	v.pos.Set(0.5f, -0.5f, 0.5f);	v.color = color; v.normal.Set(0.f, -0.5f, 0.f);	vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5f, -0.5f, 0.5f);	v.color = color; v.normal.Set(0.f, -0.5f, 0.f);	vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5f, -0.5f, -0.5f);	v.color = color; v.normal.Set(0.f, -0.5f, 0.f);	vertex_buffer_data.push_back(v);

	v.pos.Set(-0.5f, 0.5f, 0.5f);	v.color = color; v.normal.Set(0.f, 0.f, 0.5f);	vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5f, -0.5f, 0.5f);	v.color = color; v.normal.Set(0.f, 0.f, 0.5f);	vertex_buffer_data.push_back(v);
	v.pos.Set(0.5f, -0.5f, 0.5f);	v.color = color; v.normal.Set(0.f, 0.f, 0.5f);	vertex_buffer_data.push_back(v);
	v.pos.Set(0.5f, 0.5f, 0.5f);	v.color = color; v.normal.Set(0.5f, 0.f, 0.f);	vertex_buffer_data.push_back(v);
	v.pos.Set(0.5f, -0.5f, -0.5f);	v.color = color; v.normal.Set(0.5f, 0.f, 0.f);	vertex_buffer_data.push_back(v);
	v.pos.Set(0.5f, 0.5f, -0.5f);	v.color = color; v.normal.Set(0.5f, 0.f, 0.f);	vertex_buffer_data.push_back(v);

	v.pos.Set(0.5f, -0.5f, -0.5f);	v.color = color; v.normal.Set(0.5f, 0.f, 0.f);	vertex_buffer_data.push_back(v);
	v.pos.Set(0.5f, 0.5f, 0.5f);	v.color = color; v.normal.Set(0.5f, 0.f, 0.f);	vertex_buffer_data.push_back(v);
	v.pos.Set(0.5f, -0.5f, 0.5f);	v.color = color; v.normal.Set(0.5f, 0.f, 0.f);	vertex_buffer_data.push_back(v);
	v.pos.Set(0.5f, 0.5f, 0.5f);	v.color = color; v.normal.Set(0.f, 0.5f, 0.f);	vertex_buffer_data.push_back(v);
	v.pos.Set(0.5f, 0.5f, -0.5f);	v.color = color; v.normal.Set(0.f, 0.5f, 0.f);	vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5f, 0.5f, -0.5f);	v.color = color; v.normal.Set(0.f, 0.5f, 0.f);	vertex_buffer_data.push_back(v);

	v.pos.Set(0.5f, 0.5f, 0.5f);	v.color = color; v.normal.Set(0.f, 0.5f, 0.f);	vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5f, 0.5f, -0.5f);	v.color = color; v.normal.Set(0.f, 0.5f, 0.f);	vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5f, 0.5f, 0.5f);	v.color = color; v.normal.Set(0.f, 0.5f, 0.f);	vertex_buffer_data.push_back(v);
	v.pos.Set(0.5f, 0.5f, 0.5f);	v.color = color; v.normal.Set(0.f, 0.f, 0.5f);	vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5f, 0.5f, 0.5f);	v.color = color; v.normal.Set(0.f, 0.f, 0.5f);	vertex_buffer_data.push_back(v);
	v.pos.Set(0.5f, -0.5f, 0.5f);	v.color = color; v.normal.Set(0.f, 0.f, 0.5f);	vertex_buffer_data.push_back(v);

	for (unsigned i = 0; i < 36; ++i)
	{
		index_buffer_data.push_back(i);
	}

	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);

	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLES;

	return mesh;
}
//----------------------------------------------------------------------------------------------------------------
Mesh* MeshBuilder::GenerateCircle(const std::string &meshName, Color color, unsigned numSlices, float radius)
{

	Vertex v;
	std::vector<Vertex> vertex_buffer_data;
	std::vector<unsigned> index_buffer_data;

	v.pos.Set(0, 0, 0);
	v.color = color;
	vertex_buffer_data.push_back(v);

	float anglePerSlice = 360.f / numSlices;
	for (unsigned slice = 0; slice <= numSlices; slice++)
	{
		float theta = slice * anglePerSlice;
	
		v.pos.Set(radius * cos(Math::DegreeToRadian(theta)), 0, radius * sin(Math::DegreeToRadian(theta)));
		v.color = color;
		v.normal.Set(0, 1, 0);
		vertex_buffer_data.push_back(v);
	}

	for (unsigned i = 0; i < (numSlices + 1); ++i)
	{
		index_buffer_data.push_back(i);
		index_buffer_data.push_back(numSlices + 1);
	}
		

	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);

	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLE_STRIP;

	return mesh;
}
//----------------------------------------------------------------------------------------------------------------------------
Mesh* MeshBuilder::GenerateRing(const std::string &meshName, Color color, unsigned numSlices, float outerRadius, float innerRadius)
{

	Vertex v;
	std::vector<Vertex> vertex_buffer_data;
	std::vector<unsigned> index_buffer_data;

	float anglePerSlice = 360.f / numSlices;
	for (unsigned slice = 0; slice <= numSlices; slice++)
	{
		float theta = slice * anglePerSlice;

		v.pos.Set(outerRadius * cos(Math::DegreeToRadian(theta)), 0, outerRadius * sin(Math::DegreeToRadian(theta)));
		v.color = color;
		vertex_buffer_data.push_back(v);

		v.pos.Set(innerRadius * cos(Math::DegreeToRadian(theta)), 0, innerRadius * sin(Math::DegreeToRadian(theta)));
		v.color = color;
		vertex_buffer_data.push_back(v);


	}

	for (unsigned i = 0; i < (numSlices + 1) * 2; ++i)
		index_buffer_data.push_back(i);

	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);

	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLE_STRIP;

	return mesh;
}

//---------------------------------------------------------------------------------------------------------------------------

Mesh* MeshBuilder::GenerateHemiSphere(const std::string &meshName, Color color, unsigned numSlices, float radius)
{

	Vertex v;
	std::vector<Vertex> vertex_buffer_data;
	std::vector<unsigned> index_buffer_data;

	float anglePerSlice = 360.f / numSlices;
	for (float phi = 0; phi < 90; phi += 10)
	{
		for (unsigned slice = 0; slice <= numSlices; slice++)
		{
			float theta = slice * anglePerSlice;

			v.pos.Set(radius * cos(Math::DegreeToRadian(phi)) * cos(Math::DegreeToRadian(theta)),
				radius * sin(Math::DegreeToRadian(phi)), radius * cos(Math::DegreeToRadian(phi)) * sin(Math::DegreeToRadian(theta)));
			v.color = color;
			v.normal.Set(cos(Math::DegreeToRadian(phi)) * cos(Math::DegreeToRadian(theta)), sin(Math::DegreeToRadian(phi)),
				cos(Math::DegreeToRadian(phi)) * sin(Math::DegreeToRadian(theta)));
			vertex_buffer_data.push_back(v);

			v.pos.Set(radius * cos(Math::DegreeToRadian(phi + 10)) * cos(Math::DegreeToRadian(theta)),
				radius * sin(Math::DegreeToRadian(phi + 10)), radius * cos(Math::DegreeToRadian(phi + 10)) * sin(Math::DegreeToRadian(theta)));
			v.color = color;
			v.normal.Set(cos(Math::DegreeToRadian(phi + 10)) * cos(Math::DegreeToRadian(theta)), sin(Math::DegreeToRadian(phi + 10)),
				cos(Math::DegreeToRadian(phi + 10)) * sin(Math::DegreeToRadian(theta)));
			vertex_buffer_data.push_back(v);
		}
	}

	for (unsigned slice = 0; slice <= numSlices; slice++)
	{
		float theta = slice * anglePerSlice;


		v.pos.Set(0, 0, 0);
		v.color = color;
		vertex_buffer_data.push_back(v);

		v.pos.Set(radius * cos(Math::DegreeToRadian(theta)), 0, radius * sin(Math::DegreeToRadian(theta)));
		v.color = color;
		v.normal.Set(0, 1, 0);
		vertex_buffer_data.push_back(v);

	}

	for (unsigned i = 0; i < (numSlices + 1) * 36; ++i)
	{
		index_buffer_data.push_back(i);
	}
		
	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);

	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLE_STRIP;

	return mesh;
}

//-----------------------------------------------------------------------------------------------------------------------

Mesh* MeshBuilder::GenerateSphere(const std::string &meshName, Color color, unsigned numSlices, unsigned numStacks, float radius)
{

	Vertex v;
	std::vector<Vertex> vertex_buffer_data;
	std::vector<unsigned> index_buffer_data;

	float anglePerSlice = 360.f / numSlices;
	float anglePerStack = 180.f / numStacks;

	for (unsigned stack = 0; stack < numStacks + 1; ++stack)
	{
		for (unsigned slice = 0; slice < numSlices + 1; ++slice)
		{
			float theta = slice * anglePerSlice;

			float phi = -90.f + stack * anglePerSlice;
			v.pos.Set(radius * cos(Math::DegreeToRadian(phi)) * cos(Math::DegreeToRadian(theta)),
				radius * sin(Math::DegreeToRadian(phi)), radius * cos(Math::DegreeToRadian(phi)) * sin(Math::DegreeToRadian(theta)));
			v.color = color;
			v.normal.Set(cos(Math::DegreeToRadian(phi)) * cos(Math::DegreeToRadian(theta)), sin(Math::DegreeToRadian(phi)),
				cos(Math::DegreeToRadian(phi)) * sin(Math::DegreeToRadian(theta)));
			vertex_buffer_data.push_back(v);
		}
	}

	for (unsigned stack = 0; stack < numStacks; ++stack)
	{
		for (unsigned slice = 0; slice < numSlices + 1; ++slice)
		{
			index_buffer_data.push_back(stack * (numSlices + 1) + slice);
			index_buffer_data.push_back((stack + 1) * (numSlices + 1) + slice);
		}
	}

	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);

	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLE_STRIP;

	return mesh;
}

Mesh* MeshBuilder::GenerateCylinder(const std::string &meshName, Color color, unsigned numSlices,
	float radius, float height) //optimise for later
{
	Vertex v;
	std::vector<Vertex> vertex_buffer_data;
	std::vector<unsigned> index_buffer_data;

	float anglePerSlice = 360.f / numSlices;
	//bottom
	for (unsigned slice = 0; slice <= numSlices; slice++)
	{
		float theta = slice * anglePerSlice;

		v.pos.Set(radius * cos(Math::DegreeToRadian(theta)), -height * 0.5f, radius * sin(Math::DegreeToRadian(theta)));
		v.color = color;
		v.normal.Set(0, -1, 0);
		vertex_buffer_data.push_back(v);
	}

	v.pos.Set(0, -height * 0.5f, 0);
	v.color = color;
	v.normal.Set(0, -1, 0);
	vertex_buffer_data.push_back(v);

	//curve side
	for (unsigned slice = 0; slice <= numSlices; slice++)
	{
		float theta = slice * anglePerSlice;

		v.pos.Set(radius * cos(Math::DegreeToRadian(theta)), height * 0.5f, radius * sin(Math::DegreeToRadian(theta)));
		v.color = color;
		v.normal.Set(cos(Math::DegreeToRadian(theta)), 0, sin(Math::DegreeToRadian(theta)));
		vertex_buffer_data.push_back(v);

		v.pos.Set(cos(Math::DegreeToRadian(theta)), -height * 0.5f, sin(Math::DegreeToRadian(theta)));
		v.color = color;
		v.normal.Set(cos(Math::DegreeToRadian(theta)), 0, sin(Math::DegreeToRadian(theta)));
		vertex_buffer_data.push_back(v);
	}
	//top
	for (unsigned slice = 0; slice <= numSlices; slice++)
	{
		float theta = slice * anglePerSlice;

		v.pos.Set(radius * cos(Math::DegreeToRadian(theta)), height * 0.5f, radius * sin(Math::DegreeToRadian(theta)));
		v.color = color;
		v.normal.Set(0, 1, 0);
		vertex_buffer_data.push_back(v);
	}

	v.pos.Set(0, height * 0.5f, 0);
	v.color = color;
	v.normal.Set(0, 1, 0);
	vertex_buffer_data.push_back(v);

	for (unsigned i = 0; i < (numSlices + 1); ++i)
	{
		index_buffer_data.push_back(numSlices + 1);
		index_buffer_data.push_back(i);
	}

	for (unsigned i = 0; i < (numSlices + 1); ++i)
	{
		index_buffer_data.push_back(numSlices + 2 + i * 2 + 1);
		index_buffer_data.push_back(numSlices + 2 + i * 2);
	}

	for (unsigned i = 0; i < (numSlices + 1); ++i)
	{
		index_buffer_data.push_back(numSlices + 2 + (numSlices + 1) * 2 + i);
		index_buffer_data.push_back(numSlices + 2 + (numSlices + 1) * 2 + numSlices + 1);
	}

	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);

	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLE_STRIP;

	return mesh;
	
}

Mesh* MeshBuilder::GenerateOBJ(const std::string &meshName, const std::string
	&file_path) {
	//Read vertices, texcoords & normals from OBJ
	std::vector<Position> vertices;
	std::vector<TexCoord> uvs;
	std::vector<Vector3> normals;
	bool success = LoadOBJ(file_path.c_str(), vertices, uvs, normals);
	if (!success)
		return NULL;

	//Index the vertices, texcoords & normals properly
	std::vector<Vertex> vertex_buffer_data;
	std::vector<GLuint> index_buffer_data;
	IndexVBO(vertices, uvs, normals, index_buffer_data, vertex_buffer_data);
	//Create the mesh and call glBindBuffer, glBufferData
	//Use triangle list and remember to set index size

	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);

	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLES;

	return mesh;

}

Mesh* MeshBuilder::GenerateText(const std::string &meshName, unsigned numRow, unsigned numCol)
{
	Vertex v;
	std::vector<Vertex> vertex_buffer_data;
	std::vector<unsigned> index_buffer_data;

	float width = 1.f / numCol;
	float height = 1.f / numRow;
	for (unsigned i = 0; i < numRow; ++i)
	{
		for (unsigned j = 0; j < numCol; ++j)
		{
			//Task: Add 4 vertices into vertex_buffer_data
			v.pos.Set(-0.5, 0.5, 0); v.normal.Set(0, 0, 1); v.texCoord.Set(j * 0.0625f, (numRow - i ) * 0.0625f); vertex_buffer_data.push_back(v);//01
			v.pos.Set(-0.5, -0.5, 0); v.normal.Set(0, 0, 1); v.texCoord.Set(j * 0.0625f, (numRow - i - 1) * 0.0625f); vertex_buffer_data.push_back(v);//00 
			v.pos.Set(0.5, -0.5, 0); v.normal.Set(0, 0, 1); v.texCoord.Set((j + 1) * 0.0625f, (numRow - i - 1) * 0.0625f); vertex_buffer_data.push_back(v);//10
			v.pos.Set(0.5, 0.5, 0); v.normal.Set(0, 0, 1); v.texCoord.Set((j + 1) * 0.0625f, (numRow - i ) * 0.0625f); vertex_buffer_data.push_back(v);//11

			//Task: Add 6 indices into index_buffer_data
			index_buffer_data.push_back((i * numCol + j) * 4 + 0);
			index_buffer_data.push_back((i * numCol + j) * 4 + 1);
			index_buffer_data.push_back((i * numCol + j) * 4 + 2);
			index_buffer_data.push_back((i * numCol + j) * 4 + 2);
			index_buffer_data.push_back((i * numCol + j) * 4 + 0);
			index_buffer_data.push_back((i * numCol + j) * 4 + 3);
		}
	}

	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);

	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLE_STRIP;

	return mesh;
}

Mesh* MeshBuilder::GenerateUI(const std::string &meshName, unsigned numRow, unsigned numCol)
{
	Vertex v;
	std::vector<Vertex> vertex_buffer_data;
	std::vector<unsigned> index_buffer_data;

	float width = 1.f / numCol;
	float height = 1.f / numRow;
	for (unsigned i = 0; i < numRow; ++i)
	{
		for (unsigned j = 0; j < numCol; ++j)
		{
			//Task: Add 4 vertices into vertex_buffer_data
			v.pos.Set(-0.5, 0.5, 0); v.normal.Set(0, 0, 1); v.texCoord.Set(0,1); vertex_buffer_data.push_back(v);//01
			v.pos.Set(-0.5, -0.5, 0); v.normal.Set(0, 0, 1); v.texCoord.Set(0,0); vertex_buffer_data.push_back(v);//00 
			v.pos.Set(0.5, -0.5, 0); v.normal.Set(0, 0, 1); v.texCoord.Set(1,0); vertex_buffer_data.push_back(v);//10
			v.pos.Set(0.5, 0.5, 0); v.normal.Set(0, 0, 1); v.texCoord.Set(1,1); vertex_buffer_data.push_back(v);//11

			//Task: Add 6 indices into index_buffer_data
			index_buffer_data.push_back((i * numCol + j) * 4 + 0);
			index_buffer_data.push_back((i * numCol + j) * 4 + 1);
			index_buffer_data.push_back((i * numCol + j) * 4 + 2);
			index_buffer_data.push_back((i * numCol + j) * 4 + 2);
			index_buffer_data.push_back((i * numCol + j) * 4 + 0);
			index_buffer_data.push_back((i * numCol + j) * 4 + 3);
		}
	}

	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);

	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLE_STRIP;

	return mesh;
}