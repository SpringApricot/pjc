#include <iostream>
#include "pdf5_zad3.h"

int main()
{
	int tab[] = { 1,4,1,3,5 };
	Node* head = 0;
	std::cout << "test" << std::endl;
	for (size_t i = 0, e = std::size(tab); i != e; ++i) {
		bool b = add(head, tab[i]);
		std::cout << tab[i] << (b ? " " : " NOT ")
			<< "added" << std::endl;
	}
	//std::cout << "Size of the list: " << size(head) << std::endl;
	printList(head);
	//clear(head);
}

bool add(Node*& head, int data) {
	Node* current = head;
	while (current->next) {
		if (current->data == data) return false;
		current = current->next;
	}
	if (current->data == data) return false;
	Node* newnode = new Node { data, nullptr };
	current->next = newnode;
}

size_t size(const Node* head) {
	return 0;
}

void clear(Node*& head) {

}

void printList(Node* head) {
	Node* current = head;
	while (current) {
		std::cout << current->data << std::endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
