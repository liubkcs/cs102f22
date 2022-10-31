#include <iostream>
using namespace std;

/* Your code goes here */
void FindIndex(string input) {
   for(unsigned i = 0; i < input.size()-1; ++i) {
      if(input.at(i) == 'p' && input.at(i+1) == 'y') {
         cout << "py is found at index " << i << ".\n";
         return;
      }
   }
   cout << "py is not found in " << input << ".\n";
   
   // int i = input.find("py");
   // if(i == string::npos) {
   //    cout << "py is not found in " << input << ".\n";
   // }
   // else {
   //    cout << "py is found at index " << i << ".\n";
   // }
}

int main() {
   int i;
   string inputString;

   cin >> inputString;

   FindIndex(inputString);

   return 0;
}