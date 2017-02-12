#ifndef _MOUSE_CONTROL_H
#define _MOUSE_CONTROL_H

#include "Application.h"

//Include GLEW
#include <GL/glew.h>
//Include GLFW
#include <GLFW/glfw3.h>

extern GLFWwindow* m_window;

class Mouse
{
public:
	int anchorX, anchorY;
	int windowX, windowY;
};

#endif