#include "Graph.hpp"
#include<vector>
#include<iostream>
using namespace std;

int main()
{
	Graph graph;
	graph.addVertex("Amsterdam");
	graph.addVertex("Broomfield");
	graph.addVertex("Calcutta");
	graph.addVertex("Fabens");
	graph.addVertex("Dallas");
	// graph.addVertex("Cheyenne");
	// graph.addVertex("London");
	// graph.addVertex("Paris");


	graph.addEdge("Amsterdam", "Broomfield", 10);
	graph.addEdge("Amsterdam", "Calcutta", 30);
	graph.addEdge("Broomfield", "Calcutta", 10);

	graph.addEdge("Broomfield", "Fabens", 50);
	graph.addEdge("Calcutta", "Dallas", 5);
		
	graph.addEdge("Fabens", "Dallas", 5);
	
	// graph.addEdge("Denver", "Fruita");

	// graph.addEdge("Longmont", "Moab");
	
	// graph.addEdge("London", "Paris");

	graph.DijkstraAlgorithm("Amsterdam", "Fabens");
}