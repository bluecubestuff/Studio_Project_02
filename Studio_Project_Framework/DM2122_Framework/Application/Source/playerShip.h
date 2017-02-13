#ifndef _PLAYER_SHIP_H
#define _PLAYER_SHIP_H

#include "ship.h"
#include "Camera2.h"

class PlayerShip : public Ship
{
public:
	PlayerShip();
	PlayerShip(Vector3 f, Vector3 u, Vector3 r, Vector3 p, Vector3 i, float s);
	~PlayerShip();

	Camera2* Camera;

	bool freeCam;

	float camTime;

	void Update(double dt);
private:
	float Speed;

	bool FlightAssist;
protected:

};

#endif