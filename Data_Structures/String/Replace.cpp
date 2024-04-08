#include <stdio.h>
#include <iostream>
#include <string>

void replaceString(std::string& str1, const std::string& oldStr, const std::string& newStr);


int main()
{
	std::string str, str2, str3;

	printf("Enter three strings: ");
	std::cin >> str >> str2 >> str3;

	printf("%s with %s replaced with %s", str.c_str(), str2.c_str(), str3.c_str());
	replaceString(str, str2, str3);
	printf(" = %s", str.c_str());
}


void replaceString(std::string& str1, const std::string& oldStr, const std::string& newStr)
{
	std::string result;

	int len1 = str1.length();
	int len2 = oldStr.length();

	for (int i = 0; i <= len1 - len2 + 1; i++) {
		int j = 0;

		if (str1[i] == oldStr[j]) {
			for (; j < len2; j++) {
				if (str1[i + j] != oldStr[j])
					break;
			}	
		}

		if (j == oldStr.length()) {
			result += newStr;
			i += len2 - 1;
		}
		else
			result += str1[i];
	}

	str1 = result;
}