// kolos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//Klasy do rozwiazan
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

struct Point {
    double x, y;

    Point(double x, double y) : x(x), y(y) {};
};

struct Rect {
    Point dl, gp;

    Rect(Point dl, Point gp) : dl(dl), gp(gp) {};
};

struct Segment {
    double a, b; // a <= b

    Segment(double a, double b) : a(a), b(b) {};
};

bool intersect(const Segment* ps, const Segment& ra) {
    return ((ps->a < ra.a) && (ps->b > ra.a))
        || ((ps->a < ra.b) && (ps->b > ra.b))
        || ((ps->a > ra.a) && (ps->b < ra.b));
}

//Funkcje do rozwiazan
int fun(const Node* head) {
    const Node* current = head;
    while (current->next->next != nullptr) current = current->next;
    return current->data;
}

double perim(const Rect* pr) {
    double horizontal = pr->gp.x - pr->dl.x;
    double vertical = pr->gp.y - pr->dl.y;
    return 2 * horizontal + 2 * vertical;
}

//Funkcje sprawdzajace rozwi¹zania
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

void check4() {
    Rect* rect = new Rect(Point(-3.5, -3.5), Point(-1, -1));
    std::cout << perim(rect) << std::endl;
}

void check5() {
    Segment a = Segment(2, 4);
    Segment b = Segment(5, 7);
    Segment c = Segment(9, 11);
    Segment d = Segment(13, 15);
    Segment e = Segment(17, 19);
    Segment ver = Segment(6, 14);

    bool test1 = (false == intersect(&ver, a));
    bool test2 = (true == intersect(&ver, b));
    bool test3 = (true == intersect(&ver, c));
    bool test4 = (true == intersect(&ver, d));
    bool test5 = (false == intersect(&ver, e));

    bool test1b = (false == intersect(&a, ver));
    bool test2b = (true == intersect(&b, ver));
    bool test3b = (true == intersect(&c, ver));
    bool test4b = (true == intersect(&d, ver));
    bool test5b = (false == intersect(&e, ver));

    if (test1 && test2 && test3 && test4 && test5) std::cout << "Success!" << std::endl;
    else std::cout << "Error!" << std::endl;

    if (test1b && test2b && test3b && test4b && test5b) std::cout << "Success 2!" << std::endl;
    else {
        std::cout << "Error 2!" << std::endl;
        std::cout << "1: " << test1b << std::endl;
        std::cout << "2: " << test2b << std::endl;
        std::cout << "3: " << test3b << std::endl;
        std::cout << "4: " << test4b << std::endl;
        std::cout << "5: " << test5b << std::endl;
    }
}

//Main '\_:)_/' <- rip unicode
int main()
{
    check5();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu