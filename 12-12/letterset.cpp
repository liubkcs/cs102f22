#include <iostream>
#include <set>
using namespace std;
int main()
{
	string text;
	cout << "Enter text:\n";
	getline(cin, text);
	set<char> alphabet;
	for(char c : text) {
		if(isalpha(c)) {
			alphabet.insert(tolower(c));
		}
	}
	cout << alphabet.size() << " unique letters\n";
	cout << "Used:   ";
	for(char c : alphabet) {
		cout << c;
	}
	cout << endl;
	cout << "Unused: ";
	for(char c = 'a'; c <= 'z'; c++) {
		if(alphabet.count(c) == 0) {
			cout << c;
		}
	}
	cout << endl;
	if(alphabet.size() == 26) {
		cout << "Congrats, that is a PANGRAM.\n";
	}
}