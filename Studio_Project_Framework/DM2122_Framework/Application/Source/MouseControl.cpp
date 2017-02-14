#include "MouseControl.h"
#include <math.h>
#include <iostream>

Mouse::Mouse()
{
	glfwGetWindowSize(Application::m_window, &windowX, &windowY);	//get window size
	anchorX = windowX / 2;		//center of window
	anchorY = windowY / 2;		//center of window
	mousePosition.x = 0;
	mousePosition.y = 0;
}

Mouse::~Mouse()
{
	delete this;
}

POINT Mouse::mouseMovement()
{
	mousePosition.x = 0;				//reset mouse position
	mousePosition.y = 0;
	GetCursorPos(&currMousePosition);	//get cursor position
	SetCursorPos(anchorX, anchorY);		//set cursor back onto origin
	if (currMousePosition.x > anchorX)		//if cursor is leftside of center
	{
		mousePosition.x = currMousePosition.x - anchorX;
	}
	else if (currMousePosition.x < anchorX)	//if cursor is rightside of center
	{
		mousePosition.x = currMousePosition.x - anchorX;
	}
	if (anchorY < currMousePosition.y)		//if cursor is below center
	{
		mousePosition.y = currMousePosition.y - anchorY;
	}
	else if (anchorY > currMousePosition.y)	//if cursor is above center
	{
		mousePosition.y = currMousePosition.y - anchorY;
	}
	return mousePosition;
}

POINT Mouse::flightMouse()
{
	POINT temp;							//temp point to store previous mouse position
	temp = mousePosition;
	GetCursorPos(&currMousePosition);	//get cursor position
	//std::cout << 'x' << temp.x << 'y' << temp.y << std::endl;
	mousePosition.x = currMousePosition.x - anchorX;		//set mousePostion
	mousePosition.y = currMousePosition.y - anchorY;
	if (sqrt((float)mousePosition.x * (float)mousePosition.x + (float)mousePosition.y * (float)mousePosition.y) > 100) //if the mouse move out of range
	{
		mousePosition = temp;		//reset to previous Position
		SetCursorPos(temp.x + anchorX , temp.y + anchorY);	//reset cursor to previous Position
	}
	return mousePosition;
}