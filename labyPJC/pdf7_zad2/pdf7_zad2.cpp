#include <iostream>
#include <string>
#include <sstream> //Not sure if I can use it, but whatever.
#define LOG(x) std::cout << x << std::endl;

template <typename T>
struct Node {
	T data;
	Node* next;
};

template <typename T>
void showList(const Node<T>* head) {
	if (head == nullptr) { return; }
	std::ostringstream sstream;
	sstream << head->data;
	while (head->next != nullptr) {
		head = head->next;
		sstream << " " << head->data;
	}
	std::string output = sstream.str();
	LOG(output);
}

template <typename T>
Node<T>* arrayToList(const T tab[], size_t size) {
	Node<T>* head = new Node<T>();
	head->data = tab[0];
	head->next = nullptr;

	Node<T>* tmp = head;
	for (size_t i = 1; i < size; i++) {
		tmp->next = new Node<T>();
		tmp = tmp->next;
		tmp->data = tab[i];
	}

	return head;
}

template<typename T, typename Pred>
Node<T>* extract(Node<T>*& head, Pred predicate) {
	Node<T>* head_failing = nullptr;
	Node<T>* head_passing = nullptr;
	Node<T>* current_failing = nullptr;
	Node<T>* current_passing = nullptr;
	Node<T>* current = head;

	while (current != nullptr) {
		if (predicate(current->data)) {
			if (head_passing == nullptr) {
				head_passing = current;
				current_passing = current;
				current = current->next;
				current_passing->next = nullptr;
			} else {
				current_passing->next = current;
				current_passing = current_passing->next;
				current = current->next;
				current_passing->next = nullptr;
			}
		} else {
			if (head_failing == nullptr) {
				head_failing = current;
				current_failing = current;
				current = current->next;
				current_failing->next = nullptr;
			} else {
				current_failing->next = current;
				current_failing = current_failing->next;
				current = current->next;
				current_failing->next = nullptr;
			}
		}
	}

	head = head_failing;
	return head_passing;
}

template <typename T>
void deleteList(Node<T>*& head) {
	rec_deleteList(head);
	LOG("");
}

template <typename T>
void rec_deleteList(Node<T>*& head) {
	Node<T>* current = head->next;
	std::cout << "DEL " << head->data << "; ";
	delete head;
	if (current != nullptr) {
		rec_deleteList(current);
	}
}

bool isLong(const std::string& s) { return s.size() >= 5; }

int main() {
	int tabi[] = { 2,1,4,3,6,5,7,8 };
	size_t sizei = sizeof(tabi) / sizeof(tabi[0]);
	Node<int>* listAi = arrayToList(tabi, sizei);
	showList(listAi);
	Node<int>* listBi = extract(
		listAi, [](int n)->bool {return n % 2 == 0; });
	showList(listAi);
	showList(listBi);
	deleteList(listAi);
	deleteList(listBi);
	std::string tabs[]{ "Kasia", "Ola", "Ala",
	"Zosia", "Ela", "Basia" };
	size_t sizes = sizeof(tabs) / sizeof(tabs[0]);
	Node<std::string>* listAs = arrayToList(tabs, sizes);
	showList(listAs);
	Node<std::string>* listBs = extract(listAs, isLong);
	showList(listAs);
	showList(listBs);
	deleteList(listAs);
	deleteList(listBs);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
