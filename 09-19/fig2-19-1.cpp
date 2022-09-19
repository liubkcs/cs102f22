#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  int seed = time(0);
	// int seed = 1663604490;
	cout << "NOTE: random seed for this run = "
		   << seed << endl;
  srand(seed);
  cout << rand() << endl;
  cout << rand() << endl;
  cout << rand() << endl;
	double x = static_cast<double>(rand()) / RAND_MAX;
	cout << fixed <<  setprecision(rand()%1000) << x << endl;

   cout << "(RAND_MAX: " << RAND_MAX << ")" << endl;

   return 0;
}