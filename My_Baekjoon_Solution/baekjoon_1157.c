#include <stdio.h>
#include <string.h>

/* 1157��: �ܾ� ���� */

/*
������ ��!
for���� ���ǹ� �ȿ� strlen�� ���� �Լ��� ������,
for���� �� ������ ������ Ȯ���ϱ� ���� strlen �Լ��� ȣ���ϰ� �ȴ�.
�ٵ� strlen �Լ��� string�� ���̸�ŭ�� �ð� ���⵵�� ������ �ʴ°�?
��������� �׷��� �Ǹ� O(n^2)�� �ð� ���⵵�� �Ǿ� ������.
�׷���, �Լ����� �����Ǿ� �ִ� ������ ���
�� �Լ����� for�� ���� �̸� �޾Ƴ���
�� ������� ���� �ȿ� �־��־��
�ð� ���⵵�� linear�ϰ� ���������� ���ư���!!!
*/


int main() {
	int alphabet[26] = { 0 }; char given[1000001];
	int alphabet_index, len, max = 0, max_index = 0, multiple_existence = 0; char alphabet_to_print;
	// �ܾ� �Է�
	scanf("%s", given);

	// �ܾ��� ���� �޾ƿ�(for���� �ִٰ� �Űܿ���)
	len = strlen(given);

	// �ܾ��� ù���ں��� �ѱ��ھ� Ȯ��
	for (int i = 0; i < len; i++) {
		// �빮���� ���
		if (given[i] >= 'A' && given[i] <= 'Z') {
			// �ƽ�Ű�ڵ带 Ȱ���Ͽ�, alphabet�� �ε����� �����ش�
			alphabet_index = given[i] - 'A';
			alphabet[alphabet_index]++;
		}
		// �ҹ����� ���(���Ŀ� alphabet_index�� �ʱ�ȭ���� �ʴ� ��쿡 ����ؼ�, �׳� else���� ����� �ߴ�.
		else /*if (given[i] >= 'a' && given[i] <= 'z')*/ {
			// �ƽ�Ű�ڵ带 Ȱ���Ͽ�, alphabet�� �ε����� �����ش�
			alphabet_index = given[i] - 'a';
			alphabet[alphabet_index]++;
		}
		// ���� ������ ���ĺ����� �ְ��� �����ϴ� ���
		if (alphabet[alphabet_index] > max) {
			max = alphabet[alphabet_index];
			max_index = alphabet_index;
			multiple_existence = 0;
		}
		/* �ְ��� ���������� ������ �ְ��� ���� ���� ������ ���, �ߺ��Ǿ����� ���
		(�� ��� max_index�� ���� index�� �������� ���� ����. �׷� ���� ������ +1 �Ǹ鼭 max�� ���ŵǾ��� ���̱� ����.) */
		else if (alphabet[alphabet_index] == max) 
			multiple_existence = 1;
		
	}
	
	// ���� ���� ���� ���ĺ��� �ɷ�����. ��, ���� ���� ��� ?�� �޴´�
	alphabet_to_print = (multiple_existence) ? '?' : ('A' + max_index);

	// ��� ���
	printf("%c", alphabet_to_print);
}

