#include <stdio.h>

int first_digit(int n);
int second_digit(int n);
int third_digit(int n);

/* 1065번: 한수 */

int main() {
	int n, count = 0;
	
	// 자연수 입력
	scanf("%d", &n);

	// 1 이상 n 이하의 각 자연수에 대해 루프를 돈다
	for (int i = 1; i <= n; i++) {
		// 한 자리 수나 두 자리 수는 모두 한수가 된다
		if (i < 100)
			count++;
		// 네 자리 수는 1000밖에 올 수 없으나, 이마저도 한수가 아니다
		else if (i<1000){
			// 등차중항의 성질을 이용하며, 각 자리 수를 받아오는 함수를 통해 한수를 걸러낸다
			if (first_digit(i) + third_digit(i) == second_digit(i) * 2)
				count++;
		}
	}

	// 결과 출력
	printf("%d", count);
}

// 세 자리 자연수의 백의 자리 수를 반환하는 함수
int first_digit(int n) {
	// int형 데이터끼리의 나눗셈은 소수점 이하를 버린다
	return n / 100;
}

// 세 자리 자연수의 십의 자리 수를 반환하는 함수
int second_digit(int n) {
	// 세 자리 자연수의 백의 자리 수를 제거하고, 10으로 나눈다
	return (n - first_digit(n) * 100) / 10;
}

// 세 자리 자연수의 일의 자리 수를 반환하는 함수
int third_digit(int n) {
	// 단순히 % 연산을 이용한다
	return n % 10;
}