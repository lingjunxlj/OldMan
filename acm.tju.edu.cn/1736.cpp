#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int cb[300][300];
int c;
void visit(int si,int sj,int moves)
{
    if(si<0||sj<0||si>=c||sj>=c||moves>=cb[si][sj])return;
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
   	int x;
   	cin>>x;
    int si,sj,ei,ej;
    while(x--)
    {
        cin >>c>> si >> sj>>ei>>ej;
		memset(cb,10000,sizeof(cb));      
        visit(si,sj,0);
        printf("%d\n",cb[ei][ej]);
    }
    return 0;
}

