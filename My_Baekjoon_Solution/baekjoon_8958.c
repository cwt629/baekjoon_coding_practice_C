#include <stdio.h>
#include <string.h>

/* 8958¹ø: OXÄûÁî */

int main() {
	char buffer[80]; int casenum, total, point;
	
	scanf("%d", &casenum);
	while (casenum > 0) {
		total = 0; point = 1;
		scanf("%s", buffer);

		for (int i = 0; i < strlen(buffer); i++) {
			if (buffer[i] == 'O') total += point++;
			else point = 1;
		}

		printf("%d\n", total);
		casenum--;
	}
}