#include<iostream>
#include<cmath>
#include <cstdlib>
using namespace std;
#define MAX 100000000
#define MIN -100000000

char map[5000][5000];

int leftdot;
int rightdot;
int topdot;
int bottomdot;

void figure(int x,int y,int deep)
{

    if(deep==1)
    {

        map[x][y]='/';
        map[x][y+1]='_';
        map[x][y+2]='_';
        map[x][y+3]='\\';
        map[x-1][y+1]='/';
        map[x-1][y+2]='\\';
    }
    else
    {
        int dis=(int)pow((double)2,deep);
        figure(x,y,deep-1);
        figure(x,y+dis,deep-1);
        figure(x-dis/2,y+dis/2,deep-1);
    }
}


int main ()
{

    int n;
    int i,j;
    leftdot=MAX;
    rightdot=MIN;
    topdot=MAX;
    bottomdot=MIN;
    memset(map,' ',sizeof(map));
    figure(2500,2500,10);

    while(scanf("%d",&n))
    {

        if(n==0)
            break;

        topdot=2500-(int)pow((double)2,10)+1;
        bottomdot=topdot+(int)pow((double)2,n)-1;
        leftdot=2500+(int)pow((double)2,10)-(int)pow((double)2,n);
        rightdot=leftdot+(int)pow((double)2,n+1)-1;
        for(i=topdot;i<=bottomdot;i++)
        {

            for(j=rightdot;j>=leftdot&&map[i][j]!='\\';j--)
            {
                map[i][j]='a';
            }
        }
        for(i=topdot;i<=bottomdot;i++)
        {

            for(j=leftdot;j<=rightdot;j++)
            {
                if (map[i][j]!='a')
                printf("%c",map[i][j]);
            }
            printf("\n");
        }
        printf("\n");

    }
}
