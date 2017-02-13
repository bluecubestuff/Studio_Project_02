#include "MouseControl.h"

Mouse::Mouse()
{
	glfwGetWindowSize(Application::m_window, &windowX, &windowY);	//get window size
	anchorX = windowX / 2;		//center of window
	anchorY = windowY / 2;		//center of window
	mousePosition.x = anchorX;
	mousePosition.y = anchorX;
}

Mouse::~Mouse()
{
	delete this;
}

POINT Mouse::mouseMovement()
{
	GetCursorPos(&currMousePosition);		//get cursor position
	SetCursorPos(anchorX, anchorY);			//set cursor back onto origin
	if (anchorX > currMousePosition.x)		//if cursor is leftside of center
	{
		mousePosition.x = currMousePosition.x - anchorX;
	}
	else if (anchorX < currMousePosition.x)	//if cursor is rightside of center
	{
		mousePosition.x = anchorX - currMousePosition.x;
	}
	if (anchorY < currMousePosition.y)		//if cursor is below center
	{
		mousePosition.y = currMousePosition.y - anchorY;
	}
	else if (anchorY > currMousePosition.y)	//if cursor is above center
	{
		mousePosition.y = anchorY - currMousePosition.y;
	}
	return mousePosition;
}