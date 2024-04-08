#include <stdio.h>
#include <iostream>
#include <string>

void reverseString(std::string& str);
void reverseStringRecursiveTwo(std::string& str, int n, int i = 0);
void reverseStringRecursiveOne(std::string& str, int i = 0);


int main()
{
	std::string str;

	printf("Enter a string: ");
	std::getline(std::cin, str);

	reverseString(str);
	printf("\nReversed: %s\n", str.c_str());

	reverseStringRecursiveTwo(str, str.length() - 1);
	printf("Reversed by two pointers using recursion: %s\n", str.c_str());

	reverseStringRecursiveOne(str);
	printf("Reversed by one pointer using recursion: %s\n", str.c_str());
}


void reverseString(std::string& str)
{
	int length = str.length();

	for (int i = 0, j = length - 1; i < j; i++, j--) {
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

void reverseStringRecursiveTwo(std::string& str, int n, int i)
{
	if (n <= i)
		return;

	char temp = str[i];
	str[i] = str[n];
	str[n] = temp;

	reverseStringRecursiveTwo(str, n - 1, i + 1);
}

void reverseStringRecursiveOne(std::string& str, int i)
{
	int last = str.length() - 1 - i;

	if (i >= last)
		return;

	char temp = str[i];
	str[i] = str[last];
	str[last] = temp;

	reverseStringRecursiveOne(str, i + 1);
}