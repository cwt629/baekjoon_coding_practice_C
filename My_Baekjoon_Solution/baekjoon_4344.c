#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 4344��: ����� �Ѱ��� */

int main() {
	int casenum, students, i, total; int* score; double rate, average; char* ptr; char buffer[10000];
	// test case�� ����
	scanf("%d%*c", &casenum);
	
	while (casenum > 0) {
		// ���� �ʱ�ȭ
		total = 0; students = 0; rate = 0;
		// �� test case�� �Է��� stringȭ
		fgets(buffer, 10000, stdin);

		// �л� ���� �޾ƿ´�
		ptr = strtok(buffer, " ");
		students = atoi(ptr);

		// score �迭 �Ҵ�
		score = (int*)malloc(sizeof(int) * students);

		// �� �л����� ���� �Է� �� �հ� ����
		for (i=0; i<students; i++){
			ptr = strtok(NULL, " ");
			score[i] = atoi(ptr);
			total += score[i];
		}

		// ��� ���
		average = (double)total / (double)students;

		// ����� �Ѵ� �л����� ���� ���
		for (i = 0; i < students; i++) {
			if ((double)score[i] > average) rate++;
		}
		rate = rate / (double)students * 100.0f;

		printf("%.3f%%\n", rate);

		// case �ϳ� clear
		free(score);
		casenum--;
	}
	
}