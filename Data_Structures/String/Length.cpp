#include <stdio.h>
#include <iostream>
#include <string>

int lengthOfStr(const std::string& str);


int main()
{
	std::string str;

	printf("Enter a string: ");
	std::cin >> str;

	printf("length of %s: %d", str.c_str(), lengthOfStr(str));
}


int lengthOfStr(const std::string& str)
{
	int length = 0;
	for (; str[length]; length++)
		;

	return length;
}