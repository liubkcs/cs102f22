#include <iostream>
using namespace std;
// Enter: month day  (integers)
// Example: 3 22
// "March 22nd"   (st nd rd th)
int main()
{
	int month, day;
	cout << "Enter integers for Month Day: ";
  cin >> month;
	cin >> day;
	switch(month) {
		case 1: cout << "January"; break;
		case 2: cout << "February"; break;
		case 3: cout << "March"; break;
		case 4: cout << "April"; break;
		case 5: cout << "May"; break;
		case 6: cout << "June"; break;
		case 7: cout << "July"; break;
		case 8: cout << "August"; break;
		case 9: cout << "September"; break;
		case 10: cout << "October"; break;
		case 11: cout << "November"; break;
		case 12: cout << "December"; break;
		default: cout << "(INVALID MONTH)";
	}
	cout << " " << day;
  switch(day) {
		case 1:
		case 21:
		case 31:
		  cout << "st";
		  break;
		case 2:
		case 22:
		  cout << "nd";
		  break;
		case 3:
		case 23:
		  cout << "rd";
		  break;
		default:
			cout << "th";
	}	
	cout << endl;
}








