#include <stdio.h>
#include <math.h>

/* 1019번: 책 페이지 */

int PageCalculate(int pages);

int main() {
	int n; int pages[10] = { 0 };

	// 자연수 n 입력
	scanf("%d", &n);

	printf("%f", log10(n));
}