#include <stdio.h>
#include <limits>

void showArray(int* arr, int n);
void swapElements(int& lhs, int& rhs);

/* Sort array of 3 diffrent elements using Dutch National Flag Algorithm */
void sort012(int* arr, int n);

/* Sort array of 3 diffrent elements using two pointers */
void sort0123ByPointers(int* arr, int n);

/* Sort array of 3 diffrent elements by counting */
void sort0123ByCounting(int* arr, int n);


int main()
{
	const int size = 10;
	int arr[size] = { 0, 1, 2, 0, 2, 2, 1, 0, 0, 1 };
	printf("Array:");
	showArray(arr, size);

	int arr2[size];
	for (int i = 0; i < size; i++)
		arr2[i] = arr[i];
	sort012(arr2, size);
	printf("Sorted array with 0's, 1's and 2's: ");
	showArray(arr2, size);

	int arr3[size];
	for (int i = 0; i < size; i++)
		arr3[i] = arr[i];
	sort0123ByPointers(arr3, size);
	printf("Sorted array by pointers: ");
	showArray(arr3, size);

	int arr4[size];
	for (int i = 0; i < size; i++)
		arr4[i] = arr[i];
	sort0123ByCounting(arr4, size);
	printf("Sorted array by pointers: ");
	showArray(arr4, size);
}


void showArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		printf(" %d", arr[i]);
	printf("\n");
}

void swapElements(int& lhs, int& rhs)
{
	int temp = lhs;
	lhs = rhs;
	rhs = temp;
}


void sort012(int* arr, int n)
{
	int low = 0, mid = 0, high = n - 1;

	while (mid <= high) {
		switch (arr[mid]) {
		case 0:
			swapElements(arr[low++], arr[mid++]);
			break;

		case 1:
			mid++;
			break;

		case 2:
			swapElements(arr[mid], arr[high--]);
		}
	}
}

void sort0123ByPointers(int* arr, int n)
{
	int left = 0, right = n - 1;

	for (int i = 0; i <= right && i < n;) {
		if (arr[i] == 0)
			swapElements(arr[i++], arr[left++]);
		else if (arr[i] == 2)
			swapElements(arr[i], arr[right--]);
		else
			++i;
	}
}

void sort0123ByCounting(int* arr, int n)
{
	int count[3] = { 0, 0, 0 };

	for (int i = 0; i < n; i++) {
		switch (arr[i]) {
		case 0:
			++count[0];
			break;
			
		case 1:
			++count[1];
			break;

		case 2:
			++count[2];
			break;
		}
	}

	int i = 0;
	while (count[0]--)
		arr[i++] = 0;

	while (count[1]--)
		arr[i++] = 1;

	while (count[2]--)
		arr[i++] = 2;
}