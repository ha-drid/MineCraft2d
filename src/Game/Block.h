#pragma once
#include <iostream>
#include <vector>
#include <GLFW/glfw3.h>

#include "../type.h"

class Player;

class Block
{
public:
	Block();
	void setPos(float x, float y);
	void init(float x, float y, float width, float height, int type_block);
	bool isEmpty();
	~Block();
	friend Player;
	friend Mob;
	friend void block_draw(Block draw);
private:
	uint32_t type_block = Empty;
	float x, y;
	float width, height;
};

