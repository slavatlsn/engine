#pragma once

class Graphics
{
public:
	void draw(int plx, int ply, char icon, int health, int entities[10][3], char icons[10], int num, int score);
	char get_el(int i, int j);
	Graphics(int h, int w, char block);
	void rectangle(int x1, int y1, int x2, int y2, char block);
	~Graphics();

private:
	char block = ' ';
	char map[99][99] = { {} };
	int height = 100;
	int width = 100;
};

class Entity
{
public:
	Entity(int x, int y, int h, char ic);
	bool move(int x, int y, Graphics map);
	bool alive();
	void inc_h(int n);
	void dec_h(int n);
	int get_health();
	char icon();
	int getx();
	int gety();
	void hide();
	~Entity();

private:
	char i = ' ';
	int health = 0;
	int enx = 0;
	int eny = 0;
};
