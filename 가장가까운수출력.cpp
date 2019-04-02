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
	if(n*k <0) //���� �����ΰ��
		B = (k)*(n / k - 1);
	else
		B = (k)*(n / k + 1);
	//�� ������ �Ÿ�
	int disA = n - A;
	int disB = B - n;
	//�� ������ �Ÿ�
	//�Ÿ��̹Ƿ� ���밪
	if (disA < 0)
		disA = -disA;
	else if (disB < 0)
		disB = -disB;
	
	if (disA >= disB)
		cout << B << endl;
	else 
		cout << A << endl;

}