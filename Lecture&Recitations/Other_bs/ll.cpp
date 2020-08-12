#include <iostream>

using namespace std;

struct SingleNode {
	int key;
	SingleNode* next;
};

int main() {
	SingleNode* head = new SingleNode;
	head->key = 0;
	head->next = nullptr;

	cout << head->key << endl;
	cout << head->next->key << endl; // causes seg-fault -> why?

	return 0;
}
