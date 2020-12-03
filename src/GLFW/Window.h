#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <GLFW/glfw3.h>

#include "../Game/World.h"
#include "../size.h"

class Window
{
public:
	Window(int width, int height, std::string title);
	void setContextCurent();
	void loop();
	~Window();
private:
	GLFWwindow* window;
};

