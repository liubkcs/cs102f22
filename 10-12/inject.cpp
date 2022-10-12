// Demonstrate an "injection"
// fault using C++, console, getline.
#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;
// This program wants to show the
// size of a file.
int main()
{
	string filename;
	cout << "Enter a filename: ";
	getline(cin, filename);
	string command =
	   "ls --size --block-size=K " + filename;
	system(command.c_str());
	return 0;
}