#pragma once
#include "Game.h"
#include "SDL_image.h"
//used to load textures 
class TextureManager
{
public:
	static SDL_Texture* loadTexture(const char* fileName);
	static void draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);

};