// author: watashi
#include <cctype>
#include <cstdio>
#include <cstring>

void gao(int ch) {
	if (ch < $_[1]) {	// Time Limit Exceeded
		while (true);
	} else if (ch < $_[2]) { // Memory Limit Exceeded
		char* p = new char[128 << 20];
		memset(p, 0xff, 128 << 20);
	} else if (ch < $_[3]) { // Output Limit Exceeded
		while (true) {
			fputs("[Output Limit Exceeded] (http://watashi.ws/wabots) quick brown fox jumps over the lazy dog", stdout);
		}
	} else if (ch < $_[4]) { // Runtime Error (ACCESS_VIOLATION)
		int p[1 << 10] = {-1};
		putchar(p[1 << 20]);
	} else if (ch < $_[5]) { // Runtime Error (STACK_OVERFLOW)
		gao(ch);
	} else if (ch < $_[6]) { // Runtime Error (INTEGER_DIVIDE_BY_ZERO)
		int p = sizeof(char);
		printf("%d", sizeof(int) / --p);
	} else { // Wrong Answer
		return;
	}
}

int main() {
    int off = $_[0];
    for (int i = 0; i < off; ++i) {
        getchar();
    }
    gao(tolower(getchar()));
	return 0;
}
