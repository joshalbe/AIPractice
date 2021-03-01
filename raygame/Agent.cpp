#include "Agent.h"

Agent::Agent() : Actor()
{
	m_force = { 0, 0 };
	m_maxForce = 1;

}

Agent::~Agent()
{
	
}

Agent::Agent(float x, float y, float collisionRadius, char icon, float maxSpeed, float maxForce) : 
	Actor(x, y, collisionRadius, icon, maxSpeed)
{
	m_maxForce = maxForce;
}

Agent::Agent(float x, float y, float collisionRadius, Sprite* sprite, float maxSpeed, float maxForce) :
	Actor(x, y, collisionRadius, sprite, maxSpeed)
{
	m_maxForce = maxForce;
}

Agent::Agent(float x, float y, float collisionRadius, const char* spriteFilePath, float maxSpeed, float maxForce) : 
	Actor(x, y, collisionRadius, spriteFilePath, maxSpeed)
{
	m_maxForce = maxForce;
}

void Agent::update(float deltaTime)
{
	//Reset force to be zero
	m_force = { 0, 0 };

	//TO DO: Update forces


	//Updates velocity with the new force
	setVelocity(getVelocity() + m_force * deltaTime);

	Actor::update(deltaTime);
}

void Agent::addForce(MathLibrary::Vector2 force)
{
	m_force = m_force + force;
	
	//if the total force is greater than the max force
	if (m_force.getMagnitude() > getMaxForce())
	{
		//set its magnitude to be the max force
		m_force = m_force.getNormalized() * getMaxForce();
	}
}