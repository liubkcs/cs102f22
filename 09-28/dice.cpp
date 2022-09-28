#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	srand(time(0));
	int sides = 20000;
	int die = 0;
	int rollCount = 0;
	// Roll repeatedly until we get a 1.
	while(die != 1) {
  	die = rand()%sides + 1;
		rollCount++;
		cout << die << endl;
	}
	cout << "Done in " << rollCount << " roll(s)\n";
}