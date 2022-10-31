#include <iostream>
using namespace std;

void calculateChange(int amt, // Input parameter passed by value
      int& q, int& d, int& n, int& p) 
  // Output params passed by reference.
{
	q = amt / 25; amt %= 25;
	d = amt / 10; amt %= 10;
	n = amt /  5; amt %=  5;
	p = amt;
}

void sayCoin(int count, string singular,
						string plural) 
{
	switch(count) {
		case 0: break;
		case 1:
			cout << count << " " << singular << endl;
		  break;
		default:
			cout << count << " " << plural << endl;
	}
}

int main()
{
	int amount;
	cout << "Enter total cents: ";
	cin >> amount;
	int quarters, dimes, nickels, pennies;
	calculateChange(amount, // input parameter
							quarters, dimes, // output params
							nickels, pennies);
	cout << amount << "¢ is\n";
	sayCoin(quarters, "Quarter", "Quarters");
	sayCoin(dimes, "Dime", "Dimes");
	sayCoin(nickels, "Nickel", "Nickels");
	sayCoin(pennies, "Penny", "Pennies");
	return 0;	}