#include <stdio.h>
#include <string.h>

/* 1152번: 단어의 개수 */

int main() {
	char buffer[1000001]; char* temp; int result = 0;

	// 문자열 입력
	fgets(buffer, 1000001, stdin);

	// 시작 시
	temp = strtok(buffer, " ");

	// strtok을 이용하여 단어의 개수 구하기
	while (temp) {
		// fgets 함수를 사용하니 엔터까지 들어가게 되므로, 이에 대한 조정
		if (strcmp(temp, "\n"))
			result++;
		// 다음 단어 받아오기
		temp = strtok(NULL, " ");
	}

	// 결과 출력
	printf("%d", result);
}