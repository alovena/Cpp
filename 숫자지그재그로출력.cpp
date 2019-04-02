#include <iostream>
using namespace std;
void outputZigZag(int n, int k);
int main(void)
{
	int t;
	int n, k;
	cin >> t;
	for (int i = 0; i<t; i++)
	{
		cin >> n >> k;
		outputZigZag(n, k);
	}
	return 0;
}
void outputZigZag(int n, int k)
{
	
	int A0 = 1;
	int result=0;
	for (int i = 0; i < k ; i++) {
		result += i;
	}
	int real_A0= A0 + result;

	if (k % 2 == 0) {
		cout << real_A0 + (k - 1);
		for (int i = 1; i <k; i++) {
			cout << "*" << real_A0 + (k - 1) - i;
			
		}
		cout << endl;
	}
	else {
		cout << real_A0 ;
		for (int i = 1; i < k; i++) {
			cout << "*" << real_A0 +i;
		}
		cout << endl;
	}

}