#include<stdio.h>
int arr[8] = { 5,4,3,1,6,7,8,2 };
void partition(int low, int high, int *pp) {
	int item = arr[low];
	//*pp = low;

	int j = low;
	int temp;

	for (int i = low + 1; i <= high; i++) {
		if (item > arr[i]) {
			j++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;

		}
	}
	*pp = j;

	temp = arr[low];
	arr[low] = arr[*pp];
	arr[*pp] = temp;
}
void Quicksort(int low, int high) {
	int pp;
	if (low < high) {
		partition(0, 7, &pp);

		if (pp == 0) {
			return 0;
		}
		Quicksort(0, (pp)-1);
		Quicksort((pp)+1, 7);
	}
}

int main(void) {

	Quicksort(0, 7);
	for (int i = 0; i < 7; i++) {
		printf("%d", arr[i]);
	}
	return 0;
}
