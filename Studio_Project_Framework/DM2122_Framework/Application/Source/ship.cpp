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

	Stamp = Mtx44(r.x, r.y, r.z, 0, u.x, u.y, u.z, 0, f.x, f.y, f.z, 0, p.x, p.y, p.z, 1);
}

Ship::~Ship()
{

}

