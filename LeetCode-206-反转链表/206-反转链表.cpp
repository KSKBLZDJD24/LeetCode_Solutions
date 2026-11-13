#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

int main() {
	Node* head = new Node{ 1,new Node{2,new Node{3,nullptr}} };

	Node* prev = nullptr;
	Node* cur = head;
	
	while (cur!=nullptr)
	{
		Node* next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	Node* newHead = prev;

	cur = newHead;
	while (cur != nullptr) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	return 0;
}