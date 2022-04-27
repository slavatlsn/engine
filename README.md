# example of code
#include <iostream>
#include <conio.h>
#include "Engine.h"

using namespace std;

int w = 30;
int h = 20;
int score = 0;
int prx = 2;
int pry = 2;

int main()
{
	Graphics pole(h, w, '#');
	Entity player(10, 15, 50, '@');
	prx = rand() % w + 1;
	pry = rand() % h + 1;
	while (!(pole.get_el(prx, pry) == ' '))
	{
		prx = rand() % w + 1;
		pry = rand() % h + 1;
	}
	Entity prize(prx, pry, 10, '%');
	pole.rectangle(5, 7, 9, 4, '#');
	int entities[10][3] = { {prize.getx(), prize.gety(), prize.get_health()} };
	char icons[10] = { prize.icon() };
	pole.draw(player.getx(), player.gety(), player.icon(), player.get_health(), entities, icons, 1, score);
	while (player.alive())
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'w': player.move(player.getx() - 1, player.gety(), pole);
				break;
			case 'a': player.move(player.getx(), player.gety() - 1, pole);
				break;
			case 's': player.move(player.getx() + 1, player.gety(), pole);
				break;
			case 'd': player.move(player.getx(), player.gety() + 1, pole);
				break;
			}
			system("cls");
			if ((player.getx() == prize.getx()) && (player.gety() == prize.gety()))
			{
				score = score + 1;
				prx = rand() % w + 1;
				pry = rand() % h + 1;
				while (!(pole.get_el(prx, pry) == ' '))
				{
					prx = rand() % w + 1;
					pry = rand() % h + 1;
				}
				prize.move(prx, pry, pole);
				entities[0][0] = prize.getx();
				entities[0][1] = prize.gety();
				pole.draw(player.getx(), player.gety(), player.icon(), player.get_health(), entities, icons, 1, score);
			}
			else pole.draw(player.getx(), player.gety(), player.icon(), player.get_health(), entities, icons, 1, score);
		}
	}
}
