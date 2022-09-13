#include <iostream>
using namespace std;

/*
 This program calculates the amount of pasta to cook, given the
 number of people eating.
 
 Author: Andrea Giada
 Date:   May 30, 2017
*/

int main() {
   int numPeople;         // Number of people that will be eating
   int totalOuncesPasta;  // Total ounces of pasta to serve numPeople
   
   // Get number of people
   cout << "Enter number of people: "<<endl;
   cin >> numPeople;
   
   // Calculate and print total ounces of pasta
   totalOuncesPasta = numPeople * 3;  // Typical ounces per person
   cout << "Cook " << totalOuncesPasta << " ounces of pasta." << endl;
   
   return 0;
}
