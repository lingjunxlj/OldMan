#include <iostream>
char equ[270];
long int con={0};
long int coe={0};
int temp,s,n;
double ans;
bool flag=false;
using namespace std;
void matchdigit(int t)
{
    t++;
    if(t>=n)
    con-=temp;
    else if(equ[t]>='0'&&equ[t]<='9')
    temp*=10;
    return ;
}
main()
{
    cin >>s;
    for(int j=0;j<s;j++)
    {
        cin >>equ;
        n=strlen(equ);
        for(int i=0;i<n;i++)
        {
            if(equ[i]<='9'&&equ[i]>='0')
            {
                if(temp==1||temp==-1)
                temp*=(int)equ[i]-48;
                else if(temp<0)
                temp-=(int)equ[i]-48;
				else temp+=(int)equ[i]-48;
                matchdigit(i);
            }
            else if(equ[i]=='=')
            {
				con+=temp;
                flag=true;
                temp=0;
            }
            if(equ[i]=='x')
            {
                if(equ[i-1]=='='||i==0)
                temp=1;
                if(!flag)  coe-=temp;
                else coe+=temp;
                temp=0;
            }
            if(equ[i]=='+')
            {
                if(!flag) con+=temp;
                else con-=temp;
                temp=1;
            }
            if(equ[i]=='-')
            {
                if(!flag) con+=temp;
                else con-=temp;
                temp=-1;
            }
        }
        if(coe==0&&con==0)
        cout<<"IDENTITY"<<endl;
        else if(con!=0&&coe==0)
        cout<<"IMPOSSIBLE"<<endl;
        else
        {
            int sk;
            sk=con/coe;
            ans=(double)con/(double)coe;
            if(sk>ans)
            cout<<sk-1<<endl;
            else cout<<sk<<endl;
        }
        memset(equ,0,sizeof(equ));
        con=0;
        coe=0;
        temp=0;
        flag=false;
      }
      return 0;
}
