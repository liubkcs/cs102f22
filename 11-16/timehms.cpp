// Idea: Represent an interval of time
// as hours, minutes, seconds, and milliseconds.
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// This class declaration could go in
// timehms.hpp (header file).
class TimeSpan {
public:
  TimeSpan(int hours = 0,
           int minutes = 0,
           int seconds = 0,
           int millis = 0);
  void Print(ostream& out = cout) const;
  void operator*=(int);
  void operator+=(const TimeSpan&);
  void normalize();
private:
  int hours, minutes, seconds, millis;
};

// Definitions related to the class would
// go in timehms.cpp
TimeSpan::TimeSpan(int hours, int minutes,
                   int seconds, int millis)
: hours(hours), minutes(minutes),
  seconds(seconds), millis(millis)
{ }

void TimeSpan::Print(ostream& out) const
{
	out << hours << ':' 
		   << setfill('0')
		   << setw(2) << minutes << ':'
       << setw(2) << seconds << '.' 
		   << setw(3) << millis;
	// Milli means 10^{-3}, so 1,000 millis per
	// second. "0.999"
}

ostream& operator<< (ostream& out,
                     const TimeSpan& ts) 
{
	ts.Print(out);
	return out;
}

void TimeSpan::operator*=(int x)
{
  hours *= x;
	minutes *= x;
	seconds *= x;
	millis *= x;
	normalize();
}

void TimeSpan::operator+=(const TimeSpan& ts) 
{
  hours += ts.hours;
	minutes += ts.minutes;
	seconds += ts.seconds;
	millis += ts.millis;
	normalize();
}

void TimeSpan::normalize() 
{
	if(millis >= 1000) {
		seconds += millis / 1000;
		millis %= 1000;
	}
	if(seconds >= 60) {
		minutes += seconds / 60;
		seconds %= 60;
	}
	if(minutes >= 60) {
		hours += minutes / 60;
		minutes %= 60;
	}
}

// Main program (or other test code) could
// go in main.cpp. Both cpp files would
// #include "timehms.hpp"
int main() {
	TimeSpan classDur(0,25,15,700);
	cout << classDur << endl;
	classDur *= 3;
	cout << "×3 is " << classDur << endl;
  TimeSpan excessTime(0,15,50,500);
	cout << " + " << excessTime << endl;
	classDur += excessTime;
	cout << " = " << classDur << endl;
	
	
	// Or, we can print to a file.
	ofstream outfile("output.txt");
	outfile << classDur << endl;
	outfile.close();
	
	return 0;
}