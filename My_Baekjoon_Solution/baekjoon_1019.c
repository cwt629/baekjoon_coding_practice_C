#include <stdio.h>
#include <math.h>

/* 1019��: å ������ */

int PageCalculate(int pages);

int main() {
	int n; int pages[10] = { 0 };

	// �ڿ��� n �Է�
	scanf("%d", &n);

	printf("%f", log10(n));
}