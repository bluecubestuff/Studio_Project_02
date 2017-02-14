#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

#include "Vector3.h"

class StudioProject;

class GameObject //TODO
{
public:
	GameObject(StudioProject* scene, Vector3 pos, float size);
	virtual ~GameObject(){};

	virtual void interact() = 0;

	void render();

	Vector3 position;
	float scale;
	float rotatespeed = 0;

	StudioProject *myscene;
	unsigned type;

private:

};


#endif