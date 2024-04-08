#include <stdio.h>
#include <iostream>
#include <string>

std::string trim(const std::string& str);
std::string trimByCount(const std::string& str);


int main()
{
	std::string str;

	printf("Enter a string: ");
	std::getline(std::cin, str);

	printf("Normal:\n---%s---\nAfter trimming by moving:\n", str.c_str());
	printf("---%s---\n", trim(str).c_str());
	printf("After trimming by counting:\n");
	printf("---%s---", trimByCount(str).c_str());
}


std::string trim(const std::string& str)
{
	std::string result = str;

	int len = result.length();

	for (int i = 0; i < len;) {
		if (result[i] == ' ') {
			for (int j = i; j < len - 1; j++)
				result[j] = result[j + 1];
			--len;
			continue;
		}

		++i;
	}

	result[len] = '\0';
	return result;
}

std::string trimByCount(const std::string& str)
{
	std::string result = str;

	int length = result.length();
	int count = 0;

	for (int i = 0; i < length; i++) {
		if (result[i] != ' ')
			result[count++] = result[i];
	}

	result[count] = '\0';
	return result;
}