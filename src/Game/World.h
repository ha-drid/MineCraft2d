#pragma once
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>
#include <thread>
#include "Player.h"
#include "Block.h"
#include "../size.h"

class World
{
public:
	World();
	void init();
	void draw_block(int begin, int end);
	void show();
	void vertMove(float Gravity);
	void player_move(GLFWwindow* window);
	~World();
private:
	Player player;
	std::vector<std::vector<Block>> block;
};

