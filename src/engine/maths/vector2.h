#pragma once

class Vec2
{
public:
	float x, y;

	Vec2(float x, float y);

	static const Vec2 zero;
    static const Vec2 one;
    static const Vec2 left;
    static const Vec2 right;
    static const Vec2 up;
    static const Vec2 down;
};

