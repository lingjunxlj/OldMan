#include <stdio.h>
int main(){unsigned int t, x = 1;scanf("%u", &t);while(t--){unsigned int n;scanf("%u", &n);printf("Case %u: %u\n", x++, n <= 2? n: 2*n - 4);}}
