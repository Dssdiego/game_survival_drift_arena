#pragma once

#include "entity.h"
#include <vector>

class Scene
{
public:
	void create();
	void add(Entity e);
	void remove(Entity e);
	//void remove(int index); // TODO: Implement
	void clean();

private:
	std::vector<Entity> mEntities;
	int mId;
};