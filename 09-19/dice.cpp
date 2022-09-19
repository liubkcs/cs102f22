#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// 2 = (1,1)
// 3 = (1,2) (2,1)
// 4 = (1,3) (2,2) (3,1)
// 5 = (1,4) (2,3) (3,2) (4,1)
// 6
// 7
// 8
// 9
//10
//11
//12

int main()
{
	srand(time(0));
	// Simulate rolling 2 dice
	// and taking the sum.
	// Final range can be 2-12.
	cout << (rand()%6+1)+(rand()%6+1) << endl;
	cout << (rand()%6+1)+(rand()%6+1) << endl;
	cout << (rand()%6+1)+(rand()%6+1) << endl;
	cout << (rand()%6+1)+(rand()%6+1) << endl;
	cout << (rand()%6+1)+(rand()%6+1) << endl;
	cout << (rand()%6+1)+(rand()%6+1) << endl;
	cout << (rand()%6+1)+(rand()%6+1) << endl;
	cout << (rand()%6+1)+(rand()%6+1) << endl;
	cout << (rand()%6+1)+(rand()%6+1) << endl;
	cout << (rand()%6+1)+(rand()%6+1) << endl;
	
}