#include <stdio.h>


/* 2480번: 주사위 세개 */

int GetDie(int a, int b, int c, int *same);
int max(int a, int b, int c);

int main() {
	int a, b, c, die, prize, same;

	// 주사위 눈 입력
	scanf("%d %d %d", &a, &b, &c);

	/* 같은 눈의 개수와, 계산에 들어갈 눈 수 계산
	 die에는 계산에 들어갈 눈 수가 들어가고, 
	 same에는 같은 눈의 개수가 저장된다. */
	die = GetDie(a, b, c, &same);

	// 같은 눈이 3개가 나온 경우
	if (same == 3)
		prize = 10000 + die * 1000;
	// 같은 눈이 2개가 나온 경우
	else if (same == 2)
		prize = 1000 + die * 100;
	// 모두 다른 눈이 나온 경우
	else
		prize = die * 100;

	// 상금 출력
	printf("%d", prize);
}

// 최대값 반환 함수
int max(int a, int b, int c) {
	if (a > b && a > c)
		return a;
	if (b > c)
		return b;
	return c;
}

// 계산에 들어가게 될 주사위 눈을 구하는 함수
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