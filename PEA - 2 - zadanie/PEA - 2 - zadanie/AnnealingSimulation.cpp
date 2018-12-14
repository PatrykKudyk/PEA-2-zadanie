#include "AnnealingSimulation.h"
#include <algorithm>


AnnealingSimulation::AnnealingSimulation()
{
}


AnnealingSimulation::~AnnealingSimulation()
{
}

void AnnealingSimulation::simulation()
{
	bool whileStop = false;
	std::vector<int> permutation = getPermutation();	//inicjalizacja losowej œcie¿ki pocz¹tkowej jako wektora intów
	float temperature = startTemperature();			//obliczenie temperatury startowej
	int step = 0;		//inicjalizacja licznika kroków - pocz¹tkowo 0
	path = permutation;
	pathCost = calculatePathCost(permutation);
	do
	{
		for(int i = 0; i < temperatureChangeCoefficient; i++)
		{
			std::vector<int> neighbour = generateNeighbour(permutation);
			
		}
	} while (whileStop);
}

float AnnealingSimulation::startTemperature()
{
	
}

std::vector<int> AnnealingSimulation::getPermutation()
{
	std::vector<int> permutation;	//tworze wektor intów
	for (int i = 0; i < graph.getVertices(); i++)	
		permutation.push_back(i);					//dodaje wszystkie wierzcholki grafu do wektora
	std::random_shuffle(permutation.begin(), permutation.end());	//mieszam wszystkie wierzcho³ki
	return permutation;		//zwracam wektor z losowo pomieszanymi wierzcho³kami
}

std::vector<int> AnnealingSimulation::generateNeighbour(std::vector<int> permutation)
{
	std::vector<int> neighbour = permutation;
	int a, b;
	do
	{
		a = rand() % graph.getVertices();
		b = rand() % graph.getVertices();
	} while (a == b);
	std::swap(neighbour.at(a), neighbour.at(b));
	return neighbour;
}

int AnnealingSimulation::calculatePathCost(std::vector<int> permutation)
{
	int cost = 0;
	int currentVert = 0;
	int nextVert = permutation.at(1);
	for(int i = 0; i < permutation.size() - 1; i++)
	{
		cost += graph.getGraph()[currentVert][nextVert];
		currentVert = nextVert;
		nextVert = permutation.at(i + 2);
	}
	cost += graph.getGraph()[permutation.at(permutation.size()-1)][permutation.at(0)];
	return cost;
}

std::vector<int> AnnealingSimulation::getPath()
{
	return path;
}

void AnnealingSimulation::setPath(std::vector<int> gPath)
{
	path = gPath;
}

int AnnealingSimulation::getPathCost()
{
	return pathCost;
}

void AnnealingSimulation::setPathCost(int gPathCost)
{
	pathCost = gPathCost;
}

Graph AnnealingSimulation::getGraph()
{
	return graph;
}

void AnnealingSimulation::setGraph(Graph& givenGraph)
{
	graph.setVertices(givenGraph.getVertices());
	graph.setGraphFrag(givenGraph);
}

int AnnealingSimulation::getTemperatureChangeCoefficient()
{
	return temperatureChangeCoefficient;
}

void AnnealingSimulation::setTemperatureChangeCoefficient(int data)
{
	temperatureChangeCoefficient = data;
}

