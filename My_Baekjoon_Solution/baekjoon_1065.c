#include <stdio.h>

int first_digit(int n);
int second_digit(int n);
int third_digit(int n);

/* 1065��: �Ѽ� */

int main() {
	int n, count = 0;
	
	// �ڿ��� �Է�
	scanf("%d", &n);

	// 1 �̻� n ������ �� �ڿ����� ���� ������ ����
	for (int i = 1; i <= n; i++) {
		// �� �ڸ� ���� �� �ڸ� ���� ��� �Ѽ��� �ȴ�
		if (i < 100)
			count++;
		// �� �ڸ� ���� 1000�ۿ� �� �� ������, �̸����� �Ѽ��� �ƴϴ�
		else if (i<1000){
			// ���������� ������ �̿��ϸ�, �� �ڸ� ���� �޾ƿ��� �Լ��� ���� �Ѽ��� �ɷ�����
			if (first_digit(i) + third_digit(i) == second_digit(i) * 2)
				count++;
		}
	}

	// ��� ���
	printf("%d", count);
}

// �� �ڸ� �ڿ����� ���� �ڸ� ���� ��ȯ�ϴ� �Լ�
int first_digit(int n) {
	// int�� �����ͳ����� �������� �Ҽ��� ���ϸ� ������
	return n / 100;
}

// �� �ڸ� �ڿ����� ���� �ڸ� ���� ��ȯ�ϴ� �Լ�
int second_digit(int n) {
	// �� �ڸ� �ڿ����� ���� �ڸ� ���� �����ϰ�, 10���� ������
	return (n - first_digit(n) * 100) / 10;
}

// �� �ڸ� �ڿ����� ���� �ڸ� ���� ��ȯ�ϴ� �Լ�
int third_digit(int n) {
	// �ܼ��� % ������ �̿��Ѵ�
	return n % 10;
}