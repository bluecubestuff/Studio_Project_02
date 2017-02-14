#ifndef ObjectFactory_H
#define ObjectFactory_H

#include <vector>
#include "GameObject.h"

class StudioProject;

class ObjectFactory
{

public:
	ObjectFactory(StudioProject* scene);
	~ObjectFactory() {};

	void createObject(GameObject* obj);
	void interactObjects();
	void renderObjects();

	std::vector<GameObject*> objContainer;

private:
	StudioProject* myscene;


};
#endif