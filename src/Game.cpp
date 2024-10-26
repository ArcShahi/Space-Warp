#include "Game.hpp"

Game::Game()
	:current_state{ GameState::MAINMENU }, is_running{ true }
{

	InitWindow(1200, 900, "Shahi Space");
	if (!IsWindowReady()) {
		std::cerr << "WINDOW CREATION FAILED\n";
	}

	// Initialize Textures
	// Load Texture After Initializing window else Access Violation
	ship.init_texture();


}

Game::~Game()
{
	UnloadTexture(metroid.texture);
	CloseWindow();
}

void Game::run()
{

	SetTargetFPS(120);

	while (!WindowShouldClose())
	{
		float dt = GetFrameTime();

		update(dt);

		render();

	}
}



void Game::update(float dt)
{


	switch (current_state)
	{
	case GameState::MAINMENU:
		if (IsKeyPressed(KEY_ENTER))
		{
			set_state(GameState::PLAYING);
		}
		break;
	case GameState::PLAYING:
	{
		if (IsKeyPressed('P'))
		{
			set_state(GameState::PAUSED);
			break;
		}

		junk_spwan_counter += dt; // increment timer by delta time

		// Check if 3 seconds have passed
		if (junk_spwan_counter >= 3.0f) {
			Metroid metroid{};
			metroid.init_texture();
			metroids.push_back(metroid);
			junk_spwan_counter = 0.0f; // reset timer
		}

		for (auto& i : metroids)
		{
			i.update(dt);
		}

		/// UPDATE SHIP
		ship.update(dt);

		/// CHECK BULLET ASTEROID COLLISION
	}
	break;
	case GameState::PAUSED:
		if (IsKeyPressed(KEY_ENTER))
			set_state(GameState::PLAYING);
		break;
	default:
		break;
	}



}

void Game::render()
{

	BeginDrawing();
	ClearBackground(BLACK);
	DrawFPS(5, 5);

	switch (current_state)
	{
	case GameState::MAINMENU:
	{
		main_menu.show();
	}
	break;
	case GameState::PLAYING:
	{
		for (auto& i : metroids)
		{
			i.show();
		}

		ship.show();
	}
	break;
	case GameState::PAUSED:
		pause_menu.show();
		break;
	default:
		break;
	}

	EndDrawing();
}

void Game::set_state(GameState new_state)
{
	current_state = new_state;
}
