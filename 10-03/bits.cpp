// Calculate number of bits needed
// to represent a positive integer.
// 51 = 32 + 16 + 2 + 1
//      32 16  8  4  2  1
//      1   1  0  0  1  1
// Therefore, 51 requires 6 bits.
//   1024  512  256  128  64  32  16  8  4  2  1
//      1    0    0    0   0   0   0  0  0  0  0 
#include <iostream>
using namespace std;
int main()
{
	cout << "Enter a positive number: ";
	int num;
	cin >> num;
	int bits = 0;
	/* DO CALCULATION */
	// How many times can we divide by two?
	//   51 -> 25 -> 12 -> 6 -> 3 -> 1 -> 0
	int cur = num;
	while(cur > 0) {
		cur /= 2;
		// cout << cur << endl;
		bits++;
	}
	
	cout << num << " requires " << bits << " bits.\n";
	return 0;
}