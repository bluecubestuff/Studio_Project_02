#ifndef _CAMERA_3_H
#define _CAMERA_3_H

#include "Camera.h"
#include "DetectMemoryLeak.h"

#include <windows.h>

class Camera3 : public Camera
{
public:
	Vector3 defaultPosition;
	Vector3 defaultTarget;
	Vector3 defaultUp;
	Vector3 right;

	float limitPitch;
	float yawRight, yawLeft;
	float limit;

	float timeCheck;

	POINT mp; //mousePos for scene area
	POINT curMousePos;

	Camera3();
	~Camera3();

	virtual void Init(const Vector3& pos, const Vector3& target, const Vector3& up);
	virtual void Update(double dt);
	virtual void Reset();

};

#endif