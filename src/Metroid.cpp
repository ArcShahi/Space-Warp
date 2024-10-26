#include "Metroid.hpp"
#include "Vector_math.hpp"

Metroid::Metroid()
	:direction{ rand_direction() }, position{ rand_position() }
{}

void Metroid::show()
{
	if (texture.id != 0) {
		RenderTexture(texture, position, angle);
	}
	else {
		std::cerr << "Error: Invalid texture.\n";
	}
}

void Metroid::update(float dt)
{

	position += direction * Box::SPEED * dt;
	angle += Box::SPIN * dt;

	if (position.x < texture.width / 2.f)
	{
		position.x = texture.width / 2.f;
		direction.x = std::abs(direction.x);
	}
	else if (position.x > GetScreenWidth() - texture.width / 2.f)
	{
		position.x = GetScreenWidth() - texture.width / 2.f;
		direction.x = -std::abs(direction.x);
	}

	if (position.y < texture.height / 2.f)
	{
		position.y = texture.height / 2.f;
		direction.y = std::abs(direction.y);
	}
	else if (position.y > GetScreenHeight() - texture.height / 2.f)
	{
		position.y = GetScreenHeight() - texture.height / 2.f;
		direction.y = -std::abs(direction.y);
	}



 



}

void Metroid::init_texture()
{
	fs::path asset_path = R"(assets/junk.png)";

	texture = LoadTexture(asset_path.string().c_str());

	if (texture.id == 0)
		std::cerr << "Couldn't Load " << asset_path.string() << '\n';
}





