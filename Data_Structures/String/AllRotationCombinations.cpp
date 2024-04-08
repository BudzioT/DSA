#include <stdio.h>
#include <iostream>
#include <string>

void allRotatedString(const std::string& str);
void allRotatedStringByConcat(const std::string& str);


int main()
{
	std::string str;

	printf("Enter a string: ");
	std::getline(std::cin, str);

	printf("All rotated strings:");
	allRotatedString(str);
	
	printf("\nAll rotated string by concat:");
	allRotatedStringByConcat(str);
}


void allRotatedString(const std::string& str)
{
	int length = str.length();
	
	std::string temp(length, '\0');

	for (int i = 0; i < length; i++) {
		int j = i;
		int k = 0;

		while (str[j])
			temp[k++] = str[j++];

		j = 0;
		while (j < i)
			temp[k++] = str[j++];

		printf(" %s", temp.c_str());
	}
}

void allRotatedStringByConcat(const std::string& str)
{
	int length = str.length();

	std::string temp = str;
	temp += str;

	for (int i = 0; i < length; i++) {
		printf(" ");

		for (int j = 0; j < length; j++)
			printf("%c", temp[i + j]);
	}
}