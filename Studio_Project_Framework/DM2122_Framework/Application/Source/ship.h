#ifndef SHIP_H
#define SHIP_H

#include <vector>

#include "Application.h"
#include "Vector3.h"
#include "Mtx44.h"

using std::vector;

class Ship
{
public:
	Ship();
	Ship(Vector3 f, Vector3 u, Vector3 r, Vector3 p, Vector3 i, float s);
	~Ship();

	void playerShipUpdate(double dt);

private:
	Vector3 Forward;
	Vector3 Up;
	Vector3 Right;
	Vector3 Position;
	Vector3 Inertia;

	float Speed;

	bool FlightAssist;

	Mtx44 Stamp;
protected:

};

#endif