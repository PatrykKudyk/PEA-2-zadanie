#include <iostream>
#include "Menu.h"
#include <ctime>
#include "BranchAndBound.h"
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	srand(time(NULL));
	//Menu menu; //Tworze sobie obiektklasy menu, z którego potem steruje programem
	//menu.mainMenu();
	
	TimeMeasure pomiary;
	Graph graf;
	AnnealingSimulation annealing;
	vector<double> czasyAlgorytm;
	vector<double> drogi;
	
	graf.createGiven("ftv47.atsp", 48);

	annealing.setStop(120);
	annealing.setGraph(graf);
	ostringstream ss;
	string str = ss.str();
	for (float j = 0.98; j < 0.99; j = j + 0.002)
	{
		annealing.setCoolingCoefficient(j);
		ss << j;

		string nazwaPlikuAlgorytm = "Czasy-Graf48-" + ss.str() + ".txt";
		string nazwaPlikuDrogi = "Drogi-Graf48-" + ss.str() + ".txt";
		for (int i = 0; i < 10; i++)
		{
			annealing.simulation();
			czasyAlgorytm.push_back(annealing.getTimeBest());
			drogi.push_back(annealing.getPathCost());
		}
		pomiary.saveToFile(czasyAlgorytm, nazwaPlikuAlgorytm);
		pomiary.saveToFile(drogi, nazwaPlikuDrogi);
		czasyAlgorytm.clear();
		drogi.clear();
	}

	graf.createGiven("ftv170.atsp", 171);
	annealing.setStop(240);

	for (float j = 0.98; j < 0.991; j = j + 0.002)
	{
		annealing.setCoolingCoefficient(j);
		ss << j;
		string nazwaPlikuAlgorytm = "Czasy-Graf171-" + ss.str() + ".txt";
		string nazwaPlikuDrogi = "Drogi-Graf171-" + ss.str() + ".txt";
		for (int i = 0; i < 10; i++)
		{
			annealing.simulation();
			czasyAlgorytm.push_back(annealing.getTimeBest());
			drogi.push_back(annealing.getPathCost());
		}
		pomiary.saveToFile(czasyAlgorytm, nazwaPlikuAlgorytm);
		pomiary.saveToFile(drogi, nazwaPlikuDrogi);
		czasyAlgorytm.clear();
		drogi.clear();
	}

	graf.createGiven("rbg403.atsp", 403);
	annealing.setStop(360);

	for (float j = 0.98; j < 0.99; j = j + 0.002)
	{
		annealing.setCoolingCoefficient(j);
		ss << j;
		string nazwaPlikuAlgorytm = "Czasy-Graf171-" + ss.str() + ".txt";
		string nazwaPlikuDrogi = "Drogi-Graf171-" + ss.str() + ".txt";
		for (int i = 0; i < 10; i++)
		{
			annealing.simulation();
			czasyAlgorytm.push_back(annealing.getTimeBest());
			drogi.push_back(annealing.getPathCost());
		}
		pomiary.saveToFile(czasyAlgorytm, nazwaPlikuAlgorytm);
		pomiary.saveToFile(drogi, nazwaPlikuDrogi);
		czasyAlgorytm.clear();
		drogi.clear();
	}

	
	exit(EXIT_SUCCESS);
}
