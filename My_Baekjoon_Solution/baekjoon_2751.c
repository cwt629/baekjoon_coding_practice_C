#include <stdio.h>
#include <stdlib.h>

/* 2751��: �� �����ϱ� 2 */

// merge sort�� �̿��غ���.

void mergesort(int total_elements, int* myArray);
void merge(int upperHalf, int lowerHalf, int* upper, int* lower, int* myArray);

int main() {
	int n; int* myArray;

	// n �Է�
	scanf("%d", &n);

	// �迭 �Ҵ�
	myArray = (int*)malloc(sizeof(int) * n);

	// �迭�� �� ���� �Է¹ޱ�
	for (int i = 0; i < n; i++) 
		scanf("%d", &myArray[i]);
	
	// �迭 �����ϱ�(mergesort �̿�)
	mergesort(n, myArray);

	// ��� ���
	for (int i = 0; i < n; i++)
		printf("%d\n", myArray[i]);
	
	// ������
	free(myArray);
}

// mergesort �Լ� ������, �� �迭�� ������ ���� ��ġ�� �Լ�
void merge(int upperHalf, int lowerHalf, int* upper, int* lower, int* myArray) {
	int i = 0, j = 0, index = 0;

	// ������ �Ǿ��ִ� �� �迭����, ũ�⸦ ���ذ��� ��ģ��(���� �ͺ���)
	while (i < upperHalf && j < lowerHalf) {
		if (upper[i] < lower[j])
			myArray[index++] = upper[i++];
		else
			myArray[index++] = lower[j++];
	}

	// ��� �� �迭�� ��� ���簡 �Ǿ��� ���̴�. ������ �迭�� ������� ����
	// ù��° �迭�� ��� ������ ����
	if (i == upperHalf)
		while (j < lowerHalf) myArray[index++] = lower[j++];
	// �ι�° �迭�� ��� ������ ����
	else
		while (i < upperHalf) myArray[index++] = upper[i++];
}

// �־��� �迭�� mergesort�ϴ� �Լ�
void mergesort(int total_elements, int* myArray) {
	// ���޵� �迭�� ũ�Ⱑ 2 �̻��� ��츸 ���� ����
	if (total_elements > 1) {
		int* upper, * lower;

		// �迭�� �ѷ� ���� ��, ù° �迭�� ���� ����(�Ҽ��� ���� ����)
		int upperHalf = total_elements / 2;
		// �迭�� �ѷ� ���� ��, ��° �迭�� ���� ����
		int lowerHalf = total_elements - upperHalf;

		// �� �迭 �Ҵ�
		upper = (int*)malloc(sizeof(int) * upperHalf);
		lower = (int*)malloc(sizeof(int) * lowerHalf);

		// �� �迭 ���ҵ� ����
		for (int i = 0; i < upperHalf; i++)
			upper[i] = myArray[i];

		for (int i = 0; i < lowerHalf; i++)
			lower[i] = myArray[upperHalf + i];

		// recursive�ϰ� �� �迭�� ���� mergesort
		mergesort(upperHalf, upper);
		mergesort(lowerHalf, lower);

		// ���ĵ� �� �迭�� ��ģ��
		merge(upperHalf, lowerHalf, upper, lower, myArray);

		// �Լ� ������
		free(upper);
		free(lower);
	}
}


