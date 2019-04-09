#include<iostream>
#include<stdlib.h>
using namespace std;
int Count_Zero(int n);
int main(void) {
	int t;
	int n;
	cin >> t;
	for (int i = 0; i < t; i++) {
	cin >> n;
	cout << Count_Zero(n) << endl;
	
	}
}
int Count_Zero(int n) {
	int *arr = (int *)malloc(sizeof(int)*n);
	int num_two = 0;
	int num_five = 0;
	for (int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	for (int i = 0; i < n; i++) {
		while (arr[i] % 2 == 0) {
			num_two++;
			arr[i] /= 2;
			
		}
		while (arr[i] % 5 == 0) {
			num_five++;
			arr[i] /= 5;
		}
	}
	if (num_two > num_five) {
		return num_five;
	}
	else {
		return num_two;
	}

}
