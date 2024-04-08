#include <stdio.h>
#include <iostream>
#include <string>

int findSubString(const std::string& str1, const std::string& str2);


int main()
{
	std::string str;
	std::string str2;

	printf("Enter two strings: ");
	std::cin >> str >> str2;
	printf("%s is in %s at position: %d", str2.c_str(), str.c_str(), findSubString(str, str2));
}


int findSubString(const std::string& str1, const std::string& str2)
{
	int len1 = str1.length();
	int len2 = str2.length();

	for (int i = 0; i <= len1 - len2; i++) {
		int j;

		for (j = 0; j < len2; j++) {
			if (str1[i + j] != str2[j])
				break;
		}

		if (j == len2)
			return i;
	}

	return -1;
}