#include <stdio.h>
#include <stdlib.h>

/* 1920��: �� ã�� */

/* ���� �˰� �� ���!
����ġ�� ū ũ���� �迭�� main �Լ� ������ �����ϸ�
�迭�� ���� ������ �����Ǳ� ������, ũ�� ���ѿ� �ɸ���.
�׷���, �̷��� ���� ������ �����ؾ� ������ ���� �ʴ´�. */
// (�ٵ� �׳� scanf ������ �ϸ� �ż� �̰� �ʿ���� �ƴ�...)
// char given[MAX_STRING_LENGTH]; char toSearch[MAX_STRING_LENGTH];


/* 3rd try: �迭 -> mergesort -> binary search */

void mergesort(int total_elements, int* result);
void merge(int upperHalf, int lowerHalf, int* upper, int* lower, int* result);
int binarySearch(int toFind, int total_elements, int* myArray);

int main() {
	int n, m, received; int* myArray;

	// �ڿ��� n �Է�
	scanf("%d", &n);

	// �迭 �Ҵ�
	myArray = (int*)malloc(sizeof(int) * n);

	// ���Ŀ� �Է��� �������� �迭�� ����
	for (int i = 0; i < n; i++)
		scanf("%d", &myArray[i]);

	// �迭 ����
	mergesort(n, myArray);

	// �ڿ��� m �Է�
	scanf("%d", &m);

	// m���� ������ ������, ������ ���� Ž�� ��� ���
	for (int i = 0; i < m; i++) {
		scanf("%d", &received);
		printf("%d\n", binarySearch(received, n, myArray));
	}

	// ������
	free(myArray);
}

// mergesort ������, �� �迭�� ������������ ��ġ�� �Լ�
void merge(int upperHalf, int lowerHalf, int* upper, int* lower, int* result) {
	int i = 0, j = 0, index = 0;

	// ���ĵ� �� �迭���� ������� ���Ҹ� �ֵ�, ������������ ����
	while (i < upperHalf && j < lowerHalf) {
		// ù° �迭�� ���� ���Ұ� �� ���� ��� ���� ��������
		if (upper[i] < lower[j])
			result[index++] = upper[i++];
		// ��° �迭�� ���� ���Ұ� �� �۰ų� ���� ��� ���� ��������
		else
			result[index++] = lower[j++];
	}

	// ù° �迭�� ��� ������ ���, ��° �迭 ���� ����
	if (i == upperHalf) {
		while (j < lowerHalf) result[index++] = lower[j++];
	}
	// ��° �迭�� ��� ������ ���, ù° �迭 ���� ����
	else {
		while (i < upperHalf) result[index++] = upper[i++];
	}
}

// mergesort ������� �迭�� �����ϴ� �Լ�
void mergesort(int total_elements, int* result) {
	// ���� ���� 2�� �̻��� �迭�� ���ؼ��� ���� �ʿ�
	if (total_elements > 1) {
		int* upper, * lower;
		// �־��� �迭�� ������ ���� ��, �� �迭�� ���� ��
		int upperHalf = total_elements / 2;
		int lowerHalf = total_elements - upperHalf;

		// �� �迭 �Ҵ�
		upper = (int*)malloc(sizeof(int) * upperHalf);
		lower = (int*)malloc(sizeof(int) * lowerHalf);

		// �� �迭�� ���� ����
		for (int i = 0; i < upperHalf; i++)
			upper[i] = result[i];
		
		for (int i = 0; i < lowerHalf; i++)
			lower[i] = result[upperHalf + i];

		// �� �迭�� ���� recursive�ϰ� ���� ����
		mergesort(upperHalf, upper);
		mergesort(lowerHalf, lower);

		// ���ĵ� �� �迭 ��ġ��
		merge(upperHalf, lowerHalf, upper, lower, result);

		// ������
		free(upper);
		free(lower);
	}
}

// �־��� �迭���� ���� Ž���ϰ�, Ž�� ����� ��ȯ�ϴ� �Լ�
int binarySearch(int toFind, int total_elements, int* myArray) {
	// ���۰� �� ����
	int start = 0, end = total_elements - 1;
	// ��� ����
	int mid;

	// ���� Ž��
	while (start <= end) {
		// ��� Ž��
		mid = (start + end) / 2;
		
		// ã���� �ϴ� ���� �ش� ��ġ�� ������, Ž�� ����
		if (myArray[mid] == toFind) return 1;

		// ã���� �ϴ� ���� �� ũ��, ����ġ���� �����ʿ� �ִ� ��
		if (myArray[mid] < toFind)
			start = mid + 1;
		// ã���� �ϴ� ���� �� ������, ����ġ���� ���ʿ� �ִ� ��
		else
			end = mid - 1;
	}
	// while���� ��� ������ Ž������ ���ϸ�, Ž�� ����
	return 0;
}





/* 2nd try: binary search tree - �̰͵� �ð� �ʰ��� ��... 
�׷��� Ʈ���� �ұ��� Ʈ���� ������
�ᱹ O(n)�� �ð� ���⵵�� ��ٰ� �ϴ°Ű���.
(ex. 100000 - 99999 - 99998 - ..... - 3 - 2 - 1 ������� ����� ���)
�׷���, �ٽ� �迭�� ���ư�
�迭�� mergesort�� �̿��� ������ ���Ľ�Ű��
�ű⼭ ���� Ž���� �ϴ� ������� �뼱�� Ʋ���. */

/*
// binary search tree ����
typedef struct node {
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node* treepointer;

void AddToBST(int number, treepointer root);
int SearchBST(int number, treepointer root);

int main() {
	int n, m, received; treepointer root;

	// �ڿ��� n �Է�
	scanf("%d", &n);

	// root ����
	root = (treepointer)malloc(sizeof(struct node));
	root->left = root->right = NULL;

	// n���� ������ tree�� ����
	for (int i = 0; i < n; i++) {
		scanf("%d", &received);
		// �����Ǿ��ִ� Ʈ���� �ִٸ�, �ű⿡ �����̱�
		if (i>0)
			AddToBST(received, root);
		// �����Ǿ��ִ� Ʈ���� ���ٸ�, ���� �����
		else {
			root->data = received;
		}
	}

	// �ڿ��� m �Է�
	scanf("%d", &m);

	// m���� ������ �Է¹ް�, ��� ���
	for (int i = 0; i < m; i++) {
		scanf("%d", &received);
		// Ʈ������ Ž�� �� ��� ���
		printf("%d\n", SearchBST(received, root));
	}
	
	// ������
	free(root);
}

// binary search tree�� ��Ҹ� �����ϴ� �Լ�
void AddToBST(int number, treepointer root) {
	treepointer temp;
	treepointer prev = root, current = root;
	int need_to_add = 1;

	// �߰��� ��� ����
	temp = (treepointer)malloc(sizeof(struct node));
	temp->left = temp->right = NULL;
	temp->data = number;

	// ��尡 �� ��ġ Ž��
	while (current) {
		// ��带 �̾��ֱ� ����, ���� ����� prev ����
		prev = current;
		// ũ�⸦ ���Ͽ� �� ������ ����, �� ũ�� ���������� �̵� + ���� �ߺ����̶��, �߰����� �ʰ� return�Ѵ�
		if (number == current->data) {
			need_to_add = 0;
			break;
		}
		else if (number > current->data) current = current->right;
		else current = current->left;
	}
	
	// ��� �̾��ֱ�
	if (need_to_add) {
		if (number > prev->data) prev->right = temp;
		else prev->left = temp;
	}
}

// binary search tree���� �־��� ���ڸ� Ž���ϰ�, ������ 1, ������ 0�� ��ȯ�ϴ� �Լ�
int SearchBST(int number, treepointer root) {
	treepointer current = root;

	while (current) {
		// Ž�� ���� ��
		if (current->data == number) return 1;
		// ���� ���ں��� ���� ���� Ž���Ѵٸ�, �������� �̵�
		if (current->data > number) current = current->left;
		// ���� ���ں��� ū ���� Ž���Ѵٸ�, ���������� �̵�
		else current = current->right;
	}
	// ��尡 ���� current�� ��� ������ ��ȯ���� ���ߴٸ�, Ž�� �����̹Ƿ� 0 ��ȯ
	return 0;
}

*/













/* 1st try: �迭 ��� �� insertion sort - �ð� �ʰ� */

/* �ð� �ʰ� ��.
�ƹ����� �迭�� ����ؼ� �ð��� ���� �ɸ��µ� �ϴ�.
���� �迭�� ����� �װ��� �����ϴ� �ͺ��ٴ�,
���ʿ� tree�� ����°� ���� ������?
�׷��� ���� �õ����� binary search tree�� ����� �Ѵ�. */

/*void InsertAndSort(int* A, int number, int* total_elements);
int Find(int* A, int number, int total_elements);

int main() {
	char* temp;
	int n, m, picked; int* A; int total_elements = 0;
	
	// �ڿ��� n �Է�
	scanf("%d", &n);

	// A �迭 �Ҵ�
	A = (int*)malloc(sizeof(int) * n);

	// A�� ������� �����ϵ�, ������ �����Ͽ� ����
	for (int i = 0; i < n; i++) {
		scanf("%d", &picked);
		InsertAndSort(A, picked, &total_elements);
	}

	// �ڿ��� m �Է�
	scanf("%d", &m);

	// m���� ������ ���� Ž�� ����
	for (int i = 0; i < m; i++) {
		scanf("%d", &picked);
		printf("%d\n", Find(A, picked, total_elements));
	}
}

// A�� ���ڸ� �����ϵ�, ���������� �ǵ��� �����ϴ� �Լ�
void InsertAndSort(int* A, int number, int* total_elements) {
	int i = 0;
	
	// ���ڸ� ������ �ε��� Ž��
	while (i < *total_elements && A[i] < number) i++;

	// �ش� �ε������� �����ʿ� �ִ� ������ ��� ��ĭ�� ���������� �о��
	for (int j = (*total_elements) - 1; j >= i && j >= 0; j--) {
		A[j + 1] = A[j];
	}

	// �ش� �ε����� ���� ����
	A[i] = number;

	// ��ü �׸� �� increment
	(*total_elements)++;
}

// ���ڷ� �Ѿ�� ���ڰ� A�� �ִ��� Ȯ���ϰ� �� ����� ��ȯ�ϴ� �Լ�
int Find(int* A, int number, int total_elements) {
	int i = 0;

	// ���ڷ� �Ѿ�� ���ڰ� ���� ���ɼ��� �ִ� �κ� Ž��
	while (i < total_elements && A[i] < number) i++;

	// ����ġ�� ���ڴ� ������ ���ں��� ũ�ų� ����. �̸� �̿��� �Ǻ�
	if (i < total_elements && A[i] == number)
		return 1;
	// ����ġ�� ���ڰ� ���� �ʰų�, ����ġ�� �������� �ʴ� ���
	return 0;
}*/