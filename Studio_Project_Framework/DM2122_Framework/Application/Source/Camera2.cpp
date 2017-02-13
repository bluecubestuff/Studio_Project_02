#include "Camera2.h"
#include "Application.h"
#include "Mtx44.h"
#include "MatrixStack.h"
#include "DetectMemoryLeak.h"
//Include GLEW
#include <GL/glew.h>
//Include GLFW
#include <GLFW/glfw3.h>

#include <iostream>
using std::cout;
using std::endl;

//extern GLFWwindow* Application::m_window;

Camera2::Camera2()
{
	mouse = new Mouse;
}

Camera2::~Camera2()
{
	delete this;
}

void Camera2::Init(const Vector3& pos, const Vector3& target, const Vector3& up)
{
	this->position = defaultPosition = pos;
	this->target = defaultTarget = temp = target;
	this->up = defaultUp = up;

	camRight = target.Cross(up).Normalized();

	pitchLimit = 0.f;
	yawLimit = 0.f;

	curMousePos.x = 0;
	curMousePos.y = 0;
	SetCursorPos(mouse->anchorX, mouse->anchorY);
}

void Camera2::Update(double dt, bool freeCam, Vector3 f, Vector3 r, Vector3 u, Vector3 p)
{
	static const float CAMERA_SPEED = 5.f;
	position = p;
	target = position + temp;

	curMousePos = mouse->mouseMovement();

	if (freeCam)
	{
		if (curMousePos.x > 0 && yawLimit < 70.f)
		{
			float yawSpeed = curMousePos.x * (float)dt * CAMERA_SPEED;
			Mtx44 yaw;
			yaw.SetToRotation(-yawSpeed, u.x, u.y, u.z);
			temp = yaw * temp;
			up = yaw * up;
			camRight = yaw * camRight;
			yawLimit += yawSpeed;
		}
		else if (curMousePos.x < 0 && yawLimit > -70.f)
		{
			float yawSpeed = curMousePos.x * (float)dt * CAMERA_SPEED;
			Mtx44 yaw;
			yaw.SetToRotation(-yawSpeed, u.x, u.y, u.z);
			temp = yaw * temp;
			up = yaw * up;
			camRight = yaw * camRight;
			yawLimit += yawSpeed;
		}
		if (curMousePos.y > 0 && pitchLimit > -89.f)
		{
			float pitchSpeed = curMousePos.y * (float)dt * -CAMERA_SPEED;
			Mtx44 pitch;
			pitch.SetToRotation(pitchSpeed, camRight.x, camRight.y, camRight.z);
			temp = pitch * temp;
			up = pitch * up;
			pitchLimit += pitchSpeed;
		}
		else if (curMousePos.y < 0 && pitchLimit < 89.f)
		{
			float pitchSpeed = curMousePos.y * (float)dt * -CAMERA_SPEED;
			Mtx44 pitch;
			pitch.SetToRotation(pitchSpeed, camRight.x, camRight.y, camRight.z);
			temp = pitch * temp;
			up = pitch * up;
			pitchLimit += pitchSpeed;
		}
	}
	else
	{
		temp = f;
		up = u;
		camRight = r;
	}

	curMousePos.x = 0;
	curMousePos.y = 0;
}

void Camera2::Reset()
{
	position = defaultPosition;
	target = defaultTarget;
	up = defaultUp;
}

