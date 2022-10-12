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
#include <vector>
using namespace std;
int main()
{
	vector<string> dayOfWeekNames = {
			"Monday", "Tuesday", "Wednesday", 	          "Thursday", "Friday",
	 	 	"Saturday", "Sunday"
	};
	vector<string> monthNames = {
		"January", "February", "March"    ,
	  "April"  , "May"     , "June"     ,
		"July"   , "August"  , "September",
		"October", "November", "December"
	};
  time_t now = time(0);
	cout << "It is now " << now << endl;
	struct tm* tm = gmtime(&now);		
	cout << tm->tm_year+1900 << "-"
			 << tm->tm_mon+1 << "-"
			 << tm->tm_mday << " "
			 << dayOfWeekNames.at((tm->tm_wday+6)%7)			        << "\n";
	cout << monthNames.at(tm->tm_mon) << " "
			 << tm->tm_year+1900 << "\n";
	
	int day;
	int dayOfWeek = 0;
	const int size = 3; // Should support 3-7?
	for(int i = 0; i < dayOfWeekNames.size(); i++) {
		cout << setw(size) << 
			dayOfWeekNames.at(i).substr(0, 		   (size > 9)? 20 : ((size > 3)? 3 : 2)	
			);
	}
	cout << endl;
	dayOfWeek = (tm->tm_wday+6)%7;
	for(day = tm->tm_mday; day%7 != 1 ; day++) {
		dayOfWeek = (dayOfWeek+1)%7;
	}
	cout << "Month starts on "
		   << dayOfWeekNames.at(dayOfWeek)
		   << "\n";

	//  tm_mday: 12  [1-31]
	//  tm_wday:  3  [0-6, 0=Sunday]
	// So, what day of the week is the FIRST
	// day of this month?
	//   ((12 + 35) - 11) % 7
	//   (47 - 11) % 7
	//    36 % 7
	//    1
	dayOfWeek = 0;
	for(day = -4; day <= 31; ++day) {		cout << setw(size)
			   << (day < 1? "" : to_string(day))
			   << (dayOfWeek == 6? "\n" : "");		
		dayOfWeek = (dayOfWeek+1)%7;
	}
	cout << endl;
	return 0;
}