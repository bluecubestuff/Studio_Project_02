#include "Mithril.h"

Mithril::Mithril(StudioProject* scene, Vector3 pos, float size) : GameObject(scene, pos, size)
{
	type = StudioProject::GEO_MITHRIL;
}
void Mithril::interact()
{

}