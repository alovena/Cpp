#include <iostream>
using namespace std;
void outputPyramid(int n, int k);
int main() {
	int t;
	int n, k;
	cin >> t;
	for (int i = 0; i<t; i++) {
		cin >> n >> k;	
		outputPyramid(n, k);
	}
	return 0;
}
void outputPyramid(int n, int k)
{
	int i;
	int result = 0;
	cout << k;
	for (i = 0; i < k - 1; i++) {
		result += (n - 1) - i;
		cout << "*" << k + result ;
	}
	cout << endl;
	
}