#include "scene.h"

void Scene::add(Entity e)
{
	mEntities.push_back(e);
}

void Scene::remove(Entity e)
{
	//mEntities.erase(e);
}

void Scene::clean()
{
	mEntities.clear();
}
