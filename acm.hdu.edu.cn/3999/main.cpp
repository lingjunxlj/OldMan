#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *lc,*rc;
}node, *Link;
int n, num[100001], top;
void insert( Link *L,int x )
{
    if( *L )
    {
        if( x < ( *L ) -> data )
            insert( &( *L ) -> lc , x );
        else
            insert( &( *L ) -> rc , x );
    }
    else
    {
        *L = new node;
        ( *L ) -> data = x;
        ( *L ) -> lc = ( *L ) -> rc = NULL;
    }
}
void solve(Link L)
{
    if (L)
    {
        num[top++] = L-> data;
        solve(L->lc);
        solve(L->rc);
    }
}
int main()
{

    while(~scanf("%d", &n))
    {
        Link L = NULL;
        for (int i = 0; i < n; i++)
        {
            int temp;
            scanf("%d", &temp);
            insert(&L, temp);
        }
        top = 0;
        solve(L);
        for (int i = 0; i < n; i++)
            if (i == 0)
                printf("%d", num[i]);
            else
                printf(" %d", num[i]);
        printf("\n");
    }
}
