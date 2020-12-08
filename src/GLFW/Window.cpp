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
		glClearColor(0.4f, 0.4f, 1.0f, 0);
		glClear(GL_COLOR_BUFFER_BIT);

		glLoadIdentity();
		world.show();
		world.vertMove(0.0002);
		world.player_move(window);
		glfwSwapBuffers(window);
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

Window::~Window()
{
	glfwDestroyWindow(window);
}
