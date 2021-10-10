#pragma once

#include <string>
#include <iostream>

class Scene
{
public:
    Scene(const std::string &name);
    void start();
    void draw();
    void dispose();

private:
	std::string mName;
};