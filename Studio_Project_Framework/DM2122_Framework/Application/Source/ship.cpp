#include "ship.h"

Ship::Ship()
{

}

Ship::Ship(Vector3 f, Vector3 u, Vector3 r, Vector3 p, Vector3 i, float s)
{
	Forward = f;
	Up = u;
	Right = r;
	Position = p;
	Inertia = i;
	Speed = s;

	FlightAssist = true;

	Stamp = Mtx44(r.x, r.y, r.z, 0, u.x, u.y, u.z, 0, f.x, f.y, f.z, 0, p.x, p.y, p.z, 1);
}

Ship::~Ship()
{

}

void Ship::playerShipUpdate(double dt)	//Player ship movement and control
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
			if (this->Inertia.Length() < this->Speed)	//if ship Velocity is lower than speed
				this->Inertia += this->Forward * (float)dt;	//increase ship velocity
			else if (this->Inertia.Length() < this->Speed)
				this->Inertia -= this->Forward * (float)dt;	//decrease ship Velocity
		}
		else if (this->Speed < 0)
		{
			if (this->Inertia.Length() < this->Speed)	//if ship Velocity is higher than speed
				this->Inertia += this->Forward * (float)dt;	//decrease ship velocity
			else if (this->Inertia.Length() > this->Speed)
				this->Inertia -= this->Forward * (float)dt;	//increase ship Velocity
		}
		else
		{	//in the case where speed = 0
			if (this->Inertia.Length() != 0)	//slowing down the ship to a stop
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
	this->Position += this->Inertia * (float)dt;	//update position according to ship inertia
}
