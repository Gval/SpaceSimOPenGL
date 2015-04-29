#pragma once


#include <iostream>
#include "Vector3.h"
#include "stdafx.h"
#include "Entity.h"

#ifndef _SimpleFpsMouvementSystem
#define _SimpleFpsMouvementSystem

class MouvementSystem
{
private:
	MouvementSystem();
	~MouvementSystem();
public:
	void update(std::vector<Entity*>* children);

	static MouvementSystem& getMouvementSystem();
	static void destroyMouvementSystem();
};

#endif