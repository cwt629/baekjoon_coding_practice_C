#include <stdio.h>
#include <string.h>

/* 1152��: �ܾ��� ���� */

int main() {
	char buffer[1000001]; char* temp; int result = 0;

	// ���ڿ� �Է�
	fgets(buffer, 1000001, stdin);

	// ���� ��
	temp = strtok(buffer, " ");

	// strtok�� �̿��Ͽ� �ܾ��� ���� ���ϱ�
	while (temp) {
		// fgets �Լ��� ����ϴ� ���ͱ��� ���� �ǹǷ�, �̿� ���� ����
		if (strcmp(temp, "\n"))
			result++;
		// ���� �ܾ� �޾ƿ���
		temp = strtok(NULL, " ");
	}

	// ��� ���
	printf("%d", result);
}