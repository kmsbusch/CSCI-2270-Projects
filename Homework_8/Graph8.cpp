#include "Graph.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
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

void Graph::addEdge(string v1, string v2)
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
                    vertices[i]->adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = vertices[i];
                    vertices[j]->adj.push_back(av2);
                }
			}
		}
	}	
}

void Graph::displayEdges() //no idea if this works or is really finished
{
	for (unsigned int i = 0; i < vertices.size(); i++)
	{
		cout << vertices[i]->name << " --> ";
		for (unsigned int j = 0; j < vertices[i]->adj.size(); j++)
		{
			cout << vertices[i]->adj[j].v->name << " ";
		}
		cout << endl;
	}
}


void Graph::breadthFirstTraverse(string sourceVertex)
{
	vertex *n = new vertex;
	queue<vertex *> q;
	
	for (unsigned int k = 0; k < vertices.size(); k++)
	{
		if (vertices[k]->name == sourceVertex)
		{
			n = vertices[k];
		}
	}

	cout << "Starting vertex (root): " << n->name << "-> ";
	n->visited = true;
	q.push(n);
	
	while (!q.empty())
	{
		n = q.front();
		q.pop();
		// go to all the adjacent vertices of n
		for (unsigned int x = 0; x < n->adj.size(); x++)
		{
			// If an adjacent has not been visited, then mark it visited, set distance and enqueue it
			if (n->adj[x].v->visited == false)
			{
				n->adj[x].v->visited = true;
				n->adj[x].v->distance = n->distance + 1;
				cout << n->adj[x].v->name <<"("<< n->adj[x].v->distance <<")"<< " "; 
				q.push(n->adj[x].v);
			}
		}
	}
}

/*
void Graph::breadthFirstTraverse(string sourceVertex)
{
	int dist = 0;
	vertex *n = new vertex;
	queue<vertex *> q;
	
	for (unsigned int k = 0; k < vertices.size(); k++)
	{
		if (vertices[k]->name == sourceVertex)
		{
			n = vertices[k];
			
		}
	}
	cout << "Starting vertex (root): " << n->name << "-> ";
	// for(unsigned int i = 0; i < vertices.size(); i++)
	// {
	//     n = vertices[i];
	//     //cout << n->name << endl;
	//     q.push(n);
	// }
	q.push(n);
    // Use the queue to keep track of visited vertices
	//q.pop();

	while (!q.empty())
	{
		n = q.front();
		n->distance = dist;
		n->visited = true;
		q.pop();
		
		// go to all the adjacent vertices of n
		for (unsigned int x = 0; x < n->adj.size(); x++)
		{
			// If an adjacent has not been visited, then mark it visited, set distance and enqueue it
			if (n->adj[x].v->visited == false)
			{
			    //cout << x << " test ";
				n->adj[x].v->visited = true;
				n->adj[x].v->distance = n->distance + 1;
                cout << n->adj[x].v->name <<"("<< n->adj[x].v->distance <<")"<< " "; 
				q.push(n->adj[x].v);
			}
		}
		dist++;
	}
}
*/



int Graph::getConnectedComponents()
{
	vertex *n = new vertex;
	queue<vertex *> q;
	for (unsigned int i = 0; i < vertices.size(); i++)
	{
		n = vertices[i];
		n->visited = false;
	}

	int counter = 0;
	bool done = false;
	
	while (!done)
	{
		for (unsigned int k = 0; k < vertices.size(); k++)
		{
			if (vertices[k]->visited == false)
			{
				counter++;
				n = vertices[k];
				break;
			}
			if (k == vertices.size() - 1)
			{
				done = true;
			}
		}
		n->visited = true;
		q.push(n);
		
		while (!q.empty())
		{
			n = q.front();
			q.pop();
			// go to all the adjacent vertices of n
			for (unsigned int x = 0; x < n->adj.size(); x++)
			{
				// If an adjacent has not been visited, then mark it visited, set distance and enqueue it
				if (n->adj[x].v->visited == false)
				{
					n->adj[x].v->visited = true;
					n->adj[x].v->distance = n->distance + 1;
					q.push(n->adj[x].v);
				}
			}
		}
	}
	return counter;		

}

//cout << vertices[k]->name << " visited = " << vertices[k]->visited << endl;
				//cout << n->name << "->visited = " << n->visited << endl;
				        //cout << n->name <<"'s color = " << n->color << endl;
				        //cout << n->adj[x].v->name << "'s color = " << n->adj[x].v->color << endl;
					    //cout << n->adj[x].v->name << " = " << n->adj[x].v->visited << endl;
					    //cout << "here" << endl;
				        //cout << n->name <<"'s color = " << n->color << endl;
				        //cout << n->adj[x].v->name << "'s color = " << n->adj[x].v->color << endl;

bool Graph::checkBipartite()
{
	vertex *n = new vertex;
	queue<vertex *> q;
	bool done = false;

	while(!done)
	{
		for(unsigned int k = 0; k < vertices.size(); k++) //for every vertex
		{
			if(vertices[k]->visited == false) //find an unvisited vertex
			{
				n = vertices[k];
				break;
			}
			if(k == vertices.size() - 1)
			{
				done = true;
			}
		}
		if(!done)
		{
			n->color = "Green"; //this should only run for root vertex of each tree
			n->visited = true; //been visited
			q.push(n); //queue

			while(!q.empty()) //BFT starts here
			{
				n = q.front(); 
				q.pop();
				// go to all the adjacent vertices of n
				for(unsigned int x = 0; x < n->adj.size(); x++) //for every adj vertex
				{
					// If an adjacent has not been visited, then mark it visited, set distance and enqueue it
					if(n->adj[x].v->color == "")
					{
						if(n->color != "Green")
						{
							n->adj[x].v->color = "Green";
							n->adj[x].v->visited = true;
							q.push(n->adj[x].v);
						}
						if(n->color != "Red")
						{
							n->adj[x].v->color = "Red";	
							n->adj[x].v->visited = true;
							q.push(n->adj[x].v);
						}
					}
					else
					{
						if (n->color == n->adj[x].v->color)
						{
							return false;
						}
					}
				}
			}			
		}
	}
	return true;
}



