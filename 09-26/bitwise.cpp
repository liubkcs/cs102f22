#include <iostream>
using namespace std;
int main()
{
	// Logical operators (&&, ||)
	// vs bitwise operators (&, |)
	int x = 75;
	int y = 41;
	// Logically, when int is used
	// as a Boolean, 0=false,
	// non-zero=true.
	//   75 && 41 -->
	//  true && true --> true --> 1
	cout << "Logical AND: "
		   << (x && y) << endl;
	// Bitwise refers binary numbers.
	//      64 32 16  8  4  2  1
	//  75   1  0  0  1  0  1  1
	//  41   0  1  0  1  0  0  1
	// 75&41 0  0  0  1  0  0  1 == 9
	// 75|41 1  1  0  1  0  1  1 ==107
	cout << "Bitwise AND: "
		   << (x & y) << endl;
	cout << "Bitwise OR: "
		   << (x | y) << endl;
}