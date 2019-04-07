#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//�ּ��� ���κ��� -> �Լ������κ� ������ ���ּ���~!

//�Լ� 4���̻� ����!
void init(int**arr1, int**arr2,int m,int n) { //�����Լ��� �̿��Ͽ� ������ �߻����� -100~100�ǰ��� �迭A,B�� ���� �̶� �����ͺ����� �̿��Ͽ� �迭�ǰ��� �����ϱ⶧����
	srand(time(NULL));						// call by reference
	int random = rand();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr1[i][j] = (rand()%200)-100; //rand() % n �� 0���� n�ǰ��� ��� �� 0���� 200�� ���� ��¿� -100�� �ϰԵǸ� -100 ~ 100�ǰ��� �迭 A�� ����
			arr2[i][j] = (rand() % 200) - 100;;
		}
	}
}
void output(int **arr, int i, int j) {
		printf("%d ", arr[i][j]); //������ ���
}
void input_sum(int **arr1, int **arr2,int **arr3, int m,int n) { //���ϱ� ���
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr3[i][j]=arr1[i][j]+arr2[i][j]; //������ ������ ���� �Ѿ�� �迭 A,B,C�� ���� �迭 C�� ���� �־���(call by referenc).
			output(arr1,i,j);				////���̹Ƿ� �迭 A+B=C
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

void input_sub(int **arr1, int **arr2, int **arr3, int m, int n) { //������ ������ ���� �Ѿ�� �迭 A,B,C�� ���� �迭 C�� ���� �־���(call by referenc).
	for (int i = 0; i < m; i++) {								////�����̹Ƿ� �迭 A-B=C
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

	int m, n; //while������ ���� m,n�� ���� 2~5���� �����ϳ��� ���� ���Ұ�� �ݺ����� �� ó������ ���ư�
	while (1) {
		printf("����� �ప(m):");
		scanf_s("%d", &m);
		if (m < 2 || m>5) {
			printf("�Է� ����(����: 2 <= m <= 5)\n");
			continue;
		}
		printf("\n����� ����(n):");
		scanf_s("%d", &n);
		if (n < 2 || n>5) {
			printf("�Է� ����(����: 2 <= m <= 5)\n");
			continue;
		}
		if (m >= 2 && m <= 5 && n >= 2 && n <= 5) {
			break;
		}
	
	}
	//m,n�� ��� 2~5���̶��
	//�迭�� �������� �Ҵ�
	//����� ��Ʃ��������� ���ϴ� ũ�⸸ŭ �迭�� �����ϴ� ����� ���������ʴ´�
	//���� ��� int a[m] �� while������ �Է��ߴ� m�� ������ a�̶�� �迭�� ������ ����
	//int a[m] <<�����Ͽ���
	//������ gcc������ ������ �����ϴ� ���� ����� ��Ʃ��� ������ �����Ұ�..(�����ϻ� ������ �ȵ�)
	//���� �������� �迭�� �Ҵ� �ؾ���
	//�������� 2�����迭A,B,C �Ҵ�
	int **A = malloc(sizeof(int*)*m); //�������� 2�����迭A,B,C col(����ŭ)�Ҵ�
	int **B = malloc(sizeof(int*)*m);
	int **C = malloc(sizeof(int*)*m);
	for (int i = 0; i < m; i++) {
		A[i] = malloc(sizeof(int)*n); //�������� 2�����迭A,B,C�� row(�ุŭ)�Ҵ�
		B[i] = malloc(sizeof(int)*n);
		C[i] = malloc(sizeof(int)*n);
	}
	init(A, B,m,n); //�迭A,B�� ���� ���� �����Լ��� �̿�,�׸��� �迭 A,B�� �Ѱ��ٶ� call by reference �� �ּҰ����� ����
					//���� �ּҰ����� �迭�� �����ϱ⶧���� �迭 A,B�� ������ �迭 A��B�� ������ ��� �ٲ� ���´�.
	printf("\n\n%d * %d ��� ���� ���\n",m,n);
	input_sum(A,B,C, m, n); //��κе� call by reference �迭 A,B,C�� �Ű������� �Ѱ���
	printf("\n\n%d * %d ��� ���� ���\n", m, n);
	input_sub(A, B, C, m, n);
	
	return 0;
}