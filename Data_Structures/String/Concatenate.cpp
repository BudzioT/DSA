#include <stdio.h>
#include <iostream>
#include <string>

std::string concatenate(const std::string& lhs, const std::string& rhs);


int main()
{
	std::string str, str2;

	printf("Enter two strings: ");
	std::cin >> str >> str2;

	printf("%s + %s = %s", str.c_str(), str2.c_str(), concatenate(str, str2).c_str());
}


std::string concatenate(const std::string& lhs, const std::string& rhs)
{
	std::string result;

	int len1 = lhs.length();
	int len2 = rhs.length();

	result.reserve(len1 + len2);

	for (int i = 0; i < len1; i++)
		result += lhs[i];
	for (int j = 0; j < len2; j++)
		result += rhs[j];

	return result;
}