#include <stdio.h>
#include <limits>

void showArray(int* arr, int n);

/* Kadane's algorithm */
int largestContiguousSum(int* arr, int n);

/* Print the subarray using Kadane's algorithm */
void printLargestContiguousSub(int* arr, int n);

/* Largest SubArray sum using Dynamic programming */
int largestSumDP(int* arr, int n);


int main()
{
	const int size = 10;
	int arr[size] = { 5, -3, 4, 2, -7, -4, 3, 6, 7, -1 };
	printf("Array:");
	showArray(arr, size);

	printf("Largest contiguous sum: %d", largestContiguousSum(arr, size));

	printLargestContiguousSub(arr, size);

	printf("Largest contiguous sum using Dynamic Programming: %d", largestSumDP(arr, size));
}


void showArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		printf(" %d", arr[i]);
	printf("\n");
}

int largestContiguousSum(int* arr, int n)
{
	int currSum = 0;
	int maxSum = INT_MIN;

	for (int i = 0; i < n; i++) {
		currSum += arr[i];
		if (currSum > maxSum)
			maxSum = currSum;
		if (currSum < 0)
			currSum = 0;
	}

	return maxSum;
}

void printLargestContiguousSub(int* arr, int n)
{
	int start = 0;
	int end = 0;
	int s = 0;

	int currSum = 0;
	int maxSum = INT_MIN;

	for (int i = 0; i < n; i++) {
		currSum += arr[i];
		
		if (currSum > maxSum) {
			maxSum = currSum;

			start = s;
			end = i + 1;
		}

		if (currSum < 0) {
			s = i + 1;
			currSum = 0;
		}
	}

	printf("\nLargest contiguous subarray:");
	for (int i = start; i < end; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");
}

int largestSumDP(int* arr, int n)
{
	if (n <= 0)
		return -1;

	int* dp = new int[n];

	dp[0] = arr[0];
	int result = dp[0];

	for (int i = 1; i < n; i++) {
		dp[i] = ((arr[i] > arr[i] + dp[i - 1]) ? arr[i] : arr[i] + dp[i - 1]);
		result = ((result > dp[i]) ? result : dp[i]);
	}

	delete[] dp;

	return result;
}