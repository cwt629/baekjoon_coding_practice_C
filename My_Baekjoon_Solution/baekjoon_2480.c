#include <stdio.h>


/* 2480��: �ֻ��� ���� */

int GetDie(int a, int b, int c, int *same);
int max(int a, int b, int c);

int main() {
	int a, b, c, die, prize, same;

	// �ֻ��� �� �Է�
	scanf("%d %d %d", &a, &b, &c);

	/* ���� ���� ������, ��꿡 �� �� �� ���
	 die���� ��꿡 �� �� ���� ����, 
	 same���� ���� ���� ������ ����ȴ�. */
	die = GetDie(a, b, c, &same);

	// ���� ���� 3���� ���� ���
	if (same == 3)
		prize = 10000 + die * 1000;
	// ���� ���� 2���� ���� ���
	else if (same == 2)
		prize = 1000 + die * 100;
	// ��� �ٸ� ���� ���� ���
	else
		prize = die * 100;

	// ��� ���
	printf("%d", prize);
}

// �ִ밪 ��ȯ �Լ�
int max(int a, int b, int c) {
	if (a > b && a > c)
		return a;
	if (b > c)
		return b;
	return c;
}

// ��꿡 ���� �� �ֻ��� ���� ���ϴ� �Լ�
int GetDie(int a, int b, int c, int* same) {
	if (a == b && b == c) {
		*same = 3;
		return a;
	}
	if (a == b) {
		*same = 2;
		return a;
	}
	if (b == c) {
		*same = 2;
		return b;
	}
	if (c == a) {
		*same = 2;
		return c;
	}
	*same = 1;
	return max(a, b, c);
}