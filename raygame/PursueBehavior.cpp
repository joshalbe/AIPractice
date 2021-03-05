#include "PursueBehavior.h"
#include "Agent.h"
#include "Actor.h"

PursueBehavior::PursueBehavior()
{
	m_target = nullptr;
	m_pursueForce = 1;
}

PursueBehavior::PursueBehavior(Actor* target, float pursueForce)
{
	m_target = target;
	m_pursueForce = pursueForce;
}

MathLibrary::Vector2 PursueBehavior::calculateForce(Agent* agent)
{
	//Find the direction to move in
	MathLibrary::Vector2 direction = MathLibrary::Vector2::normalize(m_target->getWorldPosition() - agent->getWorldPosition());
	//Scale the direction vector by the seekForce
	MathLibrary::Vector2 desiredVelocity = direction * m_pursueForce;
	//Subtract current velocity from desired velocity to find steering force
	MathLibrary::Vector2 steeringForce = desiredVelocity - agent->getVelocity();

	return steeringForce;
}

void PursueBehavior::update(Agent* agent, float deltaTime)
{
	//If the agent isn't null, calculate a new force and apply it to the agent
	if (agent)
	{
		agent->addForce(calculateForce(agent));
	}
}
