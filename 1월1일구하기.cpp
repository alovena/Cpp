#include<iostream>
using namespace std;
//일요일 :0 월요일1 ...토요일:6
int Calc(int year) {
	int Jan_first_day = 5; //1582년 1월1일은 금요일이라지정!
	int startYear = 1582;
	int yearCount = (year - 1) - startYear + 1;
	int Nowisyearcount = (int)((year - 1) / 4) - (int)((year - 1) / 100) + int((year - 1) / 400);
	//1582~year 갯수
	int Startisyearcount = (int)(startYear / 4) - (int)(startYear / 100) + (int)(startYear / 400);
	//1582까지 갯수

	int isYearCount = Nowisyearcount - Startisyearcount;
	int normal_year = yearCount - isYearCount;
	int result = normal_year + isYearCount * 2; //평수+2*윤년
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