#include "EvadeBehavior.h"
#include "Agent.h"
#include "Actor.h"

EvadeBehavior::EvadeBehavior()
{
	m_target = nullptr;
	m_evadeForce = 1;
}

EvadeBehavior::EvadeBehavior(Actor* target, float evadeForce)
{
	m_target = target;
	m_evadeForce = evadeForce;
}

MathLibrary::Vector2 EvadeBehavior::calculateForce(Agent* agent)
{
	//Find the direction to move in
	MathLibrary::Vector2 direction = MathLibrary::Vector2::normalize(m_target->getWorldPosition() - agent->getWorldPosition());
	//Scale the direction vector by the fleeForce
	MathLibrary::Vector2 desiredVelocity = direction * m_evadeForce;
	//Subtract desired velocity from current velocity to find steering force
	MathLibrary::Vector2 steeringForce = agent->getVelocity() - desiredVelocity;

	return steeringForce;
}

void EvadeBehavior::update(Agent* agent, float deltaTime)
{
	//If the agent isn't null, calculate a new force and apply it to the agent
	if (agent)
	{
		agent->addForce(calculateForce(agent));
	}
}
