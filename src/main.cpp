#include <iostream>
#include <stdexcept>

#include <GLFW/glfw3.h>
#include "GLFW/GLFW.h"
#include "GLFW/Window.h"
#include "size.h"

int main()
{
    try
    {
        GLFW glfw;
        Window window(width_window, height_window, "Mine Craft 2d");
        window.loop();
    }
    catch (const std::runtime_error& e)
    {
        std::cout << "Exceptions" << e.what() << std::endl;
        return -1;
    }
    
    return 0;
}