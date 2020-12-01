#pragma once
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>

#include "Player.h"
#include "Block.h"

class World
{
public:
	World();
	void init();
	void show();
	void vertMove(float Gravity);
	~World();
private:
	Player player;
	std::vector<Block> block;
};

