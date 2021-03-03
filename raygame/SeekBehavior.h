#pragma once
#include "SteeringBehavior.h"

class SeekBehavior : public SteeringBehavior
{
public:
	SeekBehavior();
	SeekBehavior(Agent* target, float seekForce);

	Agent* getTarget() { return m_target; }
	void setTarget(Agent* target) { m_target = target; }
	
	MathLibrary::Vector2 calculateForce(Agent* agent) override;
	void update(Agent* agent, float deltaTime) override;

private:
	//The agent the behavior is seeking
	Agent* m_target;
	float m_seekForce;

};

