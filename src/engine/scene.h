#pragma once

#include <vector>
#include "entity/entity.h"

class Scene
{
public:
	void start();
	void add(Entity e);
	void remove(Entity e);
	//void remove(int index); // TODO: Implement
	void clean();

private:
	std::vector<Entity> mEntities;
	int mId;
};