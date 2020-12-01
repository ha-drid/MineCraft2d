#pragma once
#include <iostream>
#include <vector>
#include <GLFW/glfw3.h>

class Block
{
public:
	Block();
	void setPos(float x, float y);
	void init(float x, float y, float width, float height);
	void draw();
	~Block();
private:
	int type_block;
	float x = 0, y = 1;
	float width = 1, height = -1;
};

