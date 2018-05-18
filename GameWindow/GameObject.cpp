#include "GameObject.h"
#include "TextureManager.h"
GameObject::GameObject(const char* textureSheet, int x, int y,int s)
{
	objTexture = TextureManager::loadTexture(textureSheet);
	xpos = x;
	ypos = y;
	scale = s;
}

void GameObject::update()
{
	xpos++;
	ypos++;

	srcRect.h = 78;
	srcRect.w = 68;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = srcRect.h * scale;
	destRect.w = srcRect.w * scale;
}

void GameObject::render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);

}