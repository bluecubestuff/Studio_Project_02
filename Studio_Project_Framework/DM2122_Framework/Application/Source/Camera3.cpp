#include "Camera3.h"
#include "Application.h"
#include "Mtx44.h"
#include "MatrixStack.h"
//Include GLEW
#include <GL/glew.h>
//Include GLFW
#include <GLFW/glfw3.h>

//debugging purposes
#include <iostream>
using std::cout;
using std::endl;

//extern GLFWwindow* m_window;
Camera3::Camera3()
{
}

Camera3::~Camera3()
{
}

void Camera3::Init(const Vector3& pos, const Vector3& target, const Vector3& up)
{
	this->position = defaultPosition = pos;
	this->target = defaultTarget = target;
	Vector3 view = (target - position).Normalized();
	right = view.Cross(up);
	right.y = 0;
	right.Normalize();
	this->up = defaultUp = right.Cross(view).Normalized();

	forward.Set(0, 0, -2);
	back.Set(0, 0, 1);
	playerLeft.Set(-1, 0, 0);
	playerRight.Set(1, 0, 0);

	GetCursorPos(&curMousePos);
	glfwGetWindowSize(Application::m_window, &WindowX, &WindowY);
	SetCursorPos(WindowX / 2, WindowY / 2);
}

void Camera3::Update(double dt)
{
	GetCursorPos(&curMousePos);
	static const float CAMERA_SPEED = 40.f;

	//for mouse pos in scene
	mp.x = curMousePos.x;
	mp.y = curMousePos.y;

	if (Application::IsKeyPressed('W')) //move forwards
	{
		Vector3 view;
		view = up.Cross(right);
		view.y = 0;
		view.Normalize();

		target = target + view;
		position = position + view;
	
		/*//free roam
		Vector3 view;
		view = (target - position).Normalized();
		target += position;
		position = position - forward;*/
	}

	if (Application::IsKeyPressed('S'))//move backwards
	{
		Vector3 view;
		view = up.Cross(right);
		view.y = 0;
		view.Normalize();

	
		target -= view;
		position = position - view;

		//free roam
		//Vector3 view;
		//view = (target - position).Normalized();
		//position = position + forward;
	}

	if (Application::IsKeyPressed('A'))//strafe left
	{
		Vector3 view;
		view = (target - position).Normalized();

		right = view.Cross(up);
		right.y = 0;
		right.Normalize();


		position = position - right;
		target = position + view;
		
	}

	if (Application::IsKeyPressed('D'))//strafe right
	{
		Vector3 view;
		view = (target - position).Normalized();

		right = view.Cross(up);
		right.y = 0;
		right.Normalize();

		
		position = position + right;
		target = position + view;
	}

	if (curMousePos.x < anchorX)//yaw left
	{
		Vector3 view;
		view = (target - position).Normalized();

		right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		up = right.Cross(view).Normalized();

		yawLeft = (float)((-CAMERA_SPEED * (curMousePos.x - anchorX)) * dt);
		Mtx44 rotation;
		rotation.SetToRotation(yawLeft, 0, 1, 0);

		//---------------------------------
		forward = rotation * forward;
		back = rotation * back;
		playerRight = rotation * playerRight;
		playerLeft = rotation * playerLeft;
		//---------------------------------

		view = rotation * view;
		target = position + view;
	}
	if (curMousePos.x > anchorX)//yaw right
	{
		Vector3 view;
		view = (target - position).Normalized();

		right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		up = right.Cross(view).Normalized();

		yawRight = (float)((CAMERA_SPEED * (anchorX - curMousePos.x)) * dt);
		Mtx44 rotation;
		rotation.SetToRotation(yawRight, 0, 1, 0);

		//---------------------------------
		forward = rotation * forward;
		back = rotation * back;
		playerRight = rotation * playerRight;
		playerLeft = rotation * playerLeft;
		//---------------------------------

		view = rotation * view;
		target = position + view;
	}

	if (limitPitch < 55 && curMousePos.y < anchorY)//pitch up
	{


		float pitch = (float)((CAMERA_SPEED * (anchorY - curMousePos.y)) * dt);
		Vector3 view = (target - position).Normalized();
		right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		up = right.Cross(view).Normalized();
		Mtx44 rotation;
		rotation.SetToRotation(pitch, right.x, right.y, right.z);

		//---------------------------------
		forward = rotation * forward;
		back = rotation * back;
		playerRight = rotation * playerRight;
		playerLeft = rotation * playerLeft;
		//---------------------------------

		view = rotation * view;
		target = position + view;

		limitPitch += pitch;

	}

	if (limitPitch > -55 && curMousePos.y > anchorY)//pitch down
	{
		float pitch = (float)((-CAMERA_SPEED * (curMousePos.y - anchorY)) * dt);
		Vector3 view = (target - position).Normalized();
		right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		up = right.Cross(view).Normalized();
		Mtx44 rotation;
		rotation.SetToRotation(pitch, right.x, right.y, right.z);

		//---------------------------------
		forward = rotation * forward;
		back = rotation * back;
		playerRight = rotation * playerRight;
		playerLeft = rotation * playerLeft;
		//---------------------------------

		view = rotation * view;
		target = position + view;

		limitPitch += pitch;
	}

	//boundaryCheck();

	if (Application::IsKeyPressed('N'))//move up(y-axis)
	{
		Vector3 view = (target - position).Normalized();
		Vector3 right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		up = right.Cross(view).Normalized();
		position = position + up;
		target = position + view;
	}
	if (Application::IsKeyPressed('M'))//move down(y-axis)
	{
		Vector3 view = (target - position).Normalized();
		Vector3 right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		up = right.Cross(view).Normalized();
		position = position - up;
		target = position + view;
	}

	if (Application::IsKeyPressed('R'))//reset camera
	{
		Reset();
	}

	GetCursorPos(&curMousePos);
	SetCursorPos(WindowX / 2, WindowY / 2);
	anchorX = WindowX / 2;
	anchorY = WindowY / 2;

	mp.x = curMousePos.x;
	mp.y = curMousePos.y;
}

void Camera3::Reset()
{
	position = defaultPosition;
	target = defaultTarget;
	up = defaultUp;
}

