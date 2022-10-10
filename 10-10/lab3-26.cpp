#include <iostream>
using namespace std;
int main()
{
	string s1 = "";
	string s2 = "";
	string s3 = "";
	cin >> s1 >> s2 >> s3;
	if(s3.empty()) { // 2 names
		cout << s2 << ", "
			<< s1.at(0) << ".\n";
	}
	else { // 3 names
		cout << s3 << ", "
			<< s1.at(0) << "."
			<< s2.at(0) << ".\n";
	}
	return 0;
}