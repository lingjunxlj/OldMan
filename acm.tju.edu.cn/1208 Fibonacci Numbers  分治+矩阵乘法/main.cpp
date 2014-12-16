#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
string *cal(string b[][2],int num);
void Fibo(string *p,int F[]);
string mul( string a, string b);
string add(string a,string b);
int main()
{
    int num;
    string *p;
    cin>>num;
    string b[2][2]={{"1","1"},{"1","0"}};
    if(num==1||num==2)
    {
        cout<<'1'<<endl;
        return 0;
    }
    p=cal(b,num-2);
    cout<< add ( *p , *(p+2) ) <<endl;
    return 0;
}
string *cal(string b[][2],int num)
{
    if(num==1)
    return b[0];
    string *p=cal(b,num/2);
    string A,B,C,D;
    A=add (mul( *p , *p ) , mul( *(p+1) , *(p+2) ));
    B=add (mul( *p , *(p+1)) , mul( *(p+1) , *(p+3)) );
    C=add (mul( *(p+2) , *p) , mul( *(p+3) , *(p+2)) );
    D=add (mul( *(p+2) , *(p+1)) , mul( *(p+3) , *(p+3)));
    *p=A;
    *(p+1)=B;
    *(p+2)=C;
    *(p+3)=D;
    if(num%2==1)
    {
        A=add ( *p , *(p+1) );
        B=(*p);
        C=add ( *(p+2) , *(p+3) );
        D=(*(p+2));
        *p=A;
        *(p+1)=B;
        *(p+2)=C;
        *(p+3)=D;
    }
    return p;
}
string mul( string a, string b)
{
    unsigned int i,j;
    if(a=="0"||b=="0")
    return "0";
    string s(a.length()+b.length(),'0');
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(j=0;j<b.length();j++)
    {
        if(b[j]=='0')
        continue;
        int temp=0;
        for(i=0;i<a.length();i++)
        {
            temp+=(a[i]-'0')*(b[j]-'0')+s[j+i]-'0';
            s[j+i]=temp%10+'0';
            temp/=10;
        }
        s[a.length()+j]+=temp;
    }
    reverse(s.begin(),s.end());
    return s.substr(s.find_first_not_of('0'));
}
string add(string a,string b)
{
    int temp=0;
    if(a.length()>=b.length())
    {
        string s(a);
        int bi=b.length()-1,si=s.length()-1;
        for(;si>=0;--bi,--si)
        {
            temp+=s[si]-'0'+(bi>=0?b[bi]-'0':0);
            s[si]=char(temp%10+'0');
            temp/=10;
        }
        return temp?('1'+s):s;
    }
    else
    {
        string s(b);
        int ai=a.length()-1,si=s.length()-1;
        for(;si>=0;--ai,--si)
        {
            temp+=s[si]-'0'+(ai>=0?a[ai]-'0':0);
            s[si]=char(temp%10+'0');
            temp/=10;
        }
        return temp?('1'+s):s;
    }
}
