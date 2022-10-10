#include <iostream>
using namespace std;
int main()
{
	string first, last;
	int year;
	cin >> first >> last >> year;
	//  first five letters of the last name, followed by the first letter of the first name, and then the last two digits of the number (use the % operator). If the last name has less than five letters, then use all letters of the last name.
	cout << "Your login name: "
		<< last.substr(0,5)
		<< first.at(0)
		<< year%100 << endl;
}