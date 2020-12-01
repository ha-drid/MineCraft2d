#pragma once
#include <iostream>
#include <vector>

#include <GLFW/glfw3.h>
#include <gl/GL.h>

class Player
{
public:
	Player();
	void setPos(float x, float y);
	void init(float x, float y, float width, float height);
	void draw();
	void vertMove(float Gravity);
	bool ray_cast();//для того чтобы понимать столнкулись мы с обьектом или нет
	~Player();
private:
	float x, y;
	float width, height;
	float vertSpeed;
};

