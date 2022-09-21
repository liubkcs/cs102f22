// Michael Jordan 1991 -> JordaM91
// Kanye West 2024 -> WestK24
#include <iostream>
#include <string>
using namespace std;
int main()
{
	// This is not a complete solution,
	// but there are some ideas here.
	string first, last;
	string num;
	string login;
	cin >> first >> last >> num;
  cout << num.substr(num.length()-2, num.length())
		  << endl;
	
	login = last.substr(0,5) + first[0] ;
	cout << login << endl;
}