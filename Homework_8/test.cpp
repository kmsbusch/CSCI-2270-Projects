#include "Graph.hpp"
#include<vector>
#include<iostream>
using namespace std;

int main()
{
	Graph graph;
	graph.addVertex("Boulder");
	graph.addVertex("Denver");
	graph.addVertex("Cheyenne");
	graph.addVertex("Fruita");
	graph.addVertex("Moab");
	graph.addVertex("Longmont");
	graph.addVertex("London");
	graph.addVertex("Paris");


	graph.addEdge("Boulder", "Denver");
	graph.addEdge("Boulder", "Cheyenne");
	// graph.addEdge("Denver", "Boulder");
	graph.addEdge("Denver", "Fruita");
	//graph.addEdge("Cheyenne", "Moab");
	graph.addEdge("Longmont", "Moab");
	
	graph.addEdge("London", "Paris");

		
	bool bipartite = graph.checkBipartite();
	cout << bipartite << endl;
}