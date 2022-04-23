#include <stdio.h>
#include <stdlib.h>


/* 1463��: 1�� ����� */

/* 2nd try : BFS�� �ϵ�, �ش� ���� ��𼱰� �Ϸ�Ǹ� �ٷ� break �ɱ�? BFS�� ���Ƿ� queue�� �̿��غ���? */

#define MAX_VALUE 1000000

int queue[MAX_VALUE];
int front = -1, rear = -1;
int queue_is_empty() {
	return ((front == rear) ? 1 : 0);
}

int queue_is_full() {
	return ((rear == MAX_VALUE - 1) ? 1 : 0);
}

void queueInsert(int element) {
	if (queue_is_full()) {
		fputs("Error: Queue is Full", stderr);
		exit(-1);
	}
	queue[++rear] = element;
}

int queueDelete() {
	if (queue_is_empty()) {
		fputs("Error: Queue is Empty", stderr);
		exit(-1);
	}
	return queue[++front];
}


int main() {
	int n, current; int* inter_min;

	// ���� �Է�
	scanf("%d", &n);

	// Dynamic Programming ������ ����, �߰��� ���� Ƚ������ ������ �迭(inter_min) ����: index 0�� 1�� ���� ���, ...
	inter_min = (int*)malloc(sizeof(int) * n);

	// �ʱⰪ ����(���۰��� 1�� ���� ����� 0, �������� �ʱ� �� -1�� ����)
	inter_min[0] = 0;
	for (int i = 1; i < n; i++)
		inter_min[i] = -1;

	// ������ ���� ���� �ʱⰪ 1�� ť�� ����
	queueInsert(1);

	// BFS ������� ���� ���� ����
	while (!queue_is_empty()){
		// queue���� ���� ���ڸ� ��������(�ε����� �� ���� 1�� �� ���� �ش�!)
		current = queueDelete();
		// ������ �������ٸ�, ���� Ż��
		if (current == n) break;

		// ���� �ϴ� �Ϸ��� ������ ��� ������ ���� ������ ����ǹǷ�, �������� ���� ���� ���� ����� ���� ������ ����� ������ �ּ� ��Ʈ�� �� ���̴�.
		// 3 ���ϱ�(�������� �ʾҴٸ�)
		if (current*3 - 1 < n && inter_min[current*3 - 1] < 0) {
			queueInsert(current * 3);
			inter_min[current * 3 - 1] = inter_min[current - 1] + 1;
		}
		
		// 2 ���ϱ�(�������� �ʾҴٸ�)
		if (current * 2 - 1 < n && inter_min[current * 2 - 1] < 0) {
			queueInsert(current * 2);
			inter_min[current * 2 - 1] = inter_min[current - 1] + 1;
		}

		// 1 ���ϱ�(�������� �ʾҴٸ�)
		if (inter_min[current] < 0) {
			queueInsert(current + 1);
			inter_min[current] = inter_min[current - 1] + 1;
		}
	}

	// ��� ���
	printf("%d", inter_min[n - 1]);

	// ������
	free(inter_min);
}









/* 1st try: Brute Force (�ð��� �巴�� �����ɸ�) */
/*#define MAX_VALUE 1000000

int StartFrom(int a, int n);
int min(int a, int b, int c);

int main() {
	int n;

	// ���� �Է�
	scanf("%d", &n);

	// �ּ� Ƚ�� �޾ƿ���
	printf("%d", StartFrom(1, n));
}

int min(int a, int b, int c) {
	if (a < b && a < c)
		return a;
	if (b < c)
		return b;
	return c;
}

int StartFrom(int a, int n) {
	int val1, val2, val3;
	// �ʱ� ����(3�� ���� ���, 2�� ���� ���, 1�� ���� ��� �� �Ұ����� ��� �ּҰ� �� ��󿡼� �����ϱ� ����)
	val1 = val2 = val3 = MAX_VALUE;

	if (a == n) return 0;
	if (a * 3 <= n)
		val1 = StartFrom(a * 3, n) + 1;
	if (a * 2 <= n)
		val2 = StartFrom(a * 2, n) + 1;
	val3 = StartFrom(a + 1, n) + 1;

	return min(val1, val2, val3);
}*/

