#include <iostream>
using namespace std;

class IntNode {
public:
  IntNode(int value, IntNode* next = nullptr)
   : value(value), next(next) { }
  int value;
  IntNode* next;
};

void printList(IntNode* p) {
	if(p != nullptr) {
		cout << p->value << " ";
		printList(p->next);
	}
}

int main()
{
	IntNode* p = new IntNode(9);
	p = new IntNode(4, p);
	p = new IntNode(2, p);
	p = new IntNode(7, p);
	p = new IntNode(18, p);
	cout << "List is ";
	printList(p);
	cout << endl;

	// This idiom can remove some elements
	// from the list, but it leaves them
	// "dangling" (garbage).
	p->next->next = p->next->next->next->next;
	cout << "List is ";
	printList(p);
	cout << endl;

	p->next->next->next = p;
	cout << "List is ";
	printList(p);
	cout << endl;	
	return 0;
}