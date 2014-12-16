#include<iostream>
#include<map>
#include <utility>
#include<cmath>
using namespace std;
map<int,int> mat1,mat2;
int N ,M ,C;
void Bio()
{
    mat1.clear();mat2.clear();
    mat1[0]=1;

    for(int i=1;i<=M;i++)
    {
        for(map<int,int> :: iterator p=mat1.begin();p!=mat1.end();p++)
        {
            mat2[p->first+1]+=mat1[p->first];
            mat2[p->first-1]-=mat1[p->first];
        }
        mat1=mat2;mat2.clear();
    }


    for(int i=1;i<=C-M;i++)
    {
        for(map<int,int> :: iterator p=mat1.begin();p!=mat1.end();p++)
        {
            mat2[p->first+1]+=mat1[p->first];
            mat2[p->first-1]+=mat1[p->first];
        }
        mat1=mat2;mat2.clear();
    }


}
void Solve()
{
    double ans=0,con=1;int left=C;
    for(int i=1;i<=M;i++)
    {
        con=con*(C-i+1)/i;
        while(con>1e8 && left)
        {
            con=con/2;
            left--;
        }

    }
    for(int i=1;i<=left;i++) con=con/2;

    for(map<int,int> :: iterator p=mat1.begin();p!=mat1.end();p++)
    {
        double cur=p->second;
        cur=cur*con;
        ans+=cur*( pow( 1.0*(p->first)/C,   N) +1e-11 ) ;
    }
    printf("%lf\n",ans) ;


}
int main()
{
    while(scanf("%d",&C)!=EOF && C)
    {
        scanf("%d%d",&N,&M);
        if(M>N || M >C || N % 2!=M%2)
        {
            printf("0.000\n");
            continue ;
        }
        Bio() ;
        Solve() ;
    }
    return 0;
}
