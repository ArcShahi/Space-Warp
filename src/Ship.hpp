#ifndef SHIP_HPP
#define SHIP_HPP


#include "raylib.h"
#include <filesystem>
#include <iostream>
#include <vector>
#include "Bullet.hpp"
namespace fs = std::filesystem;


class Ship
{
public:
	Ship();

	void update(float dt);
	void show();
	void init_texture();


public:

	float speed{ 400.f };
	float angle{ -90.0f };
	float rotaion_speed{ 150.f };
	float reload_time{ 0.9f};
	
	Vector2 position{};
	Vector2 velocity{};
	Vector2 origin{};

	Texture2D texture{};


	// Bullets
	std::vector<Bullet> magzine{};
};

#endif // !SHIP_HPP


