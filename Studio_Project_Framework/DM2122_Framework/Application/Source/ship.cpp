#include "ship.h"

Ship::Ship()
{
	Forward = Vector3(0, 0, 1);
	Up = Vector3(0, 1, 0);
	Right = Vector3(1, 0, 0);
	Position = Vector3(0, 0, 0);
	Inertia = Vector3(0, 0, 0);

	Stamp = Mtx44(Right.x, Right.y, Right.z, 0, Up.x, Up.y, Up.z, 0, Forward.x, Forward.y, Forward.z, 0, Position.x, Position.y, Position.z, 1);
}

Ship::Ship(Vector3 f, Vector3 u, Vector3 r, Vector3 p, Vector3 i, float s)
{
	Forward = f;
	Up = u;
	Right = r;
	Position = p;
	Inertia = i;

	Stamp = Mtx44(r.x, r.y, r.z, 0, u.x, u.y, u.z, 0, f.x, f.y, f.z, 0, p.x, p.y, p.z, 1);
}

Ship::~Ship()
{

}