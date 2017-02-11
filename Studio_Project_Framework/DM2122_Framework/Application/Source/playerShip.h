#ifndef PLAYER_SHIP_H
#define PLAYER_SHIP_H

#include "ship.h"

using std::vector;

class PlayerShip : public Ship
{
public:
	PlayerShip();
	PlayerShip(Vector3 f, Vector3 u, Vector3 r, Vector3 p, Vector3 i, float s);
	~PlayerShip();

	void playerInit();

	void playerPlayerShipUpdate(double dt);

private:
	Camera2 Camera;

	float Speed;

	bool FlightAssist;
protected:

};

#endif