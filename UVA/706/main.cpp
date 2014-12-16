#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

// 硬编码把0123456789的矩阵表示保存在digit中。
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
		// 输出2*s + 3列
		for (i = 0; i < 2 * s + 3; i++) {
			// 输出每一行的每个数字
			for (j = 0; j < len; j++) {
				int num = str[j] - '0';
				// 输出数字的顶部中部和底部
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
				// 输出数字的上部
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
				// 输出数字的下部
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
