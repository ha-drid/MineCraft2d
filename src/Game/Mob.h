#pragma once
#include <GLFW/glfw3.h>
#include "Block.h"

class Mob
{
public:
	Mob(int type_mob);
	void setPos(float x, float y);
	void init(float x, float y, float width, float height);
	void vertMove(float Gravity, std::vector<std::vector<Block>> block);
	void move(GLFWwindow* window, std::vector<std::vector<Block>>& block);
	~Mob();
private:
	float x, y;
	float width, height;
	float vertSpeed;
	bool isFly;
	int type_mob;
};

