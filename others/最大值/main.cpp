#include <iostream>
#include <cstdio>
#include <emmintrin.h>
using namespace std;
int get_max(int* a,int l)
{
    assert(l%4==0);
    assert(SSE2);
    int ret,tmp[4];
    __asm__ __volatile__ ( "\txorps %%xmm0, %%xmm0\n" "LP3:\n" "\tmovdqa %%xmm0, %%xmm1\n" "\tpcmpgtd (%1), %%xmm1\n" "\tandps %%xmm1, %%xmm0\n" "\tandnps (%1), %%xmm1\n" "\torps %%xmm1, %%xmm0\n" "\taddl $16, %1\n" "\tsubl $4, %2\n" "\tjnz LP3\n" "\tmovdqu %%xmm0, (%3)\n" "\tmovl (%3), %%eax\n" "\tcmpl 4(%3), %%eax\n" "\tcmovll 4(%3), %%eax\n" "\tcmpl 8(%3), %%eax\n" "\tcmovll 8(%3), %%eax\n" "\tcmpl 12(%3), %%eax\n" "\tcmovll 12(%3), %%eax\n" "\tmovl %%eax, %0\n" :"=m"(ret) :"r"(a),"r"(l),"r"(tmp) :"%eax");
    return ret;
}
int main()
{
    int num[100];
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
        cin>>num[i];
    cout<<get_max(num, n)<<endl;
}
