#include <iostream>
using namespace std;
int main()
{
	int amount;
	cout << "Enter total amount (integer): ";
	cin >> amount;
	// cout << "You have " << amount << " ";
	// if(amount == 1) {
	// 	cout << "puppy";
	// }
	// else {
	// 	cout << "puppies";
	// }
	// cout << endl;
	int nickels = amount/5;
	cout << "You need " << nickels << " "
		   << (nickels == 1? "nickel" : "nickels")
		   << endl;
}