#ifndef _MATERIAL_H
#define _MATERIAL_H

#include "DetectMemoryLeak.h"

struct Component
{
	float r, g, b;
	Component(float r = 0.1f, float g = 0.1f, float b = 0.1f)
	{
		Set(r, g, b);
	}
	void Set(float r, float g, float b)
	{
		this->r = r; this->g = g; this->b = b;
	}
};

struct Material
{
	Component kAmbient;
	Component kDiffuse;
	Component kSpecular;
	float kShininess;
	//to do: add a constructor
	Material()
	{
		kAmbient.Set(0.2f, 0.2f, 0.2f);
		kDiffuse.Set(0.6f, 0.6f, 0.6f);
		kSpecular.Set(0.3f, 0.3f, 0.3f);
		kShininess = 1.f;
	}
};

#endif