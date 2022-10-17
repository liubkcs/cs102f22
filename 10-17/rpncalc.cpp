// rpncalc.cpp
// Use a vector as a stack data structure
// to implement a calculator using
// RPN = Reverse Polish Notation.
// (Postfix arithmetic)
// [Lukasiewicz]

//  1+2*3 == 1+6 == 7       1 2 3 * +
// (1+2)*3 == 3*3 == 9      1 2 + 3 *

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	cout << "Welcome RPN calculator\n";
	vector<double> stack;
	while(true) {
		string input;
		if(stack.empty()) {
			cout << "empty ";
		}
		for(double d : stack) {
			cout << d << " ";
		}		
		cout << "> ";
		getline(cin, input);
		if(input == "quit" || input == "q") {
			break;
		}
		else if(input == "add" || input == "+") {
			// To add, pop the last 2 items, add them
			// and push the result.
			double x = stack.back(); // Retrieve
			stack.pop_back(); // Discard
			double y = stack.back();
			stack.pop_back();
			stack.push_back(x+y);
		}
		else if(input == "mul" || input == "*") {
			// Pop the last 2 items, multiply them
			// and push the result.
			double x = stack.back(); // Retrieve
			stack.pop_back(); // Discard
			double y = stack.back();
			stack.pop_back();
			stack.push_back(x*y);
		}
		else if(input == "clear" || input == "c") {
			stack.clear();
		}
		else {
			// Assume input is numeric
			stack.push_back(stod(input));
			}
	}
	return 0;
}