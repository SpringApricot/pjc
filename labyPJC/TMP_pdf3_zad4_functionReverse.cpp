#include <iostream>

size_t length(const char* cstr);
char* reverse(char* cstr);

int main()
{
	using std::cout; using std::endl;
    char s1[] = "Alice in Wonderland!";
    cout << "reverse: " << reverse(s1) << endl;
}


size_t length(const char* cstr){
	size_t length = 0;
	while (*(cstr+length) != '\0') length++;
	return length;
}

char* reverse(char* cstr){
	size_t mylength;
	mylength = length(cstr);
	
	char tmp;
	
	for (int i = 0; i < (mylength - 1)/2; i++){
		tmp = *(cstr+i);
		*(cstr+i) = *(cstr+mylength-1-i);
		*(cstr+mylength-1-i) = tmp;
	}
	
	return cstr;
}