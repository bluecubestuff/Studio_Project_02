#include "PlayerShip.h"

PlayerShip::PlayerShip()
{
	this->Forward = Vector3(0, 0, 1);
	this->Up = Vector3(0, 1, 0);
	this->Right = Vector3(1, 0, 0);
	this->Position = Vector3(0, 0, 0);
	this->Inertia = Vector3(0, 0, 0);
	this->Speed = 0;

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
		freeCam = false;
	}
	else if (Application::IsKeyPressed(VK_MBUTTON) && !freeCam)
	{
		freeCam = true;
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
			else if (this->Inertia.Length() < this->Speed)
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
		//======================================================================
		if (Application::IsKeyPressed('E'))	//strafe right
		{
			this->Inertia += this->Right.Normalized() * (float)dt;
		}
		else if (Application::IsKeyPressed('Q'))	//strafe left
		{
			this->Inertia -= this->Right.Normalized() * (float)dt;
		}
		//======================================================================
		if (Application::IsKeyPressed('R'))		//elevate
		{
			this->Inertia += this->Up.Normalized() * (float)dt;
		}
		else if (Application::IsKeyPressed('F'))	//depress
		{
			this->Inertia -= this->Up.Normalized() * (float)dt;
		}
	}
	//===========================================================================
	else if (this->FlightAssist == true)	//FLIGHT ASSISTS ON
	{

	}
	//===========================================================================
	//mouse control for the ship
	if (!freeCam)
	{

	}
	//===========================================================================
	this->Position += this->Inertia * (float)dt;	//update position according to PlayerShip inertia
	Camera->Update(dt, freeCam, this->Forward, this->Right, this->Up, this->Position);
}