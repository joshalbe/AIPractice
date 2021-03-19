#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#include <raylib.h>
#include <deque>

Graph::Graph(int width, int height, int nodeSize, int nodeSpacing)
{
	m_width = width;
	m_height = height;

	createGraph(nodeSize, nodeSpacing);
}

void Graph::draw()
{
	for (int i = 0; i < m_nodes.size(); i++) 
	{
		m_nodes[i]->draw();
	}
}

void Graph::update(float deltaTime)
{
	for (int i = 0; i < m_nodes.size(); i++) 
	{
		m_nodes[i]->update(deltaTime);
	}
}

void Graph::BFS(int startX, int startY, int goalX, int goalY)
{
	//Get a reference to the start and end nodes
	Node* start = getNode(startX, startY);
	Node* goal = getNode(goalX, goalY);

	//If the start or the end is null return
	if (!start || !goal)
		return;

	//Set the color to start and mark it as visited
	start->color = ColorToInt(GREEN);
	start->visited = true;

	//Set the iterator to be the start node
	Node* currentNode = start;

	//Create a queue to store the nodes
	std::deque<Node*> queue;
	//Add the start node to the queue
	queue.push_front(start);

	//Search for the goal while the queue isn't empty
	while (!queue.empty()) 
	{
		//Set the current node to be the first item in the queue
		currentNode = queue[0];
		//Remove the first item from the queue
		queue.pop_front();

		//Check if the iterator is the goal node
		if (currentNode == goal) 
		{
			//Set the current node color to be yellow to mark it as faound
			currentNode->color = ColorToInt(YELLOW);
			return;
		}

		//If the node wasn't the goal loop through its edges to get its neighbors
		for (int i = 0; i < currentNode->edges.size(); i++) 
		{
			//Create a pointer to store the node at the other end of the edge
			Node* currentEdgeEnd = nullptr;

			//Set the pointer to be the opposite end of the edge
			if (currentNode == currentNode->edges[i]->connectedNode2)
			{
				currentEdgeEnd = currentNode->edges[i]->connectedNode1;
			}
			else
			{
				currentEdgeEnd = currentEdgeEnd->edges[i]->connectedNode2;
			}

			//If the node at tha opposite hasn't been visited, mark it as visited and add it to the queue
			if (!currentEdgeEnd->visited)
			{
				currentEdgeEnd->color = ColorToInt(RED);
				currentEdgeEnd->visited = true;
				queue.push_back(currentEdgeEnd);
			}
		}
	}
}

Node* Graph::getNode(int xPos, int yPos)
{
	if (xPos < 0 || xPos > m_width || yPos < 0 || yPos > m_height)
		return nullptr;

	for (int i = 0; i < m_nodes.size(); i++) 
	{
		if (m_nodes[i]->graphPosition == MathLibrary::Vector2(xPos, yPos))
			return m_nodes[i];
	}

	return nullptr;
}

void Graph::dijkstras(int startX, int startY, int goalX, int goalY)
{
	//Create a node pointer that points to the start node
	//Create a node pointer that points to the goal node

	Node* start = getNode(startX, startY);
	Node* goal = getNode(goalX, goalY);

	//Check if the start or the goal pointer is null
		//return an empty list
	//end if statement

	if (!start || !goal)
		return;

	//Set the start nodes color to be green

	start->color = ColorToInt(GREEN);

	//Create a node pointer that will be act as an iterator for the graph
	//Create an open list
	//Create a closed list

	Node* currentNode = start;
	std::deque<Node*> open;
	std::deque<Node*> closed;

	//Add start to the open list

	open.push_front(start);

	//Loop while the open list is not empty

	while (open.size() > 0)
	{
		//Sort the items in the open list by the g score



		//Set the iterator to be the first item in the open list

		currentNode = open[0];

		//Check if the iterator is pointing to the goal node

		if (currentNode == goal)
		{
			//Mark the goal as being found by changing its color

			//Return the new path found

			currentNode->color = ColorToInt(GREEN);

			//return currentNode;
		}
		//end if statement


		//Pop the first item off the open list

		open.pop_front();

		//Add the first item to the closed list

		closed.push_front(currentNode);

		//Loop through all of the edges for the iterator

		for (int i = 0; i < open.size(); i++)
		{
			//Create a node pointer to store the other end of the edge

			//Check if the iterator is on the second end of the node
				//Set the edge end pointer to be the first end of the node
			//Otherwise if the iterator is on the first end of the node...
				//set the edge end pointer to be the second end of the node
			// end if statement

			//Check if node at the end of the edge is in the closed list

				//Create an int and set it to be the g score of the iterator plus the cost of the edge


				//Check if the node at the end ofthe edge is in the open list

					//Mark the node as visited by changing its color
					//Set the nodes g score to be the g score calculated earlier
					//Set the nodes previous to be the iterator
					//Add the node to the open list

				//Otherwise if the g score is less than the node at the end of the edge's g score...

					//Mark the node as visited by changing its color
					//Set its g score to be the g score calculated earlier
					//Set its previous to be the current node

				//end if statement
		}
		//end loop
	}

	//end loop
}

void Graph::aStar(int startX, int startY, int goalX, int goalY)
{
	//Create a node pointer that points to the start node
	Node* start = getNode(startX, startY);
	//Create a node pointer that points to the goal node
	Node* goal = getNode(goalX, goalY);

	//Check if the start or the goal pointer is null
		//return an empty list
	//end if statement

	if (!start || !goal)
	{
		return;
	}

	//Set the start nodes color to be green

	start->color = ColorToInt(GREEN);

	//Create a node pointer that will act as an iterator for the graph
	//Create an open list
	//Create a closed list

	Node* currentNode = start;
	std::deque<Node*> open;
	std::deque<Node*> closed;

	//Add start to the open list

	open.push_front(start);

	//Loop while the open list is not empty

	while (open.size() > 0)
	{
		//Sort the items in the open list by the f score

		//Set the iterator to be the first item in the open list

		//Check if the iterator is pointing to the goal node

			//Mark the goal as being found by changing its color
			//Return the new path found

		//end if statement

		//Pop the first item off the open list
		//Add the first item to the closed list

		//Loop through all of the edges for the iterator

			//Create a node pointer to store the other end of the edge

			//Check if the iterator is on the second end of the node
				//Set the edge end pointer to be the first end of the node
			//Otherwise if the iterator is on the first end of the node...
				//set the edge end pointer to be the second end of the node
			// end if statement

			//Check if node at the end of the edge is in the closed list

				//Create a float and set it to be the g score of the iterator plus the cost of the edge
				//Create a float and set it to be the h score of the node at the end of the edge
				//Create a float for the f score and set it to be the g score combined with the h score

				//Check if the node at the end of the edge is in the open list

					//Mark the node as visited by changing its color
					//Set the nodes g score to be the g score calculated earlier
					//Set the nodes h score to be the h score calculated earlier
					//Set the nodes f score to be the f score calculated earlier
					//Set the nodes previous to be the iterator
					//Add the node to the open list

				//Otherwise if the f score is less than the node at the end of the edge's f score...

					//Mark the node as visited by changing its color
					//Set its g score to be the g score calculated earlier
					//Set the nodes h score to be the h score calculated earlier
					//Set its f score to be the f score calculated earlier
					//Set its previous to be the current node

				//end if statement
		//end loop
	}
	//end loop
}

void Graph::createGraph(int nodeSize, int nodeSpacing)
{
	float xPos = 0;
	float yPos = 0;

	//Loops for the amount of nodes in the graph
	for (int i = 0; i < m_width * m_height; i++) 
	{
		//Create a new node with the current graph position and size
		Node* currentNode = new Node(xPos, yPos, nodeSize);

		//Set the local offset for the current node
		MathLibrary::Vector2 nodeLocalPosition = { xPos * nodeSpacing, yPos * nodeSpacing };
		currentNode->setLocalPosition(nodeLocalPosition);

		//Add the node as a child of the grid and update the list
		addChild(currentNode);
		m_nodes.push_back(currentNode);

		//Connect the node to all nodes in range
		for (int j = 0; j < m_nodes.size(); j++) 
		{
			//Find the displacement between the current node being added and the node being evaluated
			MathLibrary::Vector2 displacement = m_nodes[j]->graphPosition - currentNode->graphPosition;

			//Check if the magnitude of the displacement is farther than the maximum
			if (displacement.getMagnitude() <= 1.42 && displacement.getMagnitude > 0) 
			{
				Edge* currentEdge = new Edge(m_nodes[j], currentNode);
				currentNode->edges.push_back(currentEdge);
				m_nodes[j]->edges.push_back(currentEdge);
			}
		}

		//Increase the graph position on the x
		xPos++;

		//If the x position is greater than the width, reset it to 0 and increase the y
		if (xPos >= m_width) 
		{
			xPos;
			yPos++;
		}
	}
}
