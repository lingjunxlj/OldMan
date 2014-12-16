#include<iostream>
#include<string>
using namespace std;
#define maxnum 105
string catalan[maxnum];
string Plus(string f,string s);
string Multiply(string f,string s);
void Split(int a[],string str);
int main()
{
    catalan[0]="1";
    int i,j;
    for(i=1;i<=maxnum-5;i++)
    catalan[i]="0";
    for(i=1;i<=maxnum-5;i++)//计算n=1到100的卡特兰数
    for(j=0;j<i;j++)
    catalan[i]=Plus(catalan[i],Multiply(catalan[j],catalan[i-j-1]));
    int n;
    while(cin>>n,n!=-1)
    {
        cout<<catalan[n]<<endl;
    }
    return 0;
}
string Plus(string f,string s)//模拟加法运算
{
    int fint[maxnum];
    memset(fint,0,sizeof(fint));
    Split(fint,f);
    int sint[maxnum];
    memset(sint,0,sizeof(sint));
    Split(sint,s);
    int i;
    int sz1=f.length(),sz2=s.length();
    int sz=sz1>=sz2?sz1:sz2;
    for(i=0;i<sz;i++)
    fint[i]+=sint[i];
    for(i=0;i<sz;i++)
    {
        fint[i+1]+=(fint[i]/10);
        fint[i]%=10;
    }
    string ans="";
    if(fint[i]!=0)
    ans=fint[i]+'0';
    for(i--;i>=0;i--)
    ans+=(fint[i]+'0');
    return ans;
}


string Multiply(string f,string s)//模拟乘法运算
{
    int fint[maxnum];
    memset(fint,0,sizeof(fint));
    Split(fint,f);
    int sint[maxnum];
    memset(sint,0,sizeof(sint));
    Split(sint,s);
    int rslt[maxnum];
    memset(rslt,0,sizeof(rslt));
    int i,j;
    int fsz=f.length(),ssz=s.length();
    for(i=0;i<ssz;i++)
    for(j=0;j<fsz;j++)
    rslt[i+j]+=fint[j]*sint[i];
    for(i=0;i<=fsz+ssz-2;i++)
    {
        rslt[i+1]+=(rslt[i]/10);
        rslt[i]%=10;
    }
    string ans="";
    if(rslt[i]!=0)
    ans=rslt[i]+'0';
    for(i--;i>=0;i--)
    ans+=(rslt[i]+'0');
    return ans;
}
void Split(int a[],string str)//分离字符串
{
    int i;
    int size=str.length(),t=0;
    for(i=size-1;i>=0;i--)
    a[i]=str[t++]-'0';
}
