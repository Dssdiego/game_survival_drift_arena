#include "vector2.h"

const Vec2 Vec2::zero = Vec2(0, 0);
const Vec2 Vec2::one = Vec2(1, 1);
const Vec2 Vec2::left = Vec2(-1, 0);
const Vec2 Vec2::right = Vec2(1, 0);
const Vec2 Vec2::up = Vec2(0, 1); // REVIEW: Up should be positive or negative? Where does the sceen starts?
const Vec2 Vec2::down = Vec2(0, -1); // REVIEW: Up should be positive or negative? Where does the sceen starts?

Vec2::Vec2(float x, float y): x(x), y(y)
{ }
