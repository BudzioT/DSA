#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

void printAllSubsequences(const std::string& input, const std::string& output);

void printAllSubsequencesByPointers(const std::string& str, int n, int index = -1, std::string curr = "");

std::vector<std::string> createSubSequencesFromBinary(const std::string& str);
std::string createSubSequenceBinary(const std::string& str, int i);


int main()
{
	std::string str;

	printf("Enter a string: ");
	std::getline(std::cin, str);

	printf("All subsequences:");
	printAllSubsequences(str, "");

	printf("\nAll subsequences by pointers:");
	printAllSubsequencesByPointers(str, str.length());

	printf("\nAll subsequences by binary:");
	std::vector<std::string> subSeqs = createSubSequencesFromBinary(str);
	for (int i = 0; i < subSeqs.size(); i++)
		printf(" %s", subSeqs[i].c_str());
}


void printAllSubsequences(const std::string& input, const std::string& output)
{
	if (input.empty()) {
		printf(" %s", output.c_str());
		return;
	}

	printAllSubsequences(input.substr(1), output + input[0]);

	printAllSubsequences(input.substr(1), output);
}

void printAllSubsequencesByPointers(const std::string& str, int n, int index, std::string curr) {
	if (index == n)
		return;

	if (!curr.empty())
		printf(" %s", curr.c_str());

	for (int i = index + 1; i < n; i++) {
		curr += str[i];

		printAllSubsequencesByPointers(str, n, i, curr);

		curr = curr.erase(curr.size() - 1);
	}
}

std::vector<std::string> createSubSequencesFromBinary(const std::string& str)
{
	std::vector<std::string> subseqs;

	for (int i = 1; i <= ((1 << str.length()) - 1); i++)
		subseqs.push_back(createSubSequenceBinary(str, i));

	return subseqs;
}

std::string createSubSequenceBinary(const std::string& str, int i)
{
	int j = 0;
	std::string sub;

	while (i > 0) {
		if (i & 1)
			sub += str[j];
		++j;
		i >>= 1;
	}

	return sub;
}