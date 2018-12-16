#include <iostream>
#include "Menu.h"
#include <ctime>
#include "BranchAndBound.h"
#include <iostream>

using namespace std;

int main()
{
	srand(time(NULL));
	Menu menu; //Tworze sobie obiektklasy menu, z którego potem steruje programem
	menu.mainMenu();
	
	/*TimeMeasure pomiary;
	Graph graf;
	std::vector<double>czasyBrute;
	std::vector<double>czasyBranch;

	int N = 6;
	for (int i = 0; i < 100; i++)
	{
	graf.createGiven("daneDoTestow.txt");
	brute.setGraph(graf);
	branch.setGraph(graf);
	pomiary.startCounting();
	brute.calculatingPath(0);
	czasyBrute.push_back(pomiary.getCounter());
	pomiary.startCounting();
	branch.calculatingPath(0);
	czasyBranch.push_back(pomiary.getCounter());
	cout << N << " - Wielkosc    " << i << " - Zrobione" << endl;
	}
	pomiary.saveToFile(czasyBrute, "bruteForce6.txt");
	pomiary.saveToFile(czasyBranch, "branchAndBound6.txt");
	czasyBrute.clear();
	czasyBranch.clear();
	*/

	exit(EXIT_SUCCESS);
}
