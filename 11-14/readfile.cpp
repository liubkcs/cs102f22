// Demonstration of reading a big text file
// using fstream.
#include <iostream>
#include <fstream>
using namespace std;
int main() {
	ifstream ifs;
	ifs.open("11-14/pg1342.txt");
	if(!ifs.is_open()) {
		cout << "Error opening file.\n";
		return 0;
	}
	cout << "Opened the file.\n";
	string line;
	int lineCount = 0;
	int charCount = 0;
	getline(ifs, line);
	while(!ifs.fail()) {
		lineCount++;
		charCount += line.size() + 1;
		getline(ifs, line);
	}
	cout << "File has " << lineCount << " lines and "
		<< charCount << " characters.\n";
	ifs.close();
	return 0;
}