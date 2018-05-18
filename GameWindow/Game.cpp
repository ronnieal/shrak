#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "ECS.h"
#include "Components.h"

GameObject *shrek, *farquaad;
SDL_Renderer* Game::renderer = nullptr;
Map *map;
SDL_Rect srcR, destR;

Manager manager;
auto& newPlayer(manager.addEntity());

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

		shrek = new GameObject("graphics/shrak.png", 0,0,5);
		farquaad = new GameObject("graphics/farquaad.png", 0, 400, 2);

		newPlayer.addComponent<PositionComponent>();
	

		map = new Map();
		newPlayer.getComponent<PositionComponent>().setPos(500,500);


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
	shrek->update();
	farquaad->update();
	manager.update();
	std::cout << newPlayer.getComponent<PositionComponent>().x() << ", " << newPlayer.getComponent<PositionComponent>().y() << std::endl;
	
}
void Game::render()
{
	SDL_RenderClear(renderer);
	
	map->drawMap();
	shrek->render();
	farquaad->render();


	SDL_RenderPresent(renderer);
}
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}