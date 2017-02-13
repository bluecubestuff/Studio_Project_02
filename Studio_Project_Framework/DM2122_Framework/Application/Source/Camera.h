#ifndef _CAMERA_H
#define _CAMERA_H

#include "Vector3.h"
#include "DetectMemoryLeak.h"

class Camera
{
public:
	Vector3 position;
	Vector3 target;
	Vector3 up;

	int anchorX, anchorY;
	int WindowX, WindowY;

	Vector3 forward;
	Vector3 back;
	Vector3 playerLeft;
	Vector3 playerRight;

	Camera();
	~Camera();
	virtual void Init(const Vector3& pos, const Vector3& target, const Vector3& up);
	virtual void Reset();
	virtual void Update(double dt);
};

#endif