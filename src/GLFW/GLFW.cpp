#include "GLFW.h"

GLFW::GLFW()
{
	if(!glfwInit())
		throw std::runtime_error("GLFW init problems!!!");
}

GLFW::~GLFW()
{
	glfwTerminate();
}
