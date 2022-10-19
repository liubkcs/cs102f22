#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
int main()
{
	vector<string> words;
  // Let "end" be sentinel word.
	string word;
	cin >> word;
	while(word != "end") {
		words.push_back(word);	
		cin >> word;
	}
  // Selection sort
	for(unsigned i = 0; i < words.size(); ++i) {				for(unsigned j = i+1; j < words.size(); ++j) {
			if(words.at(i) > words.at(j)) {
				string tmp;
				tmp = words.at(i);
				words.at(i) = words.at(j);
				words.at(j) = tmp;					
			}
		}
	}

	// Output vector
	for(unsigned i = 0; i < words.size(); ++i) {
		cout << setw(4) << i << ' ' << words.at(i)
			   << '\n';
	}
	return 0;
}