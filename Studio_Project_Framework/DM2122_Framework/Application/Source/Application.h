
#ifndef APPLICATION_H
#define APPLICATION_H

#include "timer.h"

//Include GLEW
#include <GL/glew.h>

//Include GLFW
#include <GLFW/glfw3.h>

class Application
{
public:
	Application();
	~Application();
	void Init();
	void Run();
	void Exit();
	static bool IsKeyPressed(unsigned short key);
	static GLFWwindow* m_window;
	//Declare a window object

	void createScene();
	static StopWatch m_timer;

private:
	
};

static const unsigned char FPS = 60; // FPS of this game
static const unsigned int frameTime = 1000 / FPS; // time for each frame

#endif