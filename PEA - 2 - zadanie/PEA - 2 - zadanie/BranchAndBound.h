#pragma once
#include <vector>
#include "Graph.h"



struct bAndB		//struktura przechowujaca wyniki redukcji oraz umozliwiajaca sprawne przeprowadzenie algorytmu
{
	int vertexNumber;		//numer aktualnie sprawdzanego wierzcholka
	long int **graph;		//graf przechowywany w danej chwili
	int reduction;			//chwilowy koszt przejscia do danego wierzcholka po wczesniejszej sciezce
	bool *visited;			//tablica przechowujaca liste odwiedzonych wierzcholkow
	std::vector<int> path;	//wektor przechowujacy kolejne wierzcholki w drodze
};

class BranchAndBound
{
	Graph graph;		//graf oraz jego wielkosc (czyli liczba wierzcholkow)
	std::vector<int> path;	//vector, który przechowuje kolejne wierzcholki po ktorych przechodzi algorytm
	int pathCost;	//zmienna, ktora przechowuje najnizszy koszt

public:
	BranchAndBound();
	~BranchAndBound();
	bool compareByCost(const bAndB &a, const bAndB &b);
	void calculatingPath(int startVert);
	bAndB matrixStartReduction(long** graph, int verticles, int startVert);
	long int** copyGraph(long**graph, int size);
	bool* copyVisited(bool*visited, int size);
	bAndB reducing(bAndB given, int startVert, int endVert, int firstVertex);
	bool isVisitedLeft(bool* visited, int size);
	std::vector<int> getPath();
	void setPath(std::vector<int> gPath);
	int getPathCost();
	void setPathCost(int gPathCost);
	Graph getGraph();
	void setGraph(Graph &givenGraph);
};

