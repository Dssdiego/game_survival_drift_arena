#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "../entity/entity.h"

class Scene
{
public:
    Scene(const std::string &name);
    void start();
    void draw();
    void dispose();

private:
    std::vector<Entity> mEntities;
	std::string mName;

	inline void add(Entity e) { mEntities.push_back(e); };
    inline void remove(Entity e) {};
    inline void clearAll() { mEntities.clear(); };
};