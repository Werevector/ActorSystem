#pragma once
#include <map>
#include "ActorComponent.h"

class Actor {

public:

	Actor(unsigned int id);
	~Actor();
	void Destroy();

	unsigned int GetActorId() {
		return actor_id;
	}

private:

	unsigned int actor_id;
	std::map<std::string, ActorComponent*> components;

};