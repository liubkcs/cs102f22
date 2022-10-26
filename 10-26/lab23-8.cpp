#include <iostream>
#include <list>
using namespace std;

/* Define your functions here */ 
string IntToReverseBinary(unsigned long integerValue)
{
	string bits;
	for( ; integerValue > 0; integerValue /= 2) {
		// bits.push_back(integerValue%2? '1' : '0');
		bits.push_back('0' + integerValue%2);
		//bits += ('0' + integerValue%2);
	}
	cout << "Bits has size " << bits.size() << endl;
	cout << "Bits is: " << bits << endl;
	return bits;
}

string StringReverse(string userString)
{
	// IDEA #1: Using swapping.
	// unsigned j = userString.size()-1;	
	// for(unsigned i = 0; i < userString.size()/2; i++, j--) {
	//   // Swap i,j
	// 	cout << "Swapping " << i << " with " << j << endl;
	// 	char tmp = userString.at(i);
	// 	userString.at(i) = userString.at(j);
	// 	userString.at(j) = tmp;
	// }
	// return userString;

	// IDEA #2: read backwards, copy each character
	// to new string using push_back.
	// string newString;
	// for(int i = userString.size()-1; i >= 0; --i) {
	// 	newString.push_back(userString.at(i));
	// }
	// return newString;

	// IDEA #3: read forwards, copy each character
	// using push_front. (Caveat: can be slower than
	// push_back.)
	string newString;
	for(char c : userString) {
		// https://stackoverflow.com/questions/8468597/prepend-stdstring
		// Apparently, push_front doesn't exist on strings,
		// but the answers point out that insert(0,1,c)
		// is an alternative.
		newString.insert(0,1,c); // push_front(c);
	}
	return newString;
}

int main() {
   /* Type your code here. 
      Your code must call IntToReverseBinary() to get
      the binary string of an integer in a reverse order.
      Then call StringReverse() to reverse the string 
      returned from IntToReverseBinary().*/
	unsigned long numToConvert;
	cin >> numToConvert;
	cout << StringReverse(IntToReverseBinary(numToConvert))
       << endl;   

  return 0;
}