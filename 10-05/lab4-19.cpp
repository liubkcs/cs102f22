#include <iostream>
using namespace std;
int main()
{
	string input;
	getline(cin, input);
	while(!(input == "done" || input == "d")) {
		// In the real solution, we'd need a NESTED
		// for loop here to print the input backwards.
		cout << "Repeat: " << input << endl;
		getline(cin, input);
	}
}