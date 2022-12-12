#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Coin {
public:
  inline Coin(string name, int denomination)
    : name(name), denomination(denomination)
    { }
  string name;
  int denomination;
};

void genCoins(int targetCents,
              const vector<Coin>& coins,
							int curCoinIndex,
							vector<int>& counts,
							int& numCombos)
{
	// Are we down to considering pennies?
	if(curCoinIndex == coins.size()-1) {
		counts[curCoinIndex] = targetCents;
		numCombos++;
		for(unsigned i = 0; i < coins.size(); i++)
		{
			cout << setw(5) << counts[i]
				  << coins[i].name.at(0) << ' ';
		}
		cout << endl;
	}	
	else {
		// Use curCoinIndex
		unsigned total = 0;
		for(unsigned count = 0; 
			  total <= targetCents;
				count++, 
			total = count *
			  coins[curCoinIndex].denomination)
			{
				counts[curCoinIndex] = count;
				genCoins(targetCents - total,
					  coins, curCoinIndex+1, counts,
					  numCombos);				
			}
	}
}

int main()
{
	//map<pair<string,int>, int>
	vector<Coin> coins = {
		{ "Dollar", 100 },
		{ "Half-dollar", 50 },
		{ "Quarter", 25 },
		{ "Dime", 10 },
		{ "Nickel", 5 },
		{ "Penny", 1 }
	};
  vector<int> counts(coins.size());
	int numCombos = 0;
  genCoins(115, coins, 0, counts, numCombos);
  cout << numCombos << " combinations\n";	
	// for(Coin coin : coins) {
	// 	cout << coin.name << endl;
	// }
	
}