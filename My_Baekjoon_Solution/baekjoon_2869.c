#include <stdio.h>

/* 2869번: 달팽이는 올라가고 싶다 */


/* 주의할 것:
while문을 이용할 수도 있지만,
이 문제의 제한 시간이 0.15초라는 것에 착안하여
계산하는 쪽으로 문제를 풀어야 할 듯 하다. */

int main() {
	int a, b, v, day, ascent;

	// 순서대로 낮에 올라가는 거리, 밤에 미끄러지는 거리, 나무 막대 높이 입력
	scanf("%d %d %d", &a, &b, &v);

	// 올라가자마자 도착하는 경우
	if (a >= v)
		day = 1;
	else {
		// 먼저 올라가고, 그 후에는 미끄러졌다 올라가는 길이를 계산한다.
		ascent = a - b;
		// 정확하게 정상에 도착하는 경우
		if ((v - a) % ascent == 0)
			day = 1 + (v - a) / ascent;
		// 정상을 가고도 더 갈 수 있었을 경우
		else
			day = 2 + (v - a) / ascent;
	}
	
	// 결과 출력
	printf("%d", day);
}