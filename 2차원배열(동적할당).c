#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//주석은 메인부터 -> 함수구현부분 순으로 봐주세요~!

//함수 4개이상 구현!
void init(int**arr1, int**arr2,int m,int n) { //랜덤함수를 이용하여 난수를 발생시켜 -100~100의값을 배열A,B에 넣음 이때 포인터변수를 이용하여 배열의값을 참조하기때문에
	srand(time(NULL));						// call by reference
	int random = rand();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr1[i][j] = (rand()%200)-100; //rand() % n 은 0부터 n의값을 출력 즉 0부터 200의 값을 출력에 -100을 하게되면 -100 ~ 100의값을 배열 A에 넣음
			arr2[i][j] = (rand() % 200) - 100;;
		}
	}
}
void output(int **arr, int i, int j) {
		printf("%d ", arr[i][j]); //한줄을 출력
}
void input_sum(int **arr1, int **arr2,int **arr3, int m,int n) { //더하기 결과
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr3[i][j]=arr1[i][j]+arr2[i][j]; //포인터 변수에 의해 넘어온 배열 A,B,C에 의해 배열 C의 값을 넣어줌(call by referenc).
			output(arr1,i,j);				////합이므로 배열 A+B=C
		}
		printf("\t");
		for (int j = 0; j < n; j++) {
			output(arr2, i, j);
		}
		printf("\t");
		for (int j = 0; j < n; j++) {
			output(arr3, i, j);
		}
		printf("\n");
	}
}

void input_sub(int **arr1, int **arr2, int **arr3, int m, int n) { //포인터 변수에 의해 넘어온 배열 A,B,C에 의해 배열 C의 값을 넣어줌(call by referenc).
	for (int i = 0; i < m; i++) {								////뺄셈이므로 배열 A-B=C
		for (int j = 0; j < n; j++) {
			arr3[i][j] = arr1[i][j] - arr2[i][j];
			output(arr1, i, j);
		}
		printf("\t");
		for (int j = 0; j < n; j++) {
			output(arr2, i, j);
		}
		printf("\t");
		for (int j = 0; j < n; j++) {
			output(arr3, i, j);
		}
		printf("\n");
	}
}

int main() {

	int m, n; //while문안의 조건 m,n의 값은 2~5사이 둘중하나가 만족 못할경우 반복문의 맨 처음으로 돌아감
	while (1) {
		printf("행렬의 행값(m):");
		scanf_s("%d", &m);
		if (m < 2 || m>5) {
			printf("입력 오류(조건: 2 <= m <= 5)\n");
			continue;
		}
		printf("\n행렬의 열값(n):");
		scanf_s("%d", &n);
		if (n < 2 || n>5) {
			printf("입력 오류(조건: 2 <= m <= 5)\n");
			continue;
		}
		if (m >= 2 && m <= 5 && n >= 2 && n <= 5) {
			break;
		}
	
	}
	//m,n이 모두 2~5사이라면
	//배열을 동적으로 할당
	//비쥬얼 스튜디오에서는 원하는 크기만큼 배열을 생성하는 기능은 지원하지않는다
	//예를 들어 int a[m] 즉 while문에서 입력했던 m을 가지고 a이라는 배열을 만들지 못함
	//int a[m] <<컴파일오류
	//하지만 gcc에서는 지원이 가능하다 단지 비쥬얼 스튜디오 에서만 지원불가..(컴파일상 지원이 안됨)
	//따라서 동적으로 배열을 할당 해야함
	//동적으로 2차원배열A,B,C 할당
	int **A = malloc(sizeof(int*)*m); //동적으로 2차원배열A,B,C col(열만큼)할당
	int **B = malloc(sizeof(int*)*m);
	int **C = malloc(sizeof(int*)*m);
	for (int i = 0; i < m; i++) {
		A[i] = malloc(sizeof(int)*n); //동적으로 2차원배열A,B,C의 row(행만큼)할당
		B[i] = malloc(sizeof(int)*n);
		C[i] = malloc(sizeof(int)*n);
	}
	init(A, B,m,n); //배열A,B에 값을 넣음 랜덤함수를 이용,그리고 배열 A,B를 넘겨줄때 call by reference 즉 주소값으로 참조
					//따라서 주소값으로 배열을 참조하기때문에 배열 A,B를 넣으면 배열 A와B의 값들이 모두 바뀌어서 나온다.
	printf("\n\n%d * %d 행렬 덧셈 결과\n",m,n);
	input_sum(A,B,C, m, n); //요부분도 call by reference 배열 A,B,C를 매개변수로 넘겨줌
	printf("\n\n%d * %d 행렬 뺄셈 결과\n", m, n);
	input_sub(A, B, C, m, n);
	for(int i=0;i<n;i++){
		free(A[i]);
		free(B[i]);
		free(C[i]);
	}
	free(A);
	free(B);
	free(C);
	
	return 0;
}
