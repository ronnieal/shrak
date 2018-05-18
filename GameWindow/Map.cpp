#include "Map.h"
#include "TextureManager.h"

int lvl1[20][25] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }, 
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }, 
	{ 1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }, 
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }, 
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }, 
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }, 
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }, 
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }, 
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }, 
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }, 
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }, 
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }, 
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }, 
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }, 
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }, 
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }, 
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }, 
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }, 
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }, 
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }};



Map::Map()
{
	std::cout << "map constructor:" << std::endl;
	dirt = TextureManager::loadTexture("graphics/dirt.png");
	grass = TextureManager::loadTexture("graphics/grass.png");
	water = TextureManager::loadTexture("graphics/water.png");
	swamp = TextureManager::loadTexture("graphics/swamp.png");
	mud = TextureManager::loadTexture("graphics/mud.png");
	
	loadMap(lvl1);

	src.x = 0;
	src.y = 0;
	dest.x = 0;
	dest.y = 0;

	src.w = 32;
	dest.w = 32;
	src.h = 32;
	dest.h = 32;
}
void Map::loadMap(int arr[20][25])
{

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			map[i][j] = arr[i][j];
		}
	}

}

void Map::drawMap()
{
	int type = 0;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			type = map[i][j];
			
			dest.x = j * 32;
			dest.y = i * 32;
			switch (type)
			{
			case 0 :
				TextureManager::draw(dirt, src, dest);
				break;
			case 1:
				TextureManager::draw(grass, src, dest);
				break;
			case 2:
				TextureManager::draw(water, src, dest);
				break;
			case 3:
				TextureManager::draw(mud, src, dest);
				break;
			case 4:
				TextureManager::draw(swamp, src, dest);
				break;
			default:
				break;
			}
		}
	}
}