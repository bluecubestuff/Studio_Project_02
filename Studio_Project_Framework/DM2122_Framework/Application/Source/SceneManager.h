#ifndef _SCENE_MANAGER_
#define _SCENE_MANAGER_

#include "Scene.h"
#include "Application.h"
#include <map>

using std::map;

class SceneManager
{
public:

	~SceneManager();

	void AddScene(Scene*);
	void SetNextScene(int);
	void sceneUpdate();

	static SceneManager *get_instance()
	{
		if (!only_instance)
		{
			only_instance = new SceneManager;
		}
		return only_instance;
	}

private:
	SceneManager();

	static SceneManager* only_instance;
	map <unsigned, Scene*> sceneStorage;
	int currSceneID, nextSceneID;
};

#endif