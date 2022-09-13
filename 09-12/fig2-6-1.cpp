#include <iostream>
using namespace std;

int main() {
  int userAgeYears;
  int userAgeDays;
   
  cout << "Enter your age in years: ";
  cin  >> userAgeYears;
   
  userAgeDays = userAgeYears * 365;

  // Account for leap years
  userAgeDays += userAgeYears / 4;
   
  cout << "You are " << userAgeDays << " days old." << endl;
   
   return 0;
}
