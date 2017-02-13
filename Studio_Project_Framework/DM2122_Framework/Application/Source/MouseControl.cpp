#include "MouseControl.h"

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