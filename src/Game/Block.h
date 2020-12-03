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
	~Block();
	friend Player;
private:
	int type_block;
	float x, y;
	float width, height;
	bool isEmpty;
};

