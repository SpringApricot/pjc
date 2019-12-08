#pragma once

struct Node {
	int data;
	Node* next;
};

bool add(Node*& head, int data);
size_t size(const Node* head);
void clear(Node*& head);
void printList(Node* head);