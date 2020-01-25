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

int main()
{
    std::cout << "Hello World!\n";

    int arr[] = {1, 2, 3, 4};
    A* a = new A(arr, 4);
    A b = *a;
    b.printA();
    delete(a);
    b.printA();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu