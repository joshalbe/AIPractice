#pragma once
#include "Actor.h"
#include <vector>
#include <raylib.h>

class Edge;

class Node : public Actor
{
public:
	Node(int x, int y, int nodeSize);
	std::vector<Edge*> edges;
	MathLibrary::Vector2 graphPosition;
	int color = 0xFFFFFFFF;
	int size = 1;
	float gScore;
	float hScore;
	float fScore;
	bool visited;
	void draw() override;
	void update(float deltaTime) override;

};

