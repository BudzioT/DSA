#include <stdio.h>

void showArray(int* arr, int n);

/* Rotation of Array assigning each element to the one before or after */
void ArrayRightShift(int* arr, int n);
void ArrayLeftShift(int* arr, int n);

/* Rotation of Array by swapping */
void ArrayRightShiftSwap(int* arr, int n);
void ArrayLeftShiftSwap(int* arr, int n);

/* Rotation of Array by reversing */
void ArrayRightShiftReverse(int* arr, int n, int k = 1);
void ArrayLeftShiftReverse(int* arr, int n, int k = 1);


int main()
{
	const int size = 5;
	int arr[size] = { 1, 2, 3, 4, 5 };
	printf("Array:");
	showArray(arr, size);


	ArrayRightShift(arr, size);
	printf("Array after right rotation:");
	showArray(arr, size);

	ArrayLeftShift(arr, size);
	printf("Array after left rotation:");
	showArray(arr, size);


	ArrayRightShiftSwap(arr, size);
	printf("Array after right rotation by swapping:");
	showArray(arr, size);

	ArrayLeftShiftSwap(arr, size);
	printf("Array after left rotation by swapping:");
	showArray(arr, size);


	ArrayRightShiftReverse(arr, size);
	printf("Array after right rotation by reversing:");
	showArray(arr, size);

	ArrayLeftShiftReverse(arr, size);
	printf("Array after left rotation by reversing:");
	showArray(arr, size);
}


void showArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		printf(" %d", arr[i]);
	printf("\n");
}

void ArrayRightShift(int* arr, int n)
{
	if (n <= 0)
		return;
	int last = arr[n - 1];
	for (int i = n - 1; i > 0; i--)
		arr[i] = arr[i - 1];
	arr[0] = last;
}

void ArrayLeftShift(int* arr, int n)
{
	if (n <= 0)
		return;
	int first = arr[0];
	for (int i = 0; i < n - 1; i++)
		arr[i] = arr[i + 1];
	arr[n - 1] = first;
}

void ArrayRightShiftSwap(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++) {
		int temp = arr[i];
		arr[i] = arr[n - 1];
		arr[n - 1] = temp;
	}
}

void ArrayLeftShiftSwap(int* arr, int n)
{
	for (int i = n - 1; i > 0; i--) {
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
	}
}

void ArrayRightShiftReverse(int* arr, int n, int k)
{
	/* Reverse first n - 1 elements */
	for (int i = 0, j = (n - 1 - k); i < j; i++, j--) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	/* Reverse the entire array */
	for (int i = 0, j = (n - 1); i < j; i++, j--) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

void ArrayLeftShiftReverse(int* arr, int n, int k)
{
	for (int i = k, j = (n - 1); i < j; i++, j--) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	for (int i = 0, j = (n - 1); i < j; i++, j--) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}