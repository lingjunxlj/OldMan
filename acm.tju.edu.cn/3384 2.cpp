#include <iostream>
using namespace std;
 
int main()
{
    int n, p, q;
    while(scanf("%d %d %d", &n, &p, &q) != EOF)
    {
        n %= (p + q);
        if(n > p || !n) printf("WIN\n");
        else printf("LOST\n");    
    }    
}
