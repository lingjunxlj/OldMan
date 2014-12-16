#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

// Ӳ�����0123456789�ľ����ʾ������digit�С�
char digit[5][31] = {
	"b-bbbbb-bb-bbbbb-bb-bb-bb-bb-b",
	"|b|bb|bb|bb||b||bb|bbbb||b||b|",
	"bbbbbbb-bb-bb-bb-bb-bbbbb-bb-b",
	"|b|bb||bbbb|bb|bb||b|bb||b|bb|",
	"b-bbbbb-bb-bbbbb-bb-bbbbb-bb-b"
};

int main()
{
	int s;
	char str[11];
//#ifndef ONLINE_JUDGE
	//freopen("706.txt", "r", stdin);
//#endif
	while (scanf("%d %s", &s, str) != EOF) {
		if (s == 0) {
			return 0;
		}

		int i, j, k;
		int len = strlen(str);
		// ���2*s + 3��
		for (i = 0; i < 2 * s + 3; i++) {
			// ���ÿһ�е�ÿ������
			for (j = 0; j < len; j++) {
				int num = str[j] - '0';
				// ������ֵĶ����в��͵ײ�
				if (i == 0 || i == s + 1 || i == 2 * s + 2) {
					int temp;
					if (i == 0) {
						temp = 0;
					} else if (i == s + 1) {
						temp = 2;
					} else {
						temp = 4;
					}
					printf(" ");
					for (k = 0; k < s; k++) {
						if (digit[temp][num * 3 + 1] == 'b') {
							printf(" ");
						} else {
							printf("%c", digit[temp][num * 3 + 1]);
						}
					}
					printf(" ");
				}
				// ������ֵ��ϲ�
				if (i > 0 && i < s + 1) {
					printf("%c", digit[1][num * 3] == 'b' ? ' ' : '|');
					for (k = 0; k < s; k++) {
						if (digit[1][num * 3 + 1] == 'b') {
							printf(" ");
						} else {
							printf("%c", digit[1][num * 3 + 1]);
						}
					}
					printf("%c", digit[1][num * 3 + 2] == 'b' ? ' ' : '|');
				}
				// ������ֵ��²�
				if (i > s + 1 && i < 2 * s + 2) {
					printf("%c", digit[3][num * 3] == 'b' ? ' ' : '|');
					for (k = 0; k < s; k++) {
						if (digit[3][num * 3 + 1] == 'b') {
							printf(" ");
						} else {
							printf("%c", digit[3][num * 3 + 1]);
						}
					}
					printf("%c", digit[3][num * 3 + 2] == 'b' ? ' ' : '|');
				}
				if (j != len - 1) {
					printf(" ");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
