#pragma once
#include <iostream>
#include <Windows.h>
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "GLU32.lib")
#include<GL/glew.h>
#include<GLFW\glfw3.h>
#include<GL\GLU.h>

#ifndef _SimpleFps_RenderSystem_
#define _SimpleFps_RenderSystem_

#include "ShaderInterface.h"
#include "VertexBuffer.h"
#include <vector>
#include "Entity.h"
#include "CameraSystem.h"

class RenderSystem
{
private:
	RenderSystem();
	~RenderSystem();

	GLFWwindow* _window;

	CameraSystem* _cameraSystem;
	Entity* _currentCamera;

public:

	Entity* getCurrentCamera();
	void setCurrentCamera(Entity* currentCamera);

	void render(std::vector<Entity*> *children);

	static RenderSystem& getRenderSystem();
	static void destroyRenderSystem();
};

#endif
