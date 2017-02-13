#ifndef _MOUSE_CONTROL_H
#define _MOUSE_CONTROL_H

#include "Application.h"
#include "DetectMemoryLeak.h"

//Include GLEW
#include <GL/glew.h>
//Include GLFW
#include <GLFW/glfw3.h>

class Mouse
{
public:
	Mouse();
	~Mouse();

	int anchorX, anchorY;
	int windowX, windowY;
	POINT mousePosition;
	POINT currMousePosition;
	POINT mouseMovement();
private:
	
};

#endif