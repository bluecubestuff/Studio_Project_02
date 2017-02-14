#include "ObjectFactory.h"

ObjectFactory::ObjectFactory(StudioProject* scene)
{
	myscene = scene;
}

void ObjectFactory::createObject(GameObject* obj)
{
	objContainer.push_back(obj);
}
void ObjectFactory::interactObjects()
{
	for (auto &a : objContainer)
	{
		a->interact();
	}
}
void ObjectFactory::renderObjects()
{
	for (auto &a : objContainer)
	{
		a->render();
	}
}