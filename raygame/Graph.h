#pragma once
#include "Actor.h"
#include <vector>
class Node;

class Graph : public Actor
{
public:
	Graph(int width, int height, int nodeSize, int nodeSpacing);
	void draw() override;
	void update(float deltaTime) override;

	void BFS(int startX, int startY, int goalX, int goalY);

	Node* getNode(int xPos, int yPos);

	void dijkstras(int startX, int startY, int goalX, int goalY);
	void aStar(int startX, int startY, int goalX, int goalY);

private:
	void createGraph(int nodeSize, int nodeSpacing);

private:
	int m_height;
	int m_width;
	std::vector<Node*> m_nodes;
 
};

