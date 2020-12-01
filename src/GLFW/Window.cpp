#include "Window.h"

Window::Window(int width, int height, std::string title)
{
	window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (!window)
	{
		throw std::runtime_error("Window error!!!");
	}
	setContextCurent();
}

void Window::setContextCurent()
{
	glfwMakeContextCurrent(window);
}

void Window::loop()
{
	World world;
	world.init();
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		world.show();
		world.vertMove(-0.01f);
		glfwSwapBuffers(window);
		glfwPollEvents();
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}

Window::~Window()
{
	glfwDestroyWindow(window);
}
