#include <iostream>
using namespace std;
int lengthOfIntervalIntersection(int a, int b, int c, int d);
int main(void) {
	int t;
	int a, b, c, d;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b >> c >> d;
		cout << lengthOfIntervalIntersection(a, b, c, d) << endl;
	}
	return 0;
}
int lengthOfIntervalIntersection(int a, int b, int c, int d) {
	int lenA = b - a;
	int lenB = d - c;
	if (lenA >= lenB) {
		if (a <= c && d <= b) return d - c;
		else if (c <= b&&b<=d) return b - c;
		else if (c <= a&&a<=d) return d-a;
		else	return -1;
	}
	else {
		if (c <= a && b <= d) return b - a;
		else if (a <= d && d <= b) return d - a;
		else if (a <= c && c <= b)return b-c;
		else return -1;
	}
}