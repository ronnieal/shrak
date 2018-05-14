#include "Game.h"
#include "TextureManager.h"

SDL_Texture *playerTex, *background;
SDL_Rect srcR, destR;
Game::Game()
{

}
Game::~Game()
{

}
void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialized" << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "window created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "renderer created" << std::endl;
		}

		playerTex = TextureManager::loadTexture("graphics/shrak.png", renderer);	
		background = TextureManager::loadTexture("graphics/swamp.png", renderer);
		isRunning = true;
	}
	else
		isRunning = false;
}
void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch(event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	
	default:
		break;
	}
		

}
void Game::update()
{
	count++;

	destR.h = 78*5;
	destR.w = 68*5;
	destR.x = count/10;

	std::cout << count << std::endl;
}
void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, background, NULL, NULL);
	SDL_RenderCopy(renderer, playerTex, NULL, &destR);
	SDL_RenderPresent(renderer);
}
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}