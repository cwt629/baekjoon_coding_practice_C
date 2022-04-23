#include <stdio.h>
#include <stdlib.h>


/* 1463번: 1로 만들기 */

/* 2nd try : BFS로 하되, 해당 레벨 어디선가 완료되면 바로 break 걸기? BFS를 쓰므로 queue를 이용해볼까? */

#define MAX_VALUE 1000000

int queue[MAX_VALUE];
int front = -1, rear = -1;
int queue_is_empty() {
	return ((front == rear) ? 1 : 0);
}

int queue_is_full() {
	return ((rear == MAX_VALUE - 1) ? 1 : 0);
}

void queueInsert(int element) {
	if (queue_is_full()) {
		fputs("Error: Queue is Full", stderr);
		exit(-1);
	}
	queue[++rear] = element;
}

int queueDelete() {
	if (queue_is_empty()) {
		fputs("Error: Queue is Empty", stderr);
		exit(-1);
	}
	return queue[++front];
}


int main() {
	int n, current; int* inter_min;

	// 정수 입력
	scanf("%d", &n);

	// Dynamic Programming 구현을 위해, 중간에 구한 횟수들을 저장할 배열(inter_min) 설정: index 0은 1에 대한 결과, ...
	inter_min = (int*)malloc(sizeof(int) * n);

	// 초기값 설정(시작값인 1에 대한 결과는 0, 나머지는 초기 값 -1로 설정)
	inter_min[0] = 0;
	for (int i = 1; i < n; i++)
		inter_min[i] = -1;

	// 시작할 때를 위해 초기값 1을 큐에 삽입
	queueInsert(1);

	// BFS 방식으로 루프 돌기 시작
	while (!queue_is_empty()){
		// queue에서 현재 숫자를 가져오기(인덱스는 이 수에 1을 뺀 값에 해당!)
		current = queueDelete();
		// 정답이 구해졌다면, 루프 탈출
		if (current == n) break;

		// 지금 하는 일련의 과정은 모두 레벨이 낮은 순서로 진행되므로, 구해지지 않은 수에 대한 결과는 지금 구해진 결과가 무조건 최소 루트가 될 것이다.
		// 3 곱하기(구해지지 않았다면)
		if (current*3 - 1 < n && inter_min[current*3 - 1] < 0) {
			queueInsert(current * 3);
			inter_min[current * 3 - 1] = inter_min[current - 1] + 1;
		}
		
		// 2 곱하기(구해지지 않았다면)
		if (current * 2 - 1 < n && inter_min[current * 2 - 1] < 0) {
			queueInsert(current * 2);
			inter_min[current * 2 - 1] = inter_min[current - 1] + 1;
		}

		// 1 더하기(구해지지 않았다면)
		if (inter_min[current] < 0) {
			queueInsert(current + 1);
			inter_min[current] = inter_min[current - 1] + 1;
		}
	}

	// 결과 출력
	printf("%d", inter_min[n - 1]);

	// 마무리
	free(inter_min);
}









/* 1st try: Brute Force (시간이 드럽게 오래걸림) */
/*#define MAX_VALUE 1000000

int StartFrom(int a, int n);
int min(int a, int b, int c);

int main() {
	int n;

	// 정수 입력
	scanf("%d", &n);

	// 최소 횟수 받아오기
	printf("%d", StartFrom(1, n));
}

int min(int a, int b, int c) {
	if (a < b && a < c)
		return a;
	if (b < c)
		return b;
	return c;
}

int StartFrom(int a, int n) {
	int val1, val2, val3;
	// 초기 상태(3을 곱한 경우, 2를 곱한 경우, 1을 더한 경우 중 불가능한 경우 최소값 비교 대상에서 제외하기 위함)
	val1 = val2 = val3 = MAX_VALUE;

	if (a == n) return 0;
	if (a * 3 <= n)
		val1 = StartFrom(a * 3, n) + 1;
	if (a * 2 <= n)
		val2 = StartFrom(a * 2, n) + 1;
	val3 = StartFrom(a + 1, n) + 1;

	return min(val1, val2, val3);
}*/

