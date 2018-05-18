#pragma once
#include "Game.h"

class GameObject
{
public:
	GameObject(const char*, int ,int,int);
	~GameObject();

	void update();
	void render();
private:
	int xpos;
	int ypos;
	int scale;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;

};