#include "PlayerShip.h"

PlayerShip::PlayerShip()
{
	this->Forward = Vector3(0, 0, 1);
	this->Up = Vector3(0, 1, 0);
	this->Right = Vector3(1, 0, 0);
	this->Position = Vector3(0, 0, 0);
	this->Inertia = Vector3(0, 0, 0);
	this->Speed = 0;
	this->camTime = 0.f;

	this->FlightAssist = true;
	this->freeCam = false;

	Camera = new Camera2;

	Camera->Init(this->Position, this->Forward, this->Up);

	this->Stamp = Mtx44(Right.x, Right.y, Right.z, 0, Up.x, Up.y, Up.z, 0, Forward.x, Forward.y, Forward.z, 0, Position.x, Position.y, Position.z, 1);
}

PlayerShip::PlayerShip(Vector3 f, Vector3 u, Vector3 r, Vector3 p, Vector3 i, float s)
{
	this->Forward = f;
	this->Up = u;
	this->Right = r;
	this->Position = p;
	this->Inertia = i;

	this->FlightAssist = true;
	this->freeCam = false;

	Camera = new Camera2;

	Camera->Init(this->Position, this->Forward, this->Up);

	this->Stamp = Mtx44(r.x, r.y, r.z, 0, u.x, u.y, u.z, 0, f.x, f.y, f.z, 0, p.x, p.y, p.z, 1);
}

PlayerShip::~PlayerShip()
{

}

void PlayerShip::Update(double dt)	//Player PlayerShip movement and control
{
	//========================================================================
	//Setting FlightAssist on or off
	if (Application::IsKeyPressed('X'))
	{
		FlightAssist = false;
	}
	if (Application::IsKeyPressed('Z'))
	{
		FlightAssist = true;
	}
	//========================================================================
	//toggle between mouse control the camera or the ship
	if (Application::IsKeyPressed(VK_MBUTTON) && freeCam)
	{
		if (camTime < 0)
		{
			freeCam = false;
			this->Camera->Init(this->Position, this->Forward, this->Up);
			camTime = 0.5f;
		}
		camTime -= dt;
	}
	else if (Application::IsKeyPressed(VK_MBUTTON) && !freeCam)
	{
		if (camTime < 0)
		{
			freeCam = true;
			this->Camera->Init(this->Position, this->Forward, this->Up);
			camTime = 0.5f;
		}
		camTime -= dt;
	}
	//========================================================================
	if (this->FlightAssist == false)	//FLIGHT ASSISTS OFF
	{
		//Adjusting how fast the player want to fly
		//====================================================================
		if (Application::IsKeyPressed('W') && this->Speed < 10.f)
		{
			this->Speed += 4.f * (float)dt;
		}
		else if (Application::IsKeyPressed('S') && this->Speed > -10.f)
		{
			this->Speed += -4.f * (float)dt;
		}
		//Setting Velocity to zero
		else if (Application::IsKeyPressed('0'))
		{
			this->Speed = 0;
		}
		//=====================================================================
		if (this->Speed > 0)
		{
			if (this->Inertia.Length() < this->Speed)	//if PlayerShip Velocity is lower than speed
				this->Inertia += this->Forward * (float)dt;	//increase PlayerShip velocity
		}
		else if (this->Speed < 0)
		{
			if (this->Inertia.Length() > this->Speed)
				this->Inertia -= this->Forward * (float)dt;	//increase PlayerShip Velocity
		}
		//======================================================================
		if (Application::IsKeyPressed('E') && Inertia.Length() < 5)	//strafe right
		{
			this->Position -= this->Right.Normalized() * (float)dt;
		}
		else if (Application::IsKeyPressed('Q') && Inertia.Length() < 5)	//strafe left
		{
			this->Position += this->Right.Normalized() * (float)dt;
		}
		//======================================================================
		if (Application::IsKeyPressed('R'))		//elevate
		{
			this->Position += this->Up.Normalized() * (float)dt;
		}
		else if (Application::IsKeyPressed('F'))	//depress
		{
			this->Position -= this->Up.Normalized() * (float)dt;
		}
	}
	//===========================================================================
	else if (this->FlightAssist == true)	//FLIGHT ASSISTS ON
	{
		if (Application::IsKeyPressed('W') && this->Speed < 10.f)
		{
			this->Speed += 4.f * (float)dt;
		}
		else if (Application::IsKeyPressed('S') && this->Speed > -10.f)
		{
			this->Speed += -4.f * (float)dt;
		}
		else if (Application::IsKeyPressed('0'))
		{
			this->Speed = 0;
		}
		if (this->Speed > 0)
		{
			if (this->Inertia.Length() < this->Speed)	//if PlayerShip Velocity is lower than speed
				this->Inertia += this->Forward * (float)dt;	//increase PlayerShip velocity
			else if (this->Inertia.Length() > this->Speed)
				this->Inertia -= this->Forward * (float)dt;	//decrease PlayerShip Velocity
		}
		else if (this->Speed < 0)
		{
			if (this->Inertia.Length() < this->Speed)	//if PlayerShip Velocity is higher than speed
				this->Inertia += this->Forward * (float)dt;	//decrease PlayerShip velocity
			else if (this->Inertia.Length() > this->Speed)
				this->Inertia -= this->Forward * (float)dt;	//increase PlayerShip Velocity
		}
		else
		{	//in the case where speed = 0
			if (this->Inertia.Length() != 0)	//slowing down the PlayerShip to a stop
			{
				this->Inertia -= this->Inertia.Normalized() * (float)dt;
			}
		}
		if (Application::IsKeyPressed('E') && Inertia.Length() < 5)	//strafe right
		{
			this->Position -= this->Right.Normalized() * (float)dt;
		}
		else if (Application::IsKeyPressed('Q') && Inertia.Length() < 5)	//strafe left
		{
			this->Position += this->Right.Normalized() * (float)dt;
		}
		//======================================================================
		if (Application::IsKeyPressed('R'))		//elevate
		{
			this->Position += this->Up.Normalized() * (float)dt;
		}
		else if (Application::IsKeyPressed('F'))	//depress
		{
			this->Position -= this->Up.Normalized() * (float)dt;
		}
		if (Application::IsKeyPressed('D'))		//roll right
		{
			float rollSpeed = 30 * (float)dt;
			Mtx44 roll;
			roll.SetToRotation(rollSpeed, this->Forward.x, this->Forward.y, this->Forward.z);
			this->Right = roll * this->Right;
			this->Up = roll * this->Up;
		}
		else if (Application::IsKeyPressed('A'))		//roll left
		{
			float rollSpeed = -30 * (float)dt;
			Mtx44 roll;
			roll.SetToRotation(rollSpeed, this->Forward.x, this->Forward.y, this->Forward.z);
			this->Right = roll * this->Right;
			this->Up = roll * this->Up;
		}
	}
	//===========================================================================
	//mouse control for the ship
	if (!freeCam)
	{
		cursorPos = mouse.mouseMovement();
		if (cursorPos.x)
		{
			float yawSpeed = cursorPos.x * -5 * (float)dt;
			Mtx44 yaw;
			yaw.SetToRotation(yawSpeed, this->Up.x, this->Up.y, this->Up.z);
			this->Forward = yaw * this->Forward;
			this->Right = yaw * this->Right;
		}
		if (cursorPos.y)
		{
			float pitchSpeed = cursorPos.y * 5 * (float)dt;
			Mtx44 pitch;
			pitch.SetToRotation(pitchSpeed, this->Right.x, this->Right.y, this->Right.y);
			this->Forward = pitch * this->Forward;
			this->Up = pitch * this->Up;
		}
	}
	//===========================================================================
	this->Position += this->Inertia * (float)dt;	//update position according to PlayerShip inertia
	Camera->Update(dt, freeCam, this->Forward, this->Right, this->Up, this->Position);
}