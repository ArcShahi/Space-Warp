#include "Pause_UI.hpp"

void PauseUI::show()
{
	DrawText("GAME PAUSED", 450, 500, 70, YELLOW);
	DrawText("PRESS ENTER TO RESUME", 500, 600, 25, WHITE);
}
