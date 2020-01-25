// kolos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class A {
    int* arr;
    int size;

public:
    A (int* arr, int size) : arr(arr), size(size) {  };

    A& operator = (const A& other) {
        arr = new int[other.size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    void printA() {
        std::cout << "    > Array:" << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << i << " : " << arr[i] << std::endl;
        }
        std::cout << "    > Done" << std::endl;
    }
};

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {};

    void add(int data) {
        Node* current = this;
        while (current->next != nullptr) current = current->next;
        current->next = new Node(data);
    }
};

int fun(const Node* head) {
    const Node* current = head;
    while (current->next->next != nullptr) current = current->next;
    return current->data;
}

void check1() {
    int arr[] = { 1, 2, 3, 4 };
    A* a = new A(arr, 4);
    A b = *a;
    b.printA();
    delete(a);
    b.printA();
}

void check3() {
    Node* head = new Node(1);
    head->add(2);
    head->add(3);
    head->add(4);
    head->add(5);
    head->add(6);
    std::cout << fun(head) << std::endl;
}

int main()
{
    check3();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu