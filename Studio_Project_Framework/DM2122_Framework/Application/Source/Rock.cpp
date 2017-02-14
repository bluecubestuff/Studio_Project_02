#include "Rock.h"

Rock::Rock(StudioProject* scene, Vector3 pos, float size) : GameObject(scene, pos, size)
{
	type = StudioProject::GEO_ROCK;
}
void Rock::interact()
{

}