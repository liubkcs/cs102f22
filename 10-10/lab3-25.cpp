// Leap year detection
#include <iostream>
using namespace std;
int main()
{
	int inputYear;
  bool isLeapYear = false; 
	cin >> inputYear;

	// 1) The year must be divisible by 4
	// if(inputYear%4 == 0) {
	// 	isLeapYear = true;
	// 	if(inputYear%100 == 0) {
	// 		if(inputYear%400 == 0) {
	// 			isLeapYear = true;
	// 		}
	// 		else {
	// 			isLeapYear = false;
	// 		}
	// 	}
	// }

  // 2) If the year is a century year (1700, 1800, etc.), the year must be evenly divisible by 400

isLeapYear =
	inputYear%4 == 0 &&
	(inputYear%400 == 0 || inputYear%100 != 0);		
	
  cout << inputYear << " - ";
	if(isLeapYear) {
		cout << "leap year\n";
	}
	else {
		cout << "not a leap year\n";
	}

	return 0;
}