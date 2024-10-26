#ifndef METROID_HPP
#define METROID_HPP

#include "raylib.h"

#include "Randum.hpp"
#include <iostream>
#include <filesystem>
#include <cmath>

namespace fs = std::filesystem;

namespace Box
{
	constexpr float SPIN{ 125.0f };
	constexpr float SPEED{ 250.0f };
	constexpr float SPAWN_TIME{ 3.1f };
	

}

class Metroid
{
public:
	Metroid();
	void show();
	void update(float dt);

	void init_texture();

public:
	Texture2D texture{};
	Vector2 direction{};
	Vector2 position{};

	float angle{};

};


inline Vector2 rand_direction()
{
	float angle{ xe::randomf(0.0f,2.0f * PI) };

	return { std::cos(angle),std::sin(angle) };

}
inline Vector2 rand_position()
{

	return { xe::randomf(100.f / 2.0f,1200.f - 50.f / 2.0f),
		xe::randomf(100.0f / 2.0f,900.f - 50.f / 2.0f) };
}


#endif // !METROID_HPP
