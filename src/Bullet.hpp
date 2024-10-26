#ifndef BULLET_HPP
#define BULLET_HPP
#include "raylib.h"



class Bullet
{
public:
	Bullet();
	void show();

public:

	Vector2 position{};
	Vector2 velocity{};
	float max_speed{};
	float radius{  };

private:
	
	float shoot_timer{0.0f};

};



#endif // !BULLET_HPP
