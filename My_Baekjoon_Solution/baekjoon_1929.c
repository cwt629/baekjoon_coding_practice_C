#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 1929번: 소수 구하기 */



// 링크드 리스트 구현
typedef struct node {
	int data;
	struct node* next;
};

typedef struct node* nodepointer;

int main() {
	int m, n, prime_flag; nodepointer current, primes, rear, temp;
	
	// 노드 할당 및 초기 노드(소수 2 저장) 생성(prime의 시작점 역할)
	primes = (nodepointer)malloc(sizeof(struct node));
	primes->data = 2; primes->next = NULL;

	// rear의 초기 설정
	rear = primes;

	// 두 자연수 입력
	scanf("%d %d", &m, &n);

	// n 이하의 모든 소수를 링크드 리스트에 저장한다
	for (int i = 3; i <= n; i++) {
		// 설정 초기화
		current = primes; prime_flag = 1;

		// 링크드 리스트에 있는 소인수들로 수를 나눠봄(자기 자신을 제외한 소인수의 최대값은 자기 자신의 제곱근값이다!)
		while (current && current->data <= sqrt(i)) {
			if (i % (current->data) == 0)
			{
				prime_flag = 0;
				break;
			}
			current = current->next;
		}

		// 소수인 경우, 링크드 리스트에 이어줌
		if (prime_flag) {
			temp = (nodepointer)malloc(sizeof(struct node));
			temp->data = i; temp->next = NULL;
			rear->next = temp; 
			rear = rear->next;
		}
	}

	// m 이상 n 이하의 소수를 모두 출력
	current = primes;
	// m보다 크거나 같아지는 시작점 찾기
	while (current->data < m) current = current->next;
	
	// n 이하까지 모두 출력
	while (current && current->data <= n) {
		printf("%d\n", current->data);
		current = current->next;
	}

	// 마무리
	free(primes);
}