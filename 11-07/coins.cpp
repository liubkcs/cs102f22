#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, char* argv[])
{
	time_t now = (argc > 1)? atoi(argv[1]) : time(0);	
	cout << "Seed was " << now << endl;	srand(now);
	for(unsigned i = 0; i < 5; ++i) {
		cout << (rand()%2? "H" : "T");	}
	cout << endl;
}