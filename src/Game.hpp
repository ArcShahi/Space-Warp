#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <cmath>


#include "Metroid.hpp"
#include "Ship.hpp"
#include "Main_UI.hpp"
#include "Pause_UI.hpp"

enum class GameState
{
	MAINMENU,PLAYING,PAUSED,
};

class Game
{
public:
	Game();
	~Game();
	void run();



private:
	void update(float dt);
	void render();
	void set_state(GameState new_state);

private:
	//Ship

	Ship ship{};


	std::vector<Metroid> metroids{};
	Metroid metroid{};
	GameState current_state{};
	bool is_running{};
	float junk_spwan_counter{};


	MainUI main_menu{};
	PauseUI pause_menu{};
};

#endif // !GAME_HPP