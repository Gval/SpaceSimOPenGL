#pragma once
#include "stdafx.h"

#ifndef _SimpleFps_Scene
#define _SimpleFps_Scene

#include "Entity.h"
#include <vector>

class Scene
{
private:

	std::vector<Entity *> *children;

public:

	std::vector<Entity *> * getChildren();

	Scene();
	~Scene();
};

#endif