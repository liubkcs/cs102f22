#include <iostream>
#include <string>
using namespace std;
int main()
{
	cout << "Would you like to order? (y/N)\n";
	string response;
	getline(cin, response);

	// This logic REQUIRES short-circuit eval
	// for correctness. Otherwise, the .at(0)
	// could throw out_of_range errors.
	if(response.length() > 0 &&
		 (response.at(0) == 'Y' ||
		  response.at(0) == 'y')) {
		cout << "Great, your order has been placed.\n";
	}
	else {
		cout << "Okay then, bye.\n";
	}
}