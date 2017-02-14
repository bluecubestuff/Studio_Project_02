#ifndef _TREE_H
#define _TREE_H

#include "StudioProject.h"
#include "Vector3.h"
#include "GameObject.h"
#include "Application.h"

#include <string>
using std::string;

class Tree : public GameObject
{
public:
	Tree(StudioProject* scene, Vector3 pos, float size);
	~Tree(){};

	virtual void interact();
};
#endif