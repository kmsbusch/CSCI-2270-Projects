#include "Graph.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


void Graph::addVertex(string name)
{
	bool found = false;
	for (int i = 0; i < vertices.size(); i++)
	{
		if (vertices[i]->name == name)
		{
			found = true;
		}
	}
	if (found == false)
	{
		vertex *v = new vertex;
		v->name = name;
		//addEdge(vertices.back(), v->name);
		vertices.push_back(v);
	}
}

void Graph::addEdge(string v1, string v2, int num) //not sure if this is done yet
{
	for (int i = 0; i < vertices.size(); i++)
	{
		if (vertices[i]->name == v1)
		{
			for (int j = 0; j < vertices.size(); j++)
			{
				if (vertices[j]->name == v2 && i != j)
                {
                    adjVertex av;
                    av.v = vertices[j];
					av.weight = num;
                    vertices[i]->adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = vertices[i];
					av2.weight = num;
                    vertices[j]->adj.push_back(av2);
                }
			}
		}
	}	
}

void dfsRecursive(vertex *n)
{
	n->visited = true;
	cout << n->name << " --> ";
	for (unsigned int i = 0; i < n->adj.size(); i++)
	{
		if (n->adj[i].v->visited == false)
		dfsRecursive(n->adj[i].v);
	}
}

void Graph::depthFirstTraversal(string sourceVertex)
{
	int source = 0;
	while (sourceVertex != vertices[source]->name)
	{
		source++;
	}
	vertices[source]->visited = true;
	dfsRecursive(vertices[source]);
	cout << "Done";
}



void weightRecursive(vertex *n, int weight)
{
	n->visited = true;
	cout << n->name << " ";
	for (unsigned int i = 0; i < n->adj.size(); i++)
	{
		if (n->adj[i].v->visited == false)
		{
			weightRecursive(n->adj[i].v, n->adj[i].v->distance);
		}
		if (n->distance + n->adj[i].weight < n->adj[i].v->distance)
		{
			n->adj[i].v->distance = n->distance + n->adj[i].weight; //coderunner has n->distance taken out
		}
	}
}

vertex* Graph::DijkstraAlgorithm(string start, string end)
{
	vertex *n = new vertex;
	queue<vertex *> q;
	
	for (unsigned int k = 0; k < vertices.size(); k++)
	{
		if (vertices[k]->name == start)
		{
			n = vertices[k];
			n->distance = 0;
		}
		else
		{
			vertices[k]->distance = 1000;
		}
		
	}

	// cout << "Starting vertex (root): " << n->name << "-> ";
	// n->visited = true;
	q.push(n);
	//int compare = 100;
	//int distByWeight = 0;
	//int dist = n->distance;
	while (!q.empty() && n->name != end)
	{
		n = q.front();
		q.pop();
		// go to all the adjacent vertices of n
		for (unsigned int x = 0; x < n->adj.size(); x++)
		{
			weightRecursive(n->adj[x].v, n->distance);
			// If an adjacent has not been visited, then mark it visited, set distance and enqueue it
			// if (n->adj[x].v->visited == false)
			// {

				// n->adj[x].v->visited = true;
				//n->adj[x].v->distance = av.weight;
				// cout << n->adj[x].v->name <<"("<< n->adj[x].v->distance <<")"<< " "; 
				// if (n->distance + n->adj[x].weight < n->adj[x].v->distance)
				// {
				// 	n->adj[x].v->distance = n->distance + n->adj[x].weight; //coderunner has n->distance taken out
				// }
			// }
			q.push(n->adj[x].v);
		}
		//n->visited = true;

	}
	for (unsigned int m = 0; m < vertices.size(); m++)
	{
		if (vertices[m]->name == end)
		{
			n = vertices[m];
		}
	}
	return n;
}



void Graph::shortestpath(string s1, string s2)
{
	vertex *vStart = new vertex;
	vertex *vEnd = new vertex;
	stack<vertex *> names;
	for (unsigned int i = 0; i < vertices.size(); i++)
	{
		if (vertices[i]->name == s2)
		{
			vEnd = vertices[i];
		}
	}
	vStart->pred = NULL;
	while (vEnd->pred != NULL)
	{
		names.push(vEnd);
		vEnd = vEnd->pred;
	}
	names.push(vEnd);
	string temp = "";
	while (!names.empty())
	{
		temp = names.top()->name;
		names.pop();
		cout << temp << " ";
	} 
	
}