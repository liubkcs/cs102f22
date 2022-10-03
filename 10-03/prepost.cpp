#include <iostream>
using namespace std;
int main()
{
	int i = 12;
	int x = i++ * 2;
	int y = ++i * 2;
	cout << i << endl; // 14
	cout << x << endl; // 24
	cout << y << endl; // 28
}