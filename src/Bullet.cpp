#include "Bullet.hpp"
#include "Vector_math.hpp"

Bullet::Bullet()
	:max_speed{ 1100.f },  radius{ 1.5f }
{
}

void Bullet::show()
{
	DrawCircle(position.x, position.y, radius, GREEN);
}


