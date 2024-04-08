#include <stdio.h>
#include <algorithm>
#include <stack>

/* Show array */
void showArray(int* arr, int n);

/* Array reverse non-in-place */
void reverseArrayNonInPlace(int* arr, int n);

/* Array reverse in-place */
void reverseArrayInPlace(int* arr, int n);

/* Array reverse by recursion */
void reverseArrayRecursive(int* arr, int n, int start = 0);

/* Array reverse using stack */
void reverseArrayStack(int* arr, int n);


int main()
{
	const int size = 5;
	int arr[size] = { 1, 2, 3, 4, 5 };
	printf("Array:");
	showArray(arr, size);


	reverseArrayNonInPlace(arr, size);


	reverseArrayInPlace(arr, size);
	printf("Reversed array in-place:");
	showArray(arr, size);


	std::reverse(arr, arr + size);
	printf("Reversed array by built-in algorithm:");
	showArray(arr, size);

	reverseArrayRecursive(arr, size);
	printf("Reversed array using recursion: ");
	showArray(arr, size);

	reverseArrayStack(arr, size);
	printf("Reversed array using stack: ");
	showArray(arr, size);
}


void showArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		printf(" %d", arr[i]);
	printf("\n");
}

void reverseArrayNonInPlace(int* arr, int n) {
	int* reversedArray = new int[n];

	for (int i = 0; i < n; i++)
		reversedArray[i] = arr[n - i - 1];

	printf("Reversed array non-in-place:");
	showArray(arr, n);

	delete[] reversedArray;
}

void reverseArrayInPlace(int* arr, int n) {
	for (int start = 0; start < n - 1; start++) {
		int temp = arr[start];
		arr[start] = arr[--n];
		arr[n] = temp;
	}
}

void reverseArrayRecursive(int* arr, int n, int start)
{
	if (start >= n)
		return;

	int temp = arr[start];
	arr[start] = arr[n - 1];
	arr[n - 1] = temp;
	return reverseArrayRecursive(arr, n - 1, start + 1);
}

void reverseArrayStack(int* arr, int n)
{
	std::stack<int> stack;
	for (int i = 0; i < n; i++)
		stack.push(arr[i]);

	for (int i = 0; i < n; i++) {
		arr[i] = stack.top();
		stack.pop();
	}
}