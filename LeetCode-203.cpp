#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

class LinkedList {
private:
	Node* head;
public:
	LinkedList() {
		head = new Node;
		head->next = nullptr;
	}

	~LinkedList() {
		Node* tur = head;
		while (tur != nullptr) {
			Node* temp = tur->next;
			delete tur;
			tur = temp;
		}
	}
	void ListP(int val) {
	Node* dummy = new Node;
	dummy->next = head;
	Node* p = dummy;

	while (p->next!=nullptr)
	{
		if (p->next->data ==val) {
			Node* del = p->next;
			p->next = del->next;
			delete del;
		}
		else {
			p = p->next;
		}
	}
}

bool ListC(int i, int x) {
	Node* p = head; 
	int j = 0;
	if (i < 1) {
		return false;
	}
	while (p!=nullptr&&j<i-1)
	{
		p = p->next;
		j++;
	}

	if (p == nullptr) {
		return false;
	}

	Node* s = new Node;
	s->data = x;
	s->next = p->next;
	p->next = s;

	return true;
}

	void print() {
		Node* p = head->next;
		while (p != nullptr) {
			cout << "输出：" << p->data << "\t";
			p = p->next;
		}
	}
};

int main() {
	LinkedList list;
	int h = 0;
	cout << "几个数字？" << endl;
	cin >> h;
	for (int i = 0; i < h; i++) {
		int p = 0;
		cout << "输入内容:" << endl;
		cin >> p;
		list.ListC(i+1, p);
	}

	cout << "删除前：" << endl;
	list.print();
	cout << endl;

	int del = 0;
	cout << "输入要删除的元素：" << endl;
	cin >> del;
	list.ListP(del);

	cout << "删除后：" << endl;
	list.print();

	system("pause");
	return 0;
}

