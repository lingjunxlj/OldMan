#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int M, N, Q;
int D[100];
int main()
{
    int i, j;
    int d;
    while(cin>>N>>Q)
    {
        if(N == 0 && Q == 0)
            break;
        memset(D, 0, sizeof(D));
        while(N--)
        {
            cin>>M;
            while (M--)
            {
                cin>>d;
                D[d] += 1;
            }
        }
        int MAXD = 0;
        int date = 0;
        for(i = 0; i < 100; ++i)
        {
            if(D[i] >= Q && MAXD < D[i] )
            {
                MAXD = D[i];
                date = i;
            }
        }
        cout<<date<<endl;
    }
}
