#include "TextureManager.h"
//used to load textures from a temporary surface
SDL_Texture* TextureManager::loadTexture(const char* texture) 
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_SetColorKey(tempSurface, SDL_TRUE, SDL_MapRGB(tempSurface->format, 255, 255, 255));
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	//free memory
	SDL_FreeSurface(tempSurface);

	return tex;

}

void TextureManager::draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);

}