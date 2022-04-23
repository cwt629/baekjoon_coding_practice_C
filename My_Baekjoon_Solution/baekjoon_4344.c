#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 4344번: 평균은 넘겠지 */

int main() {
	int casenum, students, i, total; int* score; double rate, average; char* ptr; char buffer[10000];
	// test case의 개수
	scanf("%d%*c", &casenum);
	
	while (casenum > 0) {
		// 변수 초기화
		total = 0; students = 0; rate = 0;
		// 각 test case의 입력을 string화
		fgets(buffer, 10000, stdin);

		// 학생 수를 받아온다
		ptr = strtok(buffer, " ");
		students = atoi(ptr);

		// score 배열 할당
		score = (int*)malloc(sizeof(int) * students);

		// 각 학생들의 점수 입력 및 합계 갱신
		for (i=0; i<students; i++){
			ptr = strtok(NULL, " ");
			score[i] = atoi(ptr);
			total += score[i];
		}

		// 평균 계산
		average = (double)total / (double)students;

		// 평균을 넘는 학생들의 비율 계산
		for (i = 0; i < students; i++) {
			if ((double)score[i] > average) rate++;
		}
		rate = rate / (double)students * 100.0f;

		printf("%.3f%%\n", rate);

		// case 하나 clear
		free(score);
		casenum--;
	}
	
}