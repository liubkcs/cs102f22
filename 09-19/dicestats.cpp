// dicestats: Count how many
// times we roll "snake eyes"
// (two ones).
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	srand(time(0));
	int uniformSnakeEyes = 0;
	int normalSnakeEyes = 0;
	for(int i = 0; i < 10000; i++) {		
		int uniformRoll = rand()%11+2;
		int normalRoll =
		      rand()%6+1 + rand()%6+1;
		// cout << uniformRoll << endl;
		if(uniformRoll == 2) {
			uniformSnakeEyes++;
			// cout << "[uniform] snake eyes\n";
		}
		// cout << normalRoll << endl;
		if(normalRoll == 2) {
			normalSnakeEyes++;
			// cout << "[normal] snake eyes\n";
		}
	}
	cout << "Uniform: " << uniformSnakeEyes
		   << endl;
	cout << "Normal: " << normalSnakeEyes
			 << endl;

}