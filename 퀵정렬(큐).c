#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node //��� ����
{
	int data;
	struct Node *next;
}Node;


typedef struct Queue //Queue ����ü ����
{
	Node *front; //�� ��(���� ��ġ)
	Node *rear; //�� ��(������ ��ġ)
	int count;//���� ����
}Queue;

void InitQueue(Queue *queue);//ť �ʱ�ȭ
int IsEmpty(Queue *queue); //ť�� ������� Ȯ��
void Enqueue(Queue *queue, int data); //ť�� ����
int Dequeue(Queue *queue); //ť���� ����
void quicksort(int start, int end);
void partition(int start, int end);
void printA(int* a, int n);

int array[8] = { 15,22,13,27,12,10,20,25 };
int pp = 0;

int main(void)
{
	//����Ʈ
	quicksort(0, 7);
	//�迭 ��� �Լ� (�迭, �迭 ũ��)
	printf("\n");
	printA(array, 8);
	printf("\n");
	return 0;
}

void partition(int start, int end) {
	int i, j, tmp;
	//��Ȱ�ȿ����� �Ǻ� ����
	int pivotitem = array[start];

	j = start;
	for (i = start + 1; i <= end; i++) {
		if (array[i] < pivotitem) {
			j++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}
	tmp = array[start];
	array[start] = array[j];
	array[j] = tmp;
	pp = j;
	if (start % 8 == 0) printf("\n");
	if (start % 8 == 1) printf("\n");
	//if (start == 1) printf("\n");
	//if (end == 7) printf("\n");
}

void quicksort(int start, int end) {
	//ť ����
	int top = 1;
	Queue l;
	Queue h;
	//ť �ʱ�ȭ
	InitQueue(&l);
	InitQueue(&h);
	Enqueue(&l, start);
	Enqueue(&h, end);
	while (top > 0) {
		start = Dequeue(&l);
		end = Dequeue(&h);
		top--;
		partition(start, end);
		if (start < (pp - 1)) {
			top++;
			Enqueue(&l, start);
			Enqueue(&h, pp - 1);
		}
		if ((pp + 1) < end) {
			top++;
			Enqueue(&l, pp + 1);
			Enqueue(&h, end);
		}
		printf("(%d,%d)", start + 1, end + 1);
	}
}

void printA(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%5d", a[i]);
	}
}

void InitQueue(Queue *queue)
{
	queue->front = queue->rear = NULL; //front�� rear�� NULL�� ����
	queue->count = 0;//���� ������ 0���� ����
}

int IsEmpty(Queue *queue)
{
	return queue->count == 0;    //���� ������ 0�̸� �� ����
}

void Enqueue(Queue *queue, int data)
{
	Node *now = (Node *)malloc(sizeof(Node)); //��� ����
	now->data = data;//������ ����
	now->next = NULL;

	if (IsEmpty(queue))//ť�� ������� ��
	{
		queue->front = now;//�� ���� now�� ����       
	}
	else//������� ���� ��
	{
		queue->rear->next = now;//�� ���� ������ now�� ����
	}
	queue->rear = now;//�� �ڸ� now�� ����   
	queue->count++;//���� ������ 1 ����
}

int Dequeue(Queue *queue)
{
	int re = 0;
	Node *now;
	if (IsEmpty(queue))//ť�� ����� ��
	{
		return re;
	}
	now = queue->front;//�� ���� ��带 now�� ���
	re = now->data;//��ȯ�� ���� now�� data�� ����
	queue->front = now->next;//�� ���� now�� ���� ���� ����
	free(now);//now �Ҹ�
	queue->count--;//���� ������ 1 ����
	return re;
}