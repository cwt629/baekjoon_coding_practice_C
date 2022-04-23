#include <stdio.h>
#include <stdlib.h>

/* 2751번: 수 정렬하기 2 */

// merge sort를 이용해보자.

void mergesort(int total_elements, int* myArray);
void merge(int upperHalf, int lowerHalf, int* upper, int* lower, int* myArray);

int main() {
	int n; int* myArray;

	// n 입력
	scanf("%d", &n);

	// 배열 할당
	myArray = (int*)malloc(sizeof(int) * n);

	// 배열의 각 원소 입력받기
	for (int i = 0; i < n; i++) 
		scanf("%d", &myArray[i]);
	
	// 배열 정렬하기(mergesort 이용)
	mergesort(n, myArray);

	// 결과 출력
	for (int i = 0; i < n; i++)
		printf("%d\n", myArray[i]);
	
	// 마무리
	free(myArray);
}

// mergesort 함수 내에서, 두 배열을 순서에 맞춰 합치는 함수
void merge(int upperHalf, int lowerHalf, int* upper, int* lower, int* myArray) {
	int i = 0, j = 0, index = 0;

	// 정렬이 되어있는 각 배열에서, 크기를 비교해가며 합친다(작은 것부터)
	while (i < upperHalf && j < lowerHalf) {
		if (upper[i] < lower[j])
			myArray[index++] = upper[i++];
		else
			myArray[index++] = lower[j++];
	}

	// 어느 한 배열은 모두 복사가 되었을 것이다. 나머지 배열은 순서대로 복사
	// 첫번째 배열은 모두 복사한 상태
	if (i == upperHalf)
		while (j < lowerHalf) myArray[index++] = lower[j++];
	// 두번째 배열은 모두 복사한 상태
	else
		while (i < upperHalf) myArray[index++] = upper[i++];
}

// 주어진 배열을 mergesort하는 함수
void mergesort(int total_elements, int* myArray) {
	// 전달된 배열의 크기가 2 이상인 경우만 정렬 수행
	if (total_elements > 1) {
		int* upper, * lower;

		// 배열을 둘로 나눌 때, 첫째 배열의 원소 갯수(소수점 이하 버림)
		int upperHalf = total_elements / 2;
		// 배열을 둘로 나눌 때, 둘째 배열의 원소 갯수
		int lowerHalf = total_elements - upperHalf;

		// 각 배열 할당
		upper = (int*)malloc(sizeof(int) * upperHalf);
		lower = (int*)malloc(sizeof(int) * lowerHalf);

		// 각 배열 원소들 복사
		for (int i = 0; i < upperHalf; i++)
			upper[i] = myArray[i];

		for (int i = 0; i < lowerHalf; i++)
			lower[i] = myArray[upperHalf + i];

		// recursive하게 각 배열에 대해 mergesort
		mergesort(upperHalf, upper);
		mergesort(lowerHalf, lower);

		// 정렬된 각 배열을 합친다
		merge(upperHalf, lowerHalf, upper, lower, myArray);

		// 함수 마무리
		free(upper);
		free(lower);
	}
}


