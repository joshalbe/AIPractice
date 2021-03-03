#pragma once
#include "SteeringBehavior.h"

class WanderBehavior : public SteeringBehavior
{
public:
	WanderBehavior();
	WanderBehavior(float wanderForce = 1);

	MathLibrary::Vector2 calculateForce(Agent* agent) override;
	void update(Agent* agent, float deltaTime) override;

private:
	float m_wanderForce;

};

