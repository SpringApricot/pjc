#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define LOG(x) std::cout << x << std::endl


class Person {

	char* name;
	friend class Couple;

public:

	explicit Person(const char* n) {
		name = new char[strlen(n)];
		strcpy(name, n);
	}

	Person(const Person& os) {
		name = os.name;
	}

	Person& operator = (const Person& os) {
		name = os.name;
		return *this;
	}

	~Person() {
		LOG(name << " destroyed!");
	}

	friend std::ostream& operator << (std::ostream& str, const Person& os) {
		str << os.name;
		return str;
	}

};

// implementation
class Couple {

	Person* wife, * husband;

public:

	Couple(const Person& she, const Person& he) {
		wife = new Person(she);
		husband = new Person(he);
	}

	Couple(const Couple& other) {
		wife = other.wife;
		husband = other.husband;
	}

	Couple& operator = (const Couple& other) {
		wife = other.wife;
		husband = other.husband;
		return *this;
	}

	~Couple() {
		LOG(wife->name << " and " << husband->name << " destroyed!");
	}

	friend std::ostream& operator << (std::ostream& str, const Couple& p) {
		str << *p.wife << " and " << *p.husband;
		return str;
	}
};


// implementation
int main(void) {

	Person* pjohn = new Person("John"),
		  * pjane = new Person("Jane");
	Person mary("Mary"), mark("Mark");

	Couple* pcouple1 = new Couple(mary, *pjohn);
	Couple couple2(*pjane, mark);

	delete pjohn;
	delete pjane;

	std::cout << *pcouple1 << std::endl;
	std::cout << couple2 << std::endl;

	couple2 = *pcouple1;
	delete pcouple1;
	std::cout << couple2 << std::endl << "===END===" << std::endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
