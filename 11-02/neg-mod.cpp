#include <iostream>
using namespace std;
int main()
{
	// Nullary operator: no operands.
	// Conditional operator.
	// Ternary operator: 3 operands.
	for(int i = -5; i <= 5; i++) {
		cout << i << " " << (abs(i%2)==1? "odd" : "even ") << " " << i%2 << endl;
	}
	return 0;
}