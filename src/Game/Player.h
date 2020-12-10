#pragma once
#include <iostream>
#include <vector>
#include <cstdio>
#include <thread>
#include <chrono>
#include <GLFW/glfw3.h>
#include <gl/GL.h>

#include "Block.h"
#include "../size.h"

class Player
{
public:
	Player();
	void setPos(float x, float y);
	void init(float x, float y, float width, float height);
	void vertMove(float Gravity, std::vector<std::vector<Block>> block);
	void move(GLFWwindow* window, std::vector<std::vector<Block>>& block);
	void horizon_move(std::vector<std::vector<Block>>& block, float dx);
	void put_blocks(GLFWwindow* window, std::vector<std::vector<Block>>& block);
	bool isColision(Block block);
	~Player();
	friend GL;
private:
	float x, y;
	float width, height;
	float vertSpeed;
	bool isFly;
};

