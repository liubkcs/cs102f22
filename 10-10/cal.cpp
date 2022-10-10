// Calendar like Unix "cal" program.
//     October 2022    
// Mo Tu We Th Fr Sa Su
//                 1  2
//  3  4  5  6  7  8  9
// 10 11 12 13 14 15 16
// 17 18 19 20 21 22 23
// 24 25 26 27 28 29 30
// 31                  
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;
int main()
{
  time_t now = time(0);
	cout << "It is now " << now << endl;
	struct tm* tm = gmtime(&now);
	cout << tm->tm_year+1900 << "-"
		   << tm->tm_mon+1 << "-"
		   << tm->tm_mday << endl;

	int day;
	int dayOfWeek = 0;
	const int size = 7; // Should support 3-7?
	if(size == 3) {
  	cout << " Mo Tu We Th Fr Sa Su\n";	
	} else {
		cout << setw(size) << "Mon"
			<< setw(size) << "Tue"
			<< setw(size) << "Wed"
			<< setw(size) << "Thu"
			<< setw(size) << "Fri"
			<< setw(size) << "Sat"
			<< setw(size) << "Sun"
			<< endl;
	}
	// for(int i = 0; i < dayOfWeek; ++i) {
	// 	cout << setw(size) << "";
	// }
	for(day = -4; day <= 31; ++day) {
		cout << setw(size)
			   << (day < 1? "" : to_string(day))
			   << (dayOfWeek == 6? "\n" : "");		
		dayOfWeek = (dayOfWeek+1)%7;
	}
	cout << endl;
	return 0;
}