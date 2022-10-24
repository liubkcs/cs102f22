#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string input;
	getline(cin, input);
	// Transfer input to output, one char at a time.
	for(unsigned i = 0; i < input.size(); ++i) {
		if(isalpha(input.at(i))) {
	  	cout << input.at(i);		
		}
	}
	cout << endl;
	// ALTERNATIVE: manipulate string
	// by working backwards
  for(int i = input.size()-1; i >= 0; --i) {
		if(!isalpha(input.at(i))) {
			input.erase(i,1);
		}
	}
	
	// Then just print the string as-is.
	cout << input << endl;

	
}