#pragma once
#include "Graph.h"
#include <vector>

class AnnealingSimulation
{
	Graph graph;		//graf oraz jego wielkosc (czyli liczba wierzcholkow)
	std::vector<int> path;	//vector, który przechowuje kolejne wierzcholki po ktorych przechodzi algorytm
	int pathCost;	//zmienna, ktora przechowuje najnizszy koszt
	int acceptationCoefficient;		//wspolczynnik wyzarzania okreslajacy szybkosc zmniejszania sie temperatury
	int startTemperature;
	float coolingCoefficient;
public:
	AnnealingSimulation();
	~AnnealingSimulation();
	void simulation();
	std::vector<int> getPermutation();
	std::vector<int> generateNeighbour(std::vector<int> permutation);
	int calculatePathCost(std::vector<int> permutation);
	std::vector<int> getPath();
	void setPath(std::vector<int> gPath);
	int getPathCost();
	void setPathCost(int gPathCost);
	Graph getGraph();
	void setGraph(Graph &givenGraph);	
	int getAcceptationCoefficient();
	void setAcceptationCoefficient(int data);
	float getCoolingCoefficient();
	void setCoolingCoefficient(float data);
};

