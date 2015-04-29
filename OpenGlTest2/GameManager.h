#pragma once
#include <iostream>
#include <Windows.h>
#include<GL/glew.h>
#include <GLFW\glfw3.h>

#include "RenderSystem.h"	
#include "ResourcesManager.h"
#include "MouvementSystem.h"
#include "CameraSystem.h"
#include "Scene.h"
//#define FREEGLUT_LIB_PRAGMAS 0
//#pragma comment(lib, "freeglut.lib")
//#pragma comment(lib, "opengl32.lib")
//#include <gl/GL.h>
//#include "GL/freeglut.h"
//#include "GL/glext.h"
//#include <stdio.h>
//#include <tchar.h>


class GameManager
{
private :
	bool _running;
	RenderSystem* _render;
	ResourcesManager* _resourcesManager;
	MouvementSystem* _movementSystem;
	CameraSystem* _cameraSystem;
	GLFWwindow* _window;
	Scene* _scene;

public:
	GameManager(bool running);
	~GameManager();


	static GameManager& getGameManager();
	void runGameLoop();

	void destroyGameMangaer();
};

