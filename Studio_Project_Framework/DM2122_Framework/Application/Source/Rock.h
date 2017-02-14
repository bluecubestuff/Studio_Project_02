#ifndef _ROCK_H
#define _ROCK_H

#include "StudioProject.h"
#include "Vector3.h"
#include "GameObject.h"
#include "Application.h"

#include <string>
using std::string;

class Rock : public GameObject
{
public:
	Rock(StudioProject* scene, Vector3 pos, float size);
	~Rock(){};

	virtual void interact();
};

#endif
