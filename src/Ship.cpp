#include "Ship.hpp"
#include "Vector_math.hpp"

Ship::Ship()
	:position{ 600.f,800.f }
{
}

void Ship::update(float dt)
{


	if (IsKeyDown('A'))
	{
		angle -= rotaion_speed * dt;
	}
	if (IsKeyDown('D'))
	{
		angle += rotaion_speed * dt;
	}

	float radian = angle * (PI / 180.f);

	Vector2 direction{ std::cos(radian),std::sin(radian) };

	if (IsKeyDown('W'))
	{
		velocity = direction * speed * dt;
	}
	else
	{
		velocity = { 0 };
	}

	position += velocity;

	///////////////////////////////////////////////////////////////////////////////////////////////////////
	///					SHOOTING BULLET												///
	///////////////////////////////////////////////////////////////////////////////////////////////////////

  // Update reload timer
	reload_time += dt;

	// Create new bullets
	if (IsKeyPressed(KEY_SPACE) && reload_time >= 0.1f)
	{
		reload_time = 0.9f; // reset reload

		// Calculate bullet direction based on ship's angle
		float radian = angle * (PI / 180.f);
		Vector2 bulletDir = { std::cos(radian), std::sin(radian) };

		Bullet bullet{};
		// Bullet starts from ship's position
		bullet.position = position;  
		// Set velocity based on direction and speed
		bullet.velocity = bulletDir * bullet.max_speed;  
		magzine.push_back(bullet);
	}

	// Update existing bullets
	for (int i = magzine.size() - 1; i >= 0; --i)
	{
		// Update bullet position using its own velocity
		magzine[i].position.x += magzine[i].velocity.x * dt;
		magzine[i].position.y += magzine[i].velocity.y * dt;

		// Remove bullets that are off screen
		if (magzine[i].position.x < 0.0f ||
			magzine[i].position.x > GetScreenWidth() ||
			magzine[i].position.y < 0.0f ||
			magzine[i].position.y > GetScreenHeight())
		{
			magzine[i] = magzine.back();
			magzine.pop_back();
		}
	}

}

void Ship::show()
{
	RenderTexture(texture, position, angle, 0.15);
	
	for (auto& bullet : magzine)
	{
		bullet.show();
	}
}

void Ship::init_texture()
{
	fs::path asset_path = R"(assets/fship.png)";

	texture = LoadTexture(asset_path.string().c_str());

	if (texture.id == 0)
		std::cerr << "Couldn't Load " << asset_path.string() << '\n';

	origin = { (float)texture.width * 0.1f * 0.5f, (float)texture.height * 0.1f * 0.5f };
}


