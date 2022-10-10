// Frequency analysis with nested loops
#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;
int main()
{
	string input;
	getline(cin, input);
	// Loop through the alphabet
	for(char letter = 'A'; letter <= 'Z'; letter++) {
		cout << letter;
		// Count occurrences of that letter.
		int count = 0;
		for(int i = 0; i < input.size(); i++) {
			if(toupper(input.at(i)) == letter) {
				count++;
			}
		}
		// Print the count of current letter
		cout << setw(4) << count;
		// Print that many asterisks to form bar graph
		for(int i = 0; i < count; i++) {
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}