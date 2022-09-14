#include <iomanip>
#include <cmath>
#include <iostream>
using namespace std;

int main() {

   /* Your code goes here */
   double gasVolume;
   double gasTemperature;
   double gasPressure;

	 cout << "Enter volume:\n";
   cin >> gasVolume;
	cout << "Enter temperature:\n";
   cin >> gasTemperature;
   
   gasPressure = gasVolume / (gasTemperature * 8.314);
   
   cout << "Gas pressure is " << fixed << setprecision(3) << gasPressure << endl;

   return 0;
}