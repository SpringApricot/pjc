#include <iostream>
#include "pdf3_zad4.h"

int main()
{
	using std::cout; using std::endl;
	char s1[] = "Alice in Wonderland";
	cout << "reverse: " << reverse(s1) << endl;
	cout << "length : " << length(s1) << endl;
	char s2[] = " ... for (int i = 0; i < n; ++i){...} ...";
	cout << "words : " << words(s2) << endl;
	cout << "words2 : " << words2(s2) << endl;
	char s3[100] = "Hello";
	//cout << "concat : " << concat(concat(s3, ", world"), "!") << endl;
}

size_t length(const char* cstr){ //1
	size_t length = 0;
	while (*(cstr+ length) != 0) length++;
	return length;
}

bool isLetter(char c) { //2
	return 0;
}

char* reverse(char* cstr) { //3 //TODO bs
	const size_t mylength = length(cstr);
	char tmp = *cstr;
	char* reversed = &tmp;

	for (int i = mylength -1, j = 0; i >= 0; i--, j++) {
		*(reversed + j) = *(cstr + i);
	}
	*(reversed + mylength) = '/0';

	return reversed;
}

size_t words(const char* cstr) { //4
	return 0;
}

size_t words2(const char* cstr) { //5
	return 0;
}

char* concat(char* t, const char* s) { //6
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu