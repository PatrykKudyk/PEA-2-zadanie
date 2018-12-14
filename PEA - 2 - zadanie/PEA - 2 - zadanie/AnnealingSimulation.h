#pragma once
#include "Graph.h"
#include <vector>

class AnnealingSimulation
{
	Graph graph;		//graf oraz jego wielkosc (czyli liczba wierzcholkow)
	std::vector<int> path;	//vector, który przechowuje kolejne wierzcholki po ktorych przechodzi algorytm
	int pathCost;	//zmienna, ktora przechowuje najnizszy koszt
	int temperatureChangeCoefficient;		//wspolczynnik wyzarzania okreslajacy szybkosc zmniejszania sie temperatury
public:
	AnnealingSimulation();
	~AnnealingSimulation();
	void simulation();
	std::vector<int> getPath();
	void setPath(std::vector<int> gPath);
	int getPathCost();
	void setPathCost(int gPathCost);
	Graph getGraph();
	void setGraph(Graph &givenGraph);	
	int getTemperatureChangeCoefficient();
	void setTemperatureChangeCoefficient(int data);
};

