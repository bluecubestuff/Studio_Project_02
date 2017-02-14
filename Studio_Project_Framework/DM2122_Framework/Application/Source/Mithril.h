#ifndef _MITHRIL_H
#define _MITHRIL_H

#include "StudioProject.h"
#include "Vector3.h"
#include "GameObject.h"
#include "Application.h"

#include <string>
using std::string;

class Mithril : public GameObject
{
public:
	Mithril(StudioProject* scene, Vector3 pos, float size);
	~Mithril(){};

	virtual void interact();
};
#endif