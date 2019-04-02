#include<iostream>
using namespace std;
void outputPyramid(int n, int k);
int main(void) {
	int t;
	int n, k;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		outputPyramid(n, k);
	}
	return 0;
}
void outputPyramid(int n, int k) {
	int A = (k)*(n/k);
	int B;
	if(n*k <0) //곱이 음수인경우
		B = (k)*(n / k - 1);
	else
		B = (k)*(n / k + 1);
	//두 사이의 거리
	int disA = n - A;
	int disB = B - n;
	//두 사이의 거리
	//거리이므로 절대값
	if (disA < 0)
		disA = -disA;
	else if (disB < 0)
		disB = -disB;
	
	if (disA >= disB)
		cout << B << endl;
	else 
		cout << A << endl;

}