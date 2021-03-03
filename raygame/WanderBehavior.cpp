#include "WanderBehavior.h"
#include "Agent.h"
#include "Actor.h"

WanderBehavior::WanderBehavior()
{
	m_wanderForce = 1;
}

WanderBehavior::WanderBehavior(float wanderForce)
{
	m_wanderForce = wanderForce;
}

MathLibrary::Vector2 WanderBehavior::calculateForce(Agent* agent)
{
	/*
	//Find the direction to move in
	MathLibrary::Vector2 direction = MathLibrary::Vector2::normalize
	(m_target->getWorldPosition() - agent->getWorldPosition());

	//Scale the direction vector by the seekForce
	MathLibrary::Vector2 desiredVelocity = direction * m_seekForce;

	//Subtract current velocity from desired velocity to find steering force
	MathLibrary::Vector2 steeringForce = desiredVelocity - agent->getVelocity();
	*/

	//Grab a random number
	float randomizer = rand();

	

	return MathLibrary::Vector2();
}

void WanderBehavior::update(Agent* agent, float deltaTime)
{
	//If the agent isn't null, calculate a new force and apply it to the agent
	if (agent)
	{
		agent->addForce(calculateForce(agent));
	}
}
