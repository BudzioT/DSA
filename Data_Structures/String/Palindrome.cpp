#include <stdio.h>
#include <iostream>
#include <string>

bool isPalindrome(const std::string& str);


int main()
{
	std::string str;

	printf("Enter a string: ");
	std::getline(std::cin, str);

	printf("%s = %d", str.c_str(), isPalindrome(str));
}


bool isPalindrome(const std::string& str)
{
	for (int i = 0, j = str.length() - 1; i < j; i++, j--) {
		if (str[i] != str[j])
			return false;
	}

	return true;
}