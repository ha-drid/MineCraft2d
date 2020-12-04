#pragma once
#include <iostream>
#include <vector>
#include <GLFW/glfw3.h>

class Player;

class Block
{
public:
	Block();
	void setPos(float x, float y);
	void init(float x, float y, float width, float height, int type_block);
	void draw();
	bool isEmpty();
	~Block();
	friend Player;
private:
	uint32_t type_block = 0;
	float x, y;
	float width, height;
};

