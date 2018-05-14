#include "TextureManager.h"
//used to load textures from a temporary surface
SDL_Texture* TextureManager::loadTexture(const char* texture, SDL_Renderer* ren) 
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_SetColorKey(tempSurface, SDL_TRUE, SDL_MapRGB(tempSurface->format, 255, 255, 255));
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
	//free memory
	SDL_FreeSurface(tempSurface);

	return tex;

}