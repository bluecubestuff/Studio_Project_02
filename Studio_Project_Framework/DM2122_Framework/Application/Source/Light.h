#ifndef LIGHT_H
#define LIGHT_H

#include "MeshBuilder.h"
#include "DetectMemoryLeak.h"

struct Light
{
	Position LightPosition;
	Color color;
	float power;
	float kC, kL, kQ;

	enum LIGHT_TYPE
	{
		LIGHT_POINT = 0,
		LIGHT_DIRECTIONAL,
		LIGHT_SPOT,
	};

	LIGHT_TYPE type;
	Vector3 spotDirection;
	float cosCutoff;
	float cosInner;
	float exponent;

	//to do: add a constructor
	Light() {}
};

#endif