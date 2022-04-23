#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 1929��: �Ҽ� ���ϱ� */



// ��ũ�� ����Ʈ ����
typedef struct node {
	int data;
	struct node* next;
};

typedef struct node* nodepointer;

int main() {
	int m, n, prime_flag; nodepointer current, primes, rear, temp;
	
	// ��� �Ҵ� �� �ʱ� ���(�Ҽ� 2 ����) ����(prime�� ������ ����)
	primes = (nodepointer)malloc(sizeof(struct node));
	primes->data = 2; primes->next = NULL;

	// rear�� �ʱ� ����
	rear = primes;

	// �� �ڿ��� �Է�
	scanf("%d %d", &m, &n);

	// n ������ ��� �Ҽ��� ��ũ�� ����Ʈ�� �����Ѵ�
	for (int i = 3; i <= n; i++) {
		// ���� �ʱ�ȭ
		current = primes; prime_flag = 1;

		// ��ũ�� ����Ʈ�� �ִ� ���μ���� ���� ������(�ڱ� �ڽ��� ������ ���μ��� �ִ밪�� �ڱ� �ڽ��� �����ٰ��̴�!)
		while (current && current->data <= sqrt(i)) {
			if (i % (current->data) == 0)
			{
				prime_flag = 0;
				break;
			}
			current = current->next;
		}

		// �Ҽ��� ���, ��ũ�� ����Ʈ�� �̾���
		if (prime_flag) {
			temp = (nodepointer)malloc(sizeof(struct node));
			temp->data = i; temp->next = NULL;
			rear->next = temp; 
			rear = rear->next;
		}
	}

	// m �̻� n ������ �Ҽ��� ��� ���
	current = primes;
	// m���� ũ�ų� �������� ������ ã��
	while (current->data < m) current = current->next;
	
	// n ���ϱ��� ��� ���
	while (current && current->data <= n) {
		printf("%d\n", current->data);
		current = current->next;
	}

	// ������
	free(primes);
}