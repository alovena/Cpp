#include<iostream>
using namespace std;
//�Ͽ��� :0 ������1 ...�����:6
int Calc(int year) {
	int Jan_first_day = 5; //1582�� 1��1���� �ݿ����̶�����!
	int startYear = 1582;
	int yearCount = (year - 1) - startYear + 1;
	int Nowisyearcount = (int)((year - 1) / 4) - (int)((year - 1) / 100) + int((year - 1) / 400);
	//1582~year ����
	int Startisyearcount = (int)(startYear / 4) - (int)(startYear / 100) + (int)(startYear / 400);
	//1582���� ����

	int isYearCount = Nowisyearcount - Startisyearcount;
	int normal_year = yearCount - isYearCount;
	int result = normal_year + isYearCount * 2; //���+2*����
	int realyearday = (result % 7 + Jan_first_day) % 7; 
	return realyearday;
}
int main(void) {
	 
	int t,year;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> year;
		cout << Calc(year) << endl;
	}
	return 0;
}