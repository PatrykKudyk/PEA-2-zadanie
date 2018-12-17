#include <iostream>
#include "Menu.h"
#include <ctime>
#include <iostream>
#include <sstream>

using namespace std;

TimeMeasure pomiary;
Graph graf;
AnnealingSimulation annealing;
vector<double> czasyAlgorytm;
vector<double> drogi;
vector<double> temperatury;

void testy(float j, int time, int wierzcholki);

int main()
{
	srand(time(NULL));
	//Menu menu; //Tworze sobie obiektklasy menu, z którego potem steruje programem
	//menu.mainMenu();

	graf.createGiven("ftv47.atsp", 48);
	annealing.setGraph(graf);
	annealing.setTempStart(10);
	for(int i = 1; i <= 5 ; i++)
	{
		testy(0.95, pow(2, i), 48);
		testy(0.98, pow(2, i), 48);
		testy(0.998, pow(2, i), 48);
		testy(0.9998, pow(2, i), 48);
		testy(0.99998, pow(2, i), 48);
	}


	//annealing.setTempStart(10);


	graf.createGiven("ftv170.atsp", 171);
	annealing.setGraph(graf);
	annealing.setTempStart(4);
	for (int i = 1; i <= 5; i++)
	{
		testy(0.95, pow(2, i), 171);
		testy(0.98, pow(2, i), 171);
		testy(0.998, pow(2, i), 171);
		testy(0.9998, pow(2, i), 171);
		testy(0.99998, pow(2, i), 171);
	}


	graf.createGiven("rbg403.atsp", 403);
	annealing.setGraph(graf);
	annealing.setTempStart(10);
	for (int i = 1; i <= 5; i++)
	{
		testy(0.95, pow(2, i), 403);
		testy(0.98, pow(2, i), 403);
		testy(0.998, pow(2, i), 403);
		testy(0.9998, pow(2, i), 403);
		testy(0.99998, pow(2, i), 403);
	}


	/*
	graf.createGiven("ftv170.atsp", 171);
	annealing.setStop(240);
	annealing.setGraph(graf);
	annealing.setTempStart(4);
	for (float j = 0.995; j < 0.9999; j = j + 0.0005) 
	{
		annealing.setCoolingCoefficient(j);
		ostringstream ss;
		ss << j;
		string nazwaPlikuAlgorytm = "Czasy-Graf171-" + ss.str() + ".txt";
		string nazwaPlikuDrogi = "Drogi-Graf171-" + ss.str() + ".txt";
		for (int i = 0; i < 10; i++)
		{
			annealing.simulation();
			czasyAlgorytm.push_back(annealing.getTimeBest());
			drogi.push_back(annealing.getPathCost());
			cout << "Policzone dla Grafu 171 wierzcholkow. Chlodzenie: " << j << "		Podejscie " << i << endl;
		}
		pomiary.saveToFile(czasyAlgorytm, nazwaPlikuAlgorytm);
		pomiary.saveToFile(drogi, nazwaPlikuDrogi);
		czasyAlgorytm.clear();
		drogi.clear();
	}

	graf.createGiven("rbg403.atsp", 403);
	annealing.setStop(360);
	annealing.setGraph(graf);
	annealing.setTempStart(10);
	for (float j = 0.995; j < 0.9999; j = j + 0.0005) 
	{
		annealing.setCoolingCoefficient(j);
		ostringstream ss; 
		ss << j;
		string nazwaPlikuAlgorytm = "Czasy-Graf403-" + ss.str() + ".txt";
		string nazwaPlikuDrogi = "Drogi-Graf403-" + ss.str() + ".txt";
		for (int i = 0; i < 10; i++)
		{
			annealing.simulation();
			czasyAlgorytm.push_back(annealing.getTimeBest());
			drogi.push_back(annealing.getPathCost());
			cout << "Policzone dla Grafu 403 wierzcholkow. Chlodzenie: " << j << "		Podejscie " << i << endl;
		}
		pomiary.saveToFile(czasyAlgorytm, nazwaPlikuAlgorytm);
		pomiary.saveToFile(drogi, nazwaPlikuDrogi);
		czasyAlgorytm.clear();
		drogi.clear();
	}

	*/
	exit(EXIT_SUCCESS);
}


void testy(float j, int time, int wierzcholki)
{
	annealing.setStop(time);
	annealing.setCoolingCoefficient(j);
	ostringstream ss, ss1,ss2;
	ss << j;
	ss1 << wierzcholki;
	ss2 << time;
	string nazwaPlikuAlgorytm = "Czasy-Graf" + ss1.str() + "-" + ss.str() + "-Czas" + ss2.str() + ".txt";
	string nazwaPlikuDrogi = "Drogi-Graf" + ss1.str() + "-" + ss.str() + "-Czas" + ss2.str() + ".txt";
	string nazwaPlikuTemperatury = "Temperatury-Graf" + ss1.str() + "-" + ss.str() + "-Czas" + ss2.str() + ".txt";
	for (int i = 0; i < 10; i++)
	{
		annealing.simulation();
		czasyAlgorytm.push_back(annealing.getTimeBest());
		drogi.push_back(annealing.getPathCost());
		temperatury.push_back(annealing.getTempEnd());
		cout << "Policzone dla Grafu "<< wierzcholki <<" wierzcholkow. Chlodzenie: " << j << "		Podejscie " << i << endl
			<< "\t\tWyniki: koszt - " << annealing.getPathCost() << "   czas - " << annealing.getTimeBest() << "   temperatura koncowa - " << annealing.getTempEnd() << endl;
	}
	pomiary.saveToFile(czasyAlgorytm, nazwaPlikuAlgorytm);
	pomiary.saveToFile(drogi, nazwaPlikuDrogi);
	pomiary.saveToFile(temperatury, nazwaPlikuTemperatury);
	czasyAlgorytm.clear();
	drogi.clear();
	temperatury.clear();
}
