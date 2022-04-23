#include <stdio.h>
#include <stdlib.h>

/* 1920번: 수 찾기 */

/* 새로 알게 된 사실!
지나치게 큰 크기의 배열을 main 함수 내에서 선언하면
배열이 스택 영역에 생성되기 때문에, 크기 제한에 걸린다.
그래서, 이렇게 전역 변수로 설정해야 에러가 나지 않는다. */
// (근데 그냥 scanf 여러번 하면 돼서 이건 필요없게 됐다...)
// char given[MAX_STRING_LENGTH]; char toSearch[MAX_STRING_LENGTH];


/* 3rd try: 배열 -> mergesort -> binary search */

void mergesort(int total_elements, int* result);
void merge(int upperHalf, int lowerHalf, int* upper, int* lower, int* result);
int binarySearch(int toFind, int total_elements, int* myArray);

int main() {
	int n, m, received; int* myArray;

	// 자연수 n 입력
	scanf("%d", &n);

	// 배열 할당
	myArray = (int*)malloc(sizeof(int) * n);

	// 이후에 입력한 정수들을 배열에 저장
	for (int i = 0; i < n; i++)
		scanf("%d", &myArray[i]);

	// 배열 정렬
	mergesort(n, myArray);

	// 자연수 m 입력
	scanf("%d", &m);

	// m개의 정수를 받으며, 각각에 대해 탐색 결과 출력
	for (int i = 0; i < m; i++) {
		scanf("%d", &received);
		printf("%d\n", binarySearch(received, n, myArray));
	}

	// 마무리
	free(myArray);
}

// mergesort 내에서, 두 배열을 오름차순으로 합치는 함수
void merge(int upperHalf, int lowerHalf, int* upper, int* lower, int* result) {
	int i = 0, j = 0, index = 0;

	// 정렬된 각 배열에서 순서대로 원소를 넣되, 오름차순으로 복사
	while (i < upperHalf && j < lowerHalf) {
		// 첫째 배열의 현재 원소가 더 작은 경우 먼저 복사해줌
		if (upper[i] < lower[j])
			result[index++] = upper[i++];
		// 둘째 배열의 현재 원소가 더 작거나 같은 경우 먼저 복사해줌
		else
			result[index++] = lower[j++];
	}

	// 첫째 배열을 모두 복사한 경우, 둘째 배열 마저 복사
	if (i == upperHalf) {
		while (j < lowerHalf) result[index++] = lower[j++];
	}
	// 둘째 배열을 모두 복사한 경우, 첫째 배열 마저 복사
	else {
		while (i < upperHalf) result[index++] = upper[i++];
	}
}

// mergesort 방법으로 배열을 정렬하는 함수
void mergesort(int total_elements, int* result) {
	// 원소 수가 2개 이상인 배열에 대해서만 정렬 필요
	if (total_elements > 1) {
		int* upper, * lower;
		// 주어진 배열을 반으로 나눌 때, 각 배열의 원소 수
		int upperHalf = total_elements / 2;
		int lowerHalf = total_elements - upperHalf;

		// 각 배열 할당
		upper = (int*)malloc(sizeof(int) * upperHalf);
		lower = (int*)malloc(sizeof(int) * lowerHalf);

		// 각 배열에 원소 복사
		for (int i = 0; i < upperHalf; i++)
			upper[i] = result[i];
		
		for (int i = 0; i < lowerHalf; i++)
			lower[i] = result[upperHalf + i];

		// 각 배열에 대해 recursive하게 정렬 진행
		mergesort(upperHalf, upper);
		mergesort(lowerHalf, lower);

		// 정렬된 두 배열 합치기
		merge(upperHalf, lowerHalf, upper, lower, result);

		// 마무리
		free(upper);
		free(lower);
	}
}

// 주어진 배열에서 이진 탐색하고, 탐색 결과를 반환하는 함수
int binarySearch(int toFind, int total_elements, int* myArray) {
	// 시작과 끝 배정
	int start = 0, end = total_elements - 1;
	// 가운데 선언
	int mid;

	// 이진 탐색
	while (start <= end) {
		// 가운데 탐색
		mid = (start + end) / 2;
		
		// 찾고자 하는 수가 해당 위치에 있으면, 탐색 성공
		if (myArray[mid] == toFind) return 1;

		// 찾고자 하는 수가 더 크면, 현위치보다 오른쪽에 있는 것
		if (myArray[mid] < toFind)
			start = mid + 1;
		// 찾고자 하는 수가 더 작으면, 현위치보다 왼쪽에 있는 것
		else
			end = mid - 1;
	}
	// while문을 벗어날 때까지 탐색하지 못하면, 탐색 실패
	return 0;
}





/* 2nd try: binary search tree - 이것도 시간 초과가 뜸... 
그런데 트리도 불균형 트리기 때문에
결국 O(n)의 시간 복잡도를 띈다고 하는거같다.
(ex. 100000 - 99999 - 99998 - ..... - 3 - 2 - 1 순서대로 저장된 경우)
그래서, 다시 배열로 돌아가
배열을 mergesort를 이용해 빠르게 정렬시키고
거기서 이진 탐색을 하는 방식으로 노선을 틀어본다. */

/*
// binary search tree 구성
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

	// 자연수 n 입력
	scanf("%d", &n);

	// root 생성
	root = (treepointer)malloc(sizeof(struct node));
	root->left = root->right = NULL;

	// n개의 정수를 tree에 저장
	for (int i = 0; i < n; i++) {
		scanf("%d", &received);
		// 생성되어있는 트리가 있다면, 거기에 덧붙이기
		if (i>0)
			AddToBST(received, root);
		// 생성되어있는 트리가 없다면, 새로 만들기
		else {
			root->data = received;
		}
	}

	// 자연수 m 입력
	scanf("%d", &m);

	// m개의 수들을 입력받고, 결과 출력
	for (int i = 0; i < m; i++) {
		scanf("%d", &received);
		// 트리에서 탐색 및 결과 출력
		printf("%d\n", SearchBST(received, root));
	}
	
	// 마무리
	free(root);
}

// binary search tree에 요소를 삽입하는 함수
void AddToBST(int number, treepointer root) {
	treepointer temp;
	treepointer prev = root, current = root;
	int need_to_add = 1;

	// 추가할 노드 생성
	temp = (treepointer)malloc(sizeof(struct node));
	temp->left = temp->right = NULL;
	temp->data = number;

	// 노드가 들어갈 위치 탐색
	while (current) {
		// 노드를 이어주기 위해, 이전 노드인 prev 저장
		prev = current;
		// 크기를 비교하여 더 작으면 왼쪽, 더 크면 오른쪽으로 이동 + 만약 중복값이라면, 추가하지 않고 return한다
		if (number == current->data) {
			need_to_add = 0;
			break;
		}
		else if (number > current->data) current = current->right;
		else current = current->left;
	}
	
	// 노드 이어주기
	if (need_to_add) {
		if (number > prev->data) prev->right = temp;
		else prev->left = temp;
	}
}

// binary search tree에서 주어진 숫자를 탐색하고, 있으면 1, 없으면 0을 반환하는 함수
int SearchBST(int number, treepointer root) {
	treepointer current = root;

	while (current) {
		// 탐색 성공 시
		if (current->data == number) return 1;
		// 현재 숫자보다 작은 수를 탐색한다면, 왼쪽으로 이동
		if (current->data > number) current = current->left;
		// 현재 숫자보다 큰 수를 탐색한다면, 오른쪽으로 이동
		else current = current->right;
	}
	// 노드가 없어 current를 벗어날 때까지 반환하지 못했다면, 탐색 실패이므로 0 반환
	return 0;
}

*/













/* 1st try: 배열 사용 및 insertion sort - 시간 초과 */

/* 시간 초과 뜸.
아무래도 배열을 사용해서 시간이 오래 걸리는듯 하다.
굳이 배열을 만들고 그것을 정렬하는 것보다는,
애초에 tree를 만드는게 낫지 않을까?
그래서 다음 시도에는 binary search tree를 쓰기로 한다. */

/*void InsertAndSort(int* A, int number, int* total_elements);
int Find(int* A, int number, int total_elements);

int main() {
	char* temp;
	int n, m, picked; int* A; int total_elements = 0;
	
	// 자연수 n 입력
	scanf("%d", &n);

	// A 배열 할당
	A = (int*)malloc(sizeof(int) * n);

	// A에 순서대로 저장하되, 순서를 생각하여 저장
	for (int i = 0; i < n; i++) {
		scanf("%d", &picked);
		InsertAndSort(A, picked, &total_elements);
	}

	// 자연수 m 입력
	scanf("%d", &m);

	// m개의 정수에 대해 탐색 시작
	for (int i = 0; i < m; i++) {
		scanf("%d", &picked);
		printf("%d\n", Find(A, picked, total_elements));
	}
}

// A에 숫자를 삽입하되, 오름차순이 되도록 삽입하는 함수
void InsertAndSort(int* A, int number, int* total_elements) {
	int i = 0;
	
	// 숫자를 삽입할 인덱스 탐색
	while (i < *total_elements && A[i] < number) i++;

	// 해당 인덱스보다 오른쪽에 있는 수들을 모두 한칸씩 오른쪽으로 밀어낸다
	for (int j = (*total_elements) - 1; j >= i && j >= 0; j--) {
		A[j + 1] = A[j];
	}

	// 해당 인덱스에 숫자 삽입
	A[i] = number;

	// 전체 항목 수 increment
	(*total_elements)++;
}

// 인자로 넘어온 숫자가 A에 있는지 확인하고 그 결과를 반환하는 함수
int Find(int* A, int number, int total_elements) {
	int i = 0;

	// 인자로 넘어온 숫자가 있을 가능성이 있는 부분 탐색
	while (i < total_elements && A[i] < number) i++;

	// 현위치의 숫자는 인자의 숫자보다 크거나 같다. 이를 이용해 판별
	if (i < total_elements && A[i] == number)
		return 1;
	// 현위치의 숫자가 같지 않거나, 현위치가 존재하지 않는 경우
	return 0;
}*/