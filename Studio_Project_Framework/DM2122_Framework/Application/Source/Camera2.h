#ifndef _CAMERA_2_H
#define _CAMERA_2_H

#include "Camera.h"
#include "MouseControl.h"
#include "DetectMemoryLeak.h"

#include <windows.h>

class Camera2 : public Camera
{
public:
	//Vector3 position;
	//Vector3 target;
	//Vector3 up;

	Vector3 defaultPosition;
	Vector3 defaultTarget;
	Vector3 defaultUp;

	Vector3 temp;
	Vector3 camRight;

	float pitchLimit;
	float yawLimit;

	Mouse* mouse;

	POINT curMousePos;

	Camera2();
	~Camera2();
	virtual void Init(const Vector3& pos, const Vector3& target, const Vector3& up);
	virtual void Update(double dt, bool freeCam, Vector3 f, Vector3 r, Vector3 u, Vector3 p);
	virtual void Reset();
};

#endif