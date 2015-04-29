#include "stdafx.h"
#include "MouvementSystem.h"

MouvementSystem::MouvementSystem()
{
}


MouvementSystem::~MouvementSystem()
{
}

void MouvementSystem::update(std::vector<Entity*>* children)
{
	for (std::vector<Entity*>::iterator iterator = children->begin(); iterator != children->end(); iterator++)
	{
		Entity* entity = *iterator;
		
		entity->set_position(addVector3(entity->get_position(), entity->get_velocity()));
		entity->set_scale(addVector3(entity->get_scale(), entity->get_scaleVelocity()));
		entity->set_rotation(addVector3(entity->get_rotation(), entity->get_rotationVelocity()));
	}
}

MouvementSystem& MouvementSystem::getMouvementSystem()
{
	static MouvementSystem* mouvementSystem = NULL;

	if (mouvementSystem != NULL) {
		mouvementSystem = new MouvementSystem();
	}

	return *mouvementSystem;
}

void MouvementSystem::destroyMouvementSystem()
{
	MouvementSystem* mouvementSystem = &getMouvementSystem();
	delete mouvementSystem;
}


