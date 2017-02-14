#include "GameObject.h"
#include "StudioProject.h"

GameObject::GameObject(StudioProject* scene, Vector3 pos, float size)
{
	myscene = scene;
	position = pos;
	scale = size;
}
void GameObject::render()
{
	myscene->modelStack.PushMatrix();
	myscene->modelStack.Translate(position.x, position.y, position.z);
	myscene->modelStack.Scale(scale, scale, scale);
	myscene->RenderMesh(myscene->meshList[type], true);
	myscene->modelStack.PopMatrix();
}