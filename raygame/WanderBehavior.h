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
	float m_angleChange = 0;
	float m_circleDistance = 0;
	float m_circleRadius = 0;
	float m_wanderAngle = 1;
	float m_wanderForce = 1;

	MathLibrary::Vector2 m_target;
	//MathLibrary::Vector2
};

