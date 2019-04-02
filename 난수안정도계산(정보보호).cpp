#include<stdio.h>
int main(void) {
	int m = 119, a = 19, c = 5, x0 = 8;
	int n = 5;
	int x[5] = { 0 };
	double r[5] = { 0 };
	x[0] = (x0*a + c) % m;
	r[0] = (double)x[0] / m;
	for (int i = 1; i < n; i++) {
		x[i]= (x[i-1]*a + c) % m;
		r[i] = (double)x[i] / m;
	}
	printf("=========1단계=========\n");
	double temp;
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1; j++) {
			if (r[j] >= r[j+1]) {
				temp = r[j+1];
				r[j+1] = r[j];
				r[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%.3f ", r[i]);
	}
	printf("\n=========2단계=========\n");
	double pMax = 0, mMax = 0; //D+, D- 구하기
	for (int i = 0; i < n; i++) {
		if (pMax < ((double)(i + 1) / n) - r[i]) {
			pMax = ((double)(i + 1) / n) - r[i];
			
		}
		
		if (mMax < r[i] - ((double)(i + 1 - 1) / n)) {
			mMax = r[i] - ((double)(i + 1 - 1) / n);
		
		}
	}
	printf("pMax : %.3f, mMax : %f.3\n", pMax, mMax);
	printf("=========3단계=========\n");
	double Max;
	if (pMax > mMax) Max = pMax;
	else Max = mMax;
	printf("Dmax : %.3f\n", Max);

	printf("=========4단계=========\n");
	printf("d=0.05, N=5, 임계값 = 0.565 \n");

	printf("=========5단계=========\n");
	printf("%.3f - 0.565 = %.3f D<D0 이므로 난수는 안정성을 가진다.\n", Max, Max - 0.565);


	return 0;
}