#include "SceneManager.h"

SceneManager::SceneManager() : currSceneID(0), nextSceneID(0) {}

SceneManager::~SceneManager() {}

void SceneManager::AddScene(Scene* newScene)
{
	if (nextSceneID != 0)
	{
		sceneStorage[nextSceneID] = newScene;
		nextSceneID = currSceneID + 1;
	}
	else
	{
		sceneStorage[currSceneID] = newScene;
		nextSceneID++;
	}
}

void SceneManager::SetNextScene(int sceneID)
{
	currSceneID = nextSceneID;
	nextSceneID++;
}

void SceneManager::sceneUpdate()
{
	sceneStorage[currSceneID]->Update(Application::m_timer.getElapsedTime());
	sceneStorage[currSceneID]->Render();
	//Swap buffers
	glfwSwapBuffers(Application::m_window);
	//Get and organize events, like keyboard and mouse input, window resizing, etc...
	glfwPollEvents();
	Application::m_timer.waitUntil(frameTime);       // Frame rate limiter. Limits each frame to a specified time in ms.   		 
}
