#include <stdio.h>

/* 1008¹ø: A/B */

int main() {
	int a, b; double result;
	scanf("%d %d", &a, &b);
	result = (double)a / (double)b;
	printf("%.9f", result);
}