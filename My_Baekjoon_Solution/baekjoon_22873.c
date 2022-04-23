#include <stdio.h>
#include <stdlib.h>

/* 22873��: A+B�� ���� */


/* ���� �߻�:
Integer Overflow!
���ô� �� �۵�������,
�� ū ���ڸ� ����Կ� �־ overflow �߻��� ��.
�ƹ����� ������ �ƴ϶�, string���μ� �����ؾ� �� �� ��.*/

/* @@@@@@@@@@@@@@@@@@@@ �ι�° ���� �߻�: @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
���� �ʹ��� �� ��������,
�ð��� �ʹ� ���� �ɸ��� �� �ϴ�.
carry�� �����ϴ� ������� �����Ͽ� for���� ���ư��� Ƚ���� �ٿ�������
�� ���� �������̾���.
���� �߰����� ��������, carry�� �ٲ��� ������ ���̻� �������� �ʵ��� ����������
�� ���� �������̾���.
��� �ϸ� �ð��� �� ������ �� ������? */

int main() {
	int n, q, split_count, digit, changeTo; char target;
	char* A, * B, * C; int* A_split, B_split;

	/* 3rd try : 8���� �ɰ��� ���ڷ� ����غ��� */

	// n�� q �Է�
	scanf("%d %d", &n, &q);

	// A, B, C �迭 �Ҵ�
	A = (char*)malloc(sizeof(char) * (n + 1));
	B = (char*)malloc(sizeof(char) * (n + 1));
	C = (char*)malloc(sizeof(char) * (n + 2));
	// split �迭���� �� ���ڵ��� 8�ڸ� ���� �ɰ� �����ϴ� �迭�̴�
	split_count = (n % 8 == 0) ? (n / 8) : (n / 8 + 1);
	// A_split�� B_split �迭 �Ҵ�
	A_split = (int*)malloc(sizeof(int) * split_count);
	B_split = (int*)malloc(sizeof(int) * split_count);

	// A, B �Է�
	scanf("%s%*c", A);
	scanf("%s%*c", B);

	// C ���
	

	// ������
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

	// N�� Q �Է�
	scanf("%d %d", &n, &q);

	// A, B�� �Է¹ޱ� ���� �� string�� �Ҵ�޴´�
	A = (char*)malloc(sizeof(char) * (n + 1));
	B = (char*)malloc(sizeof(char) * (n + 1));
	C = (char*)malloc(sizeof(char) * (n + 2));
	cry = (int*)malloc(sizeof(int) * n);

	// A, B�� �Է¹޴´�
	scanf("%s%*c", A);
	scanf("%s%*c", B);

	// �ʱ� C ���
	carry = 0;
	for (int j = n-1; j >= 0; j--) {
		// �ڿ������� �� �ڸ� ������(carry����) ����. ���ڿ��̶�� ��ǿ� �����ϱ�.
		sum = (A[j] - '0') + (B[j] - '0') + carry;

		// �� ���� 10�� �Ѿ��, ���� ��꿡 1�� ������� �ϹǷ� carry �ݿ�
		if (sum >= 10) {
			sum -= 10;
			carry = 1;
		}
		else carry = 0;

		// ���� ������ ���� carry ����
		cry[j] = carry;

		// sum�� ���ڿ��μ� C�� �ݿ�
		C[j + 1] = sum + '0';
	}
	C[0] = (carry == 1) ? '1' : '0';

	// ����
	for (int i = 0; i < q; i++) {
		// �ʱ�ȭ
		changed = 0; no_need_to_proceed = 0;

		// ���� �Է�
		scanf("%c %d %d%*c", &target, &digit, &num);
		
		// �Է¹��� �ڸ��� �ε����� ����
		index = n - digit;

		// ���� ����
		if (target == 'A')
			A[index] = num + '0';
		else if (target == 'B')
			B[index] = num + '0';

		// �հ��
		carry = (index == n - 1) ? 0 : cry[index + 1];
		for (int j = index; j >= 0 && !no_need_to_proceed; j--) {
			sum = (A[j] - '0') + (B[j] - '0') + carry;
			
			// �� ���� 10�� �Ѿ��, ���� ��꿡 1�� ������� �ϹǷ� carry �ݿ�
			if (sum >= 10) {
				sum -= 10;
				carry = 1;
			}
			else carry = 0;

			// �� �������� carry�� �ٲ��� �ʴ´ٸ�, �� �ڴ� ���̻� �ٲ��� �����Ƿ� ���� ���� ���ʿ�. �ٲ�ٸ�, carry ������
			if (carry == cry[j])
				no_need_to_proceed = 1;
			else cry[j] = carry;

			// sum�� ����ȭ
			sum += '0';

			// ���� sum�� ���� C�� �ش� �ڸ��� ��
			if (sum != C[j + 1]) {
				changed++;
				// sum�� C�� �ݿ�
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
		// ��� ���
		printf("%d\n", changed);
	}

	// ����
	free(A);
	free(B);
	free(C);
	free(cry);
}*/

// 1st try: ���ڷμ� �������� ��

//int N, Q, A, B, C, digit, num, controlling, changed, temp, temp_c;
	//char object;

	// N�� Q �Է�
	//scanf("%d %d", &N, &Q);

	// A�� B �Է�
	//scanf("%d", &A);
	//scanf("%d%*c", &B);

	// query ������ŭ ���� �Է�
	/*for (int i = 0; i < Q; i++) {
		C = A + B;
		controlling = 1; changed = 0;

		scanf("%c %d %d%*c", &object, &digit, &num);*/

		// �ٲ� �ڸ����� ���� �ڸ������� ����
		/*for (int j = 1; j < digit; j++)
			controlling *= 10; */

			/* ���� ���� ��� :
			   �ٲٰ��� �ϴ� �ڸ��� ���ڴ�, ���� ���ڸ� �ٲ� �ڸ����� ���� ��
			   �� ���� ���� 1�� �ڸ����� �ȴ�.
			   �ش� �ڸ����� 0���� �ٲ۴ٰ� �����ϰ� ��ü ������ ���� ��,
			   �ٲ� �ڸ�����ŭ �ٽ� �����ش�. */

			   /*if (object == 'A') {
				   A = A - ((A / controlling) % 10) * controlling + num * controlling;
			   }
			   else if (object == 'B') {
				   B = B - ((B / controlling) % 10) * controlling + num * controlling;
			   }

			   controlling = 1; */
			   //for (int j = 0; j < N + 1; j++) {
				   // ���� ������� �� �ڸ����� �����ʺ��� ����
				   /*temp = ((A + B) / controlling) % 10;
				   temp_c = (C / controlling) % 10;

				   if (temp != temp_c) changed++;

				   controlling *= 10;
			   }

			   printf("%d\n", changed);
		   }*/
