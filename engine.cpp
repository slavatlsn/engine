#include <iostream>
#include "Engine.h"

using namespace std;

Graphics::Graphics(int h, int w, char block)
{
	height = h;
	width = w;
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			if ((i < width - 1) && (i > 0) && (j > 0) && (j < height - 1)) map[i][j] = ' ';
			else map[i][j] = '\0';
			if (i == 0 || i == width - 1 || j == 0 || j == height - 1) map[i][j] = block;
		}
	}
}

void Graphics::rectangle(int x1, int y1, int x2, int y2, char block)
{
	if ((x1 > 0 && x1 < width) && (x2 > 0 && x2 < width) && (y1 > 0 && y1 < height) && (y2 > 0 && y2 < height))
	{
		for (int a = 0; a < abs(x2 - x1); a++)
		{
			for (int b = 0; b < abs(y2 - y1); b++)
			{
				map[y1 + a][x1 + b - 1] = block;
			}
		}
	}
}

void Graphics::draw(int plx, int ply, char icon, int health, int entities[10][3], char icons[10], int num, int score)
{
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			if (j == plx && i == ply) cout << icon;
			else
			{
				for (int k = 0; k < num; k++)
				{
					if ((j == entities[k][0]) && (i == entities[k][1]))
					{
						cout << icons[k];
						break;
					}
					else cout << map[i][j];
				}
			}
		}
		cout << '\n';
	}
	cout << "health: " << health << " " << "score: " << score;
}

char Graphics::get_el(int i, int j)
{
	return map[i][j];
}

Graphics::~Graphics()
{

}

Entity::Entity(int x, int y, int h, char ic)
{
	i = ic;
	health = h;
	enx = x;
	eny = y;
}

bool Entity::move(int x, int y, Graphics map)
{
	if (map.get_el(y, x) == ' ')
	{
		enx = x;
		eny = y;
		return true;
	}
	else return false;
}

bool Entity::alive()
{
	if (health > 0) return true; else return false;
}

void Entity::inc_h(int n)
{
	health = health + n;
}

void Entity::dec_h(int n)
{
	health = health - n;
}

int Entity::get_health()
{
	return health;
}

char Entity::icon()
{
	return i;
}

int Entity::getx()
{
	return enx;
}

int Entity::gety()
{
	return eny;
}

void Entity::hide()
{
	i = ' ';
}

Entity::~Entity()
{
}
