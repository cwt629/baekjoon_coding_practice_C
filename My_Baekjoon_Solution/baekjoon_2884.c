#include <stdio.h>

/* 2884번: 알람 시계 */

int main() {
	int h, m;
	scanf("%d %d", &h, &m);
	if (m < 45) {
		h = h - 1;
		m = m + 15;
	}
	else m = m - 45;

	if (h < 0) h = h + 24;

	printf("%d %d", h, m);
}