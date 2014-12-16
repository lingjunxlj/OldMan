#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int cb[8][8];
void visit(int si,int sj,int moves)
{
    if(si<0||sj<0||si>=8||sj>=8||moves>=cb[si][sj])return;
    cb[si][sj]=moves;
    visit(si+2,sj+1,moves+1);
    visit(si+1,sj+2,moves+1);
    visit(si-1,sj+2,moves+1);
    visit(si-2,sj+1,moves+1);
    visit(si-2,sj-1,moves+1);
    visit(si-1,sj-2,moves+1);
    visit(si+1,sj-2,moves+1);
    visit(si+2,sj-1,moves+1);
}
    
int main()
{
    char a[10],b[10];
    int si,sj,ei,ej;
    while(cin >> a >> b)
    {
        memset(cb,10000,sizeof(cb));
        si=a[0]-'a';sj=a[1]-'1';
        ei=b[0]-'a';ej=b[1]-'1';
        visit(si,sj,0);
        printf("To get from %s to %s takes %d knight moves.\n",a,b,cb[ei][ej]);
    }
    return 0;
}
