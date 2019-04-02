#include <iostream>
using namespace std;
int angleClock(int h, int m);
int main(void)
{
	int t;
	int h, m;
	
	cin >> t;
	for (int i = 0; i<t; i++)
	{
		cin >> h >> m;
		cout << angleClock(h, m) << endl;
	}
	return 0;
}
int angleClock(int h, int m)
{
	int A = 30*h + m*(0.5);
	int B = 6 * m;
	if ((A - B) < 0)
		return (B - A);
	else
	return (A - B);
}