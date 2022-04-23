#include <stdio.h>
#include <stdlib.h>

/* 22873번: A+B와 쿼리 */


/* 문제 발생:
Integer Overflow!
예시는 잘 작동하지만,
더 큰 숫자를 사용함에 있어서 overflow 발생한 듯.
아무래도 정수가 아니라, string으로서 접근해야 할 듯 함.*/

/* @@@@@@@@@@@@@@@@@@@@ 두번째 문제 발생: @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
답은 너무나 잘 나오지만,
시간이 너무 오래 걸리는 듯 하다.
carry를 저장하는 방법까지 동원하여 for문이 돌아가는 횟수를 줄여봤지만
그 역시 역부족이었다.
이후 추가적인 구현으로, carry가 바뀌지 않으면 더이상 진행하지 않도록 수정했지만
이 역시 역부족이었다.
어떻게 하면 시간을 더 단축할 수 있을까? */

int main() {
	int n, q, split_count, digit, changeTo; char target;
	char* A, * B, * C; int* A_split, B_split;

	/* 3rd try : 8개씩 쪼개서 숫자로 계산해보기 */

	// n과 q 입력
	scanf("%d %d", &n, &q);

	// A, B, C 배열 할당
	A = (char*)malloc(sizeof(char) * (n + 1));
	B = (char*)malloc(sizeof(char) * (n + 1));
	C = (char*)malloc(sizeof(char) * (n + 2));
	// split 배열들은 각 숫자들을 8자리 수로 쪼개 저장하는 배열이다
	split_count = (n % 8 == 0) ? (n / 8) : (n / 8 + 1);
	// A_split과 B_split 배열 할당
	A_split = (int*)malloc(sizeof(int) * split_count);
	B_split = (int*)malloc(sizeof(int) * split_count);

	// A, B 입력
	scanf("%s%*c", A);
	scanf("%s%*c", B);

	// C 계산
	

	// 마무리
	free(A); 
	free(B); 
	free(C);
	free(A_split);
	free(B_split);
}








/*int main() {
	
	// 2nd try

	int n, q, digit, num, sum, carry, index, changed; 
	char* A, * B, * C; char target; int* cry;
	int no_need_to_proceed = 0;

	// N과 Q 입력
	scanf("%d %d", &n, &q);

	// A, B를 입력받기 위해 각 string을 할당받는다
	A = (char*)malloc(sizeof(char) * (n + 1));
	B = (char*)malloc(sizeof(char) * (n + 1));
	C = (char*)malloc(sizeof(char) * (n + 2));
	cry = (int*)malloc(sizeof(int) * n);

	// A, B를 입력받는다
	scanf("%s%*c", A);
	scanf("%s%*c", B);

	// 초기 C 계산
	carry = 0;
	for (int j = n-1; j >= 0; j--) {
		// 뒤에서부터 각 자리 수끼리(carry까지) 더함. 문자열이라는 사실에 유의하기.
		sum = (A[j] - '0') + (B[j] - '0') + carry;

		// 그 합이 10을 넘어가면, 다음 계산에 1을 더해줘야 하므로 carry 반영
		if (sum >= 10) {
			sum -= 10;
			carry = 1;
		}
		else carry = 0;

		// 후의 과정을 위해 carry 저장
		cry[j] = carry;

		// sum을 문자열로서 C에 반영
		C[j + 1] = sum + '0';
	}
	C[0] = (carry == 1) ? '1' : '0';

	// 쿼리
	for (int i = 0; i < q; i++) {
		// 초기화
		changed = 0; no_need_to_proceed = 0;

		// 쿼리 입력
		scanf("%c %d %d%*c", &target, &digit, &num);
		
		// 입력받은 자리를 인덱스로 변경
		index = n - digit;

		// 쿼리 수행
		if (target == 'A')
			A[index] = num + '0';
		else if (target == 'B')
			B[index] = num + '0';

		// 합계산
		carry = (index == n - 1) ? 0 : cry[index + 1];
		for (int j = index; j >= 0 && !no_need_to_proceed; j--) {
			sum = (A[j] - '0') + (B[j] - '0') + carry;
			
			// 그 합이 10을 넘어가면, 다음 계산에 1을 더해줘야 하므로 carry 반영
			if (sum >= 10) {
				sum -= 10;
				carry = 1;
			}
			else carry = 0;

			// 이 과정에서 carry가 바뀌지 않는다면, 그 뒤는 더이상 바뀌지 않으므로 과정 수행 불필요. 바뀐다면, carry 재저장
			if (carry == cry[j])
				no_need_to_proceed = 1;
			else cry[j] = carry;

			// sum의 문자화
			sum += '0';

			// 현재 sum과 기존 C의 해당 자리를 비교
			if (sum != C[j + 1]) {
				changed++;
				// sum을 C에 반영
				C[j + 1] = sum;
			}
		}
		if (!no_need_to_proceed) {
			cry[0] = carry;
			if (C[0] != carry + '0') {
				changed++;
				C[0] = carry + '0';
			}
		}
		// 결과 출력
		printf("%d\n", changed);
	}

	// 종료
	free(A);
	free(B);
	free(C);
	free(cry);
}*/

// 1st try: 숫자로서 접근했을 때

//int N, Q, A, B, C, digit, num, controlling, changed, temp, temp_c;
	//char object;

	// N과 Q 입력
	//scanf("%d %d", &N, &Q);

	// A와 B 입력
	//scanf("%d", &A);
	//scanf("%d%*c", &B);

	// query 개수만큼 쿼리 입력
	/*for (int i = 0; i < Q; i++) {
		C = A + B;
		controlling = 1; changed = 0;

		scanf("%c %d %d%*c", &object, &digit, &num);*/

		// 바뀔 자리수가 몇의 자리수인지 구함
		/*for (int j = 1; j < digit; j++)
			controlling *= 10; */

			/* 숫자 변경 방법 :
			   바꾸고자 하는 자리의 숫자는, 원래 숫자를 바뀔 자리수로 나눈 뒤
			   그 나눈 값의 1의 자리수가 된다.
			   해당 자리수를 0으로 바꾼다고 생각하고 전체 수에서 빼준 뒤,
			   바뀔 자리수만큼 다시 더해준다. */

			   /*if (object == 'A') {
				   A = A - ((A / controlling) % 10) * controlling + num * controlling;
			   }
			   else if (object == 'B') {
				   B = B - ((B / controlling) % 10) * controlling + num * controlling;
			   }

			   controlling = 1; */
			   //for (int j = 0; j < N + 1; j++) {
				   // 같은 방법으로 각 자리수를 오른쪽부터 비교함
				   /*temp = ((A + B) / controlling) % 10;
				   temp_c = (C / controlling) % 10;

				   if (temp != temp_c) changed++;

				   controlling *= 10;
			   }

			   printf("%d\n", changed);
		   }*/
