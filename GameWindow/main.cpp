#include "SDL.h"
#include "Game.h"


Game *game = nullptr;

int main(int argc, char *argv[])
{
	const int FPS = 60;
	const int FRAME_DELAY = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;


	game = new Game();
	game->init("Shrek", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	while (game->running())
	{
		frameStart = SDL_GetTicks();


		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (FRAME_DELAY > frameTime)
		{
			SDL_Delay(FRAME_DELAY - frameTime);
		}
		//handle input
		//update objects
		//render changesto display
	}
	game->clean();
	return 0;
}