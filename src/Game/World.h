#pragma once
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>
#include <thread>
#include "Player.h"
#include "Block.h"
#include "draw.h"
#include "../size.h"

class World
{
public:
	World();
	void init();
	void show();
	void vertMove(float Gravity);
	void player_move(GLFWwindow* window);
	~World();
	friend void foo(int begin, int end, int begin1, int end1);
private:
	Player player;
	std::vector<std::vector<Block>> block;
};

