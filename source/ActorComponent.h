#pragma once

class ActorComponent {

public:

	ActorComponent();
	~ActorComponent();

	unsigned int getComponentId() { return component_id; }
	virtual void Update(int framedelta) {};

protected:
	unsigned int component_id;
	unsigned int owner_id;

private:

	void setOwner(unsigned int id) {
		owner_id = id;
	}

};