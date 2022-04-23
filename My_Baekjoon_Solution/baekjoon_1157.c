#include <stdio.h>
#include <string.h>

/* 1157번: 단어 공부 */

/*
깨달은 점!
for문의 조건문 안에 strlen과 같은 함수를 넣으면,
for문이 돌 때마다 조건을 확인하기 위해 strlen 함수를 호출하게 된다.
근데 strlen 함수는 string의 길이만큼의 시간 복잡도를 가지지 않는가?
결과적으로 그렇게 되면 O(n^2)의 시간 복잡도가 되어 버린다.
그래서, 함수값이 고정되어 있는 조건의 경우
그 함수값을 for문 전에 미리 받아놓고
그 상수값을 조건 안에 넣어주어야
시간 복잡도가 linear하게 정상적으로 돌아간다!!!
*/


int main() {
	int alphabet[26] = { 0 }; char given[1000001];
	int alphabet_index, len, max = 0, max_index = 0, multiple_existence = 0; char alphabet_to_print;
	// 단어 입력
	scanf("%s", given);

	// 단어의 길이 받아옴(for문에 있다가 옮겨왔음)
	len = strlen(given);

	// 단어의 첫글자부터 한글자씩 확인
	for (int i = 0; i < len; i++) {
		// 대문자인 경우
		if (given[i] >= 'A' && given[i] <= 'Z') {
			// 아스키코드를 활용하여, alphabet의 인덱스를 정해준다
			alphabet_index = given[i] - 'A';
			alphabet[alphabet_index]++;
		}
		// 소문자인 경우(이후에 alphabet_index가 초기화되지 않는 경우에 대비해서, 그냥 else문을 쓰기로 했다.
		else /*if (given[i] >= 'a' && given[i] <= 'z')*/ {
			// 아스키코드를 활용하여, alphabet의 인덱스를 정해준다
			alphabet_index = given[i] - 'a';
			alphabet[alphabet_index]++;
		}
		// 현재 더해진 알파벳으로 최고값을 갱신하는 경우
		if (alphabet[alphabet_index] > max) {
			max = alphabet[alphabet_index];
			max_index = alphabet_index;
			multiple_existence = 0;
		}
		/* 최고값을 갱신하지는 않지만 최고값과 같은 값이 나오는 경우, 중복되었음을 명시
		(이 경우 max_index와 현재 index가 같아지는 경우는 없다. 그런 경우면 어차피 +1 되면서 max가 갱신되었을 것이기 때문.) */
		else if (alphabet[alphabet_index] == max) 
			multiple_existence = 1;
		
	}
	
	// 가장 많이 나온 알파벳을 걸러낸다. 단, 여러 개인 경우 ?를 받는다
	alphabet_to_print = (multiple_existence) ? '?' : ('A' + max_index);

	// 결과 출력
	printf("%c", alphabet_to_print);
}

