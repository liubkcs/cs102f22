#include <iostream>
using namespace std;
int main() {
 int month;
 if(month >= 1 && month <= 12)
 {} // Month is valid.
   
 if(month > 0 && month < 13)
 {}// Month is valid.
   // (Same, but prefer previous)

	// What's the OPPOSITE of
	// "month >= 1": month<1
	// Opposite of x>1 is x<=1

	// Instead, detect an INVALID month.
	if(!(month >= 1 && month <= 12))
  {} // Month is invalid.
	
	// Apply DeMorgan's Law
	if(!(month >= 1) || !(month <= 12))
	{} // Month is invalid

	// Same as
	if(month < 1 || month > 12) 
	{} // Month is invalid
	}