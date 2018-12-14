#include "AnnealingSimulation.h"
#include <algorithm>
//#include <iostream>


AnnealingSimulation::AnnealingSimulation()
{
	startTemperature = 10;
}

AnnealingSimulation::~AnnealingSimulation()
{
}

void AnnealingSimulation::simulation()
{
	//bool whileStop = false;
	std::vector<int> permutation = getPermutation();	//inicjalizacja losowej œcie¿ki pocz¹tkowej jako wektora intów
	float temperature = static_cast<float>(startTemperature);			//obliczenie temperatury startowej
	//int step = 0;		//inicjalizacja licznika kroków - pocz¹tkowo 0
	std::vector<int> bestPath = permutation;
	int minimalCost = calculatePathCost(permutation);
	do
	{
		
		for(int i = 0; i < graph.getVertices(); i++)
		{
			std::vector<int> neighbour = generateNeighbour(permutation);
			int currentCost = calculatePathCost(neighbour);
			if (currentCost <= minimalCost)
			{
				permutation = neighbour;
				minimalCost = currentCost;
			}
			else if(exp(minimalCost-currentCost)/temperature > 0.4747)
			{
				permutation = neighbour;
				minimalCost = currentCost;
			}
		}
		temperature = temperature*coolingCoefficient;
		//step++;
	} while (temperature > 0.1);
//	std::cout << step << std::endl;
	//std::cin.get();
	path = permutation;
	pathCost = minimalCost;
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
	for(int i = 0; i < permutation.size() - 1; i++)
	{
		int currentVert = permutation.at(i);
		int nextVert = permutation.at(i + 1);
		cost += graph.getGraph()[currentVert][nextVert];
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

int AnnealingSimulation::getAcceptationCoefficient()
{
	return acceptationCoefficient;
}

void AnnealingSimulation::setAcceptationCoefficient(int data)
{
	acceptationCoefficient = data;
}

float AnnealingSimulation::getCoolingCoefficient()
{
	return coolingCoefficient;
}

void AnnealingSimulation::setCoolingCoefficient(float data)
{
	coolingCoefficient = data;
}

