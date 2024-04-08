#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

void printSubStrings(const std::string& str);

void printSubStringsBySubstr(const std::string& str);

void printSubStringsByPrevious(const std::string& str);

void printSubStringsFaster(const std::string& str);


int main()
{
	std::string str;

	printf("Enter a string: ");
	std::getline(std::cin, str);

	printf("All substrings:");
	printSubStrings(str);

	printf("\nAll substrings by substr:");
	printSubStringsBySubstr(str);

	printf("\nAll substrings using previous substring:");
	printSubStringsByPrevious(str);

	printf("\nAll substrings using two loops:");
	printSubStringsFaster(str);
}


void printSubStrings(const std::string& str)
{
	int length = str.length();

	/* Starting point (length of substring) */
	for (int len = 1; len <= length; len++) {
		/* Ending point (first letter of substring) */
		for (int i = 0; i <= length - len; i++) {
			printf(" ");

			/* Print all chars from start to the end */
			int j = i + len - 1;
			for (int k = i; k <= j; k++)
				printf("%c", str[k]);
		}
	}
}

void printSubStringsBySubstr(const std::string& str)
{
	int length = str.length();

	for (int len = 1; len <= length; len++) {
		for (int i = 0; i <= length - len; i++) {
			printf(" %s", str.substr(i, len).c_str());
		}
	}
}

void printSubStringsByPrevious(const std::string& str)
{
	int length = str.length();

	for (int i = 0; i < length; i++) {
		char* temp = new char[length - i + 1];
		int tempIndex = 0;

		for (int j = i; j < length; j++) {
			temp[tempIndex++] = str[j];
			temp[tempIndex] = '\0';
			printf(" %s", temp);
		}

		delete [] temp;
	}
}

void printSubStringsFaster(const std::string& str)
{
	int length = str.length();

	for (int i = 0; i < length; i++) {
		std::string subStr;

		for (int j = i; j < length; j++) {
			subStr += str[j];
			printf(" %s", subStr.c_str());
		}
	}
}