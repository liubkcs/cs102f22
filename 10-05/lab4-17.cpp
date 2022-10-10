#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	string input;
	srand(time(0));
	getline(cin, input);
	// Easy way out: output one char at a 
	// time, and don't bother to modify the
	// string.
	for(int i = 0; i < input.size(); i++) {
		// Can do isalpha or whatever to
		// decide whether to output
		if(rand()%2 == 0) {
			cout << input.at(i);
		}
	}
	cout << endl;

  // Hard way: modify the string
	// to erase certain characters.
	//    abcdEFGhijklmnopqrstuvwxyz
	//    0123456789
	//  input.erase(4); Delete index 4 to end
	//  input.erase(4,1); Delete 1 char at idx 4
	//  input.erase(4,3); Delete 3 chars from idx 4
	// But how to erase all non-alphabetic characters?
	//   H#el!lo  =>  Hello
	//   0123456
	// Suggest going backwards.
	for(int i = input.size()-1; i >= 0; --i) {
		// ---- If .at(i) isn't alphabetic, erase it.
	}
	cout << "New string: "
		   << input << endl;
	
	return 0;
}