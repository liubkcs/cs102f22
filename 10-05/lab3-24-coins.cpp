#include <iostream>
using namespace std;
int main()
{
	int amount;
	cin >> amount; 
	// 382 -->
	// 3 Dollars     382/100==3   382%100==82
	// 3 Quarters     82/25==3     82%25==7
	// [skip dimes]    7/10==0      7%10==7
	// 1 Nickel        7/5 ==1      7%5==2
	// 2 Pennies       2
	int dollars = amount/100;
	switch(dollars) {
		case 0: break;
		case 1: cout << "1 dollar\n"; break;
		default: cout << dollars << " dollars\n";
	}
	amount = amount % 100;

	int quarters = amount/25;
	switch(quarters) {
		case 0: break;
		case 1: cout << "1 quarter\n"; break;
		default: cout << quarters << " quarters\n";
	}
	amount %= 25;

	// TODO: dimes, nickels, pennies.
	return 0;
}