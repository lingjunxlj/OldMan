#include<iostream>
#include<algorithm>
using namespace std;

inline int CharToDigit(char c){
    if( isdigit(c) )
        return c-'0';
    return c-'A'+10;
}

inline char DigitToChar(int n){
    return "0123456789ABCDEF"[n];
}

bool checkIllegal(int base1, string& in ){
    for(int i=0;i<in.length();++i)
        if( CharToDigit(in[i])>=base1 )
            return true;
    return false;
}

/* convert string 'in' to int 'value'. */
long long parseValue( int base1, string& in ){

    if( checkIllegal(base1, in) ) return -1;

    long long value=0;
    long long curBase=1;

    for(int i=in.length()-1;i>=0;--i) {

        int digit = CharToDigit(in[i]);
        value += digit * curBase;
        curBase *= base1;
    }
    return value;
}

/* convert int 'value' to string 'out' */
string toBase( int base2, long long value ){

    if(value==0) return "0";

    string out;
    while( value>0 ){
        out += DigitToChar( value%base2 );
        value /= base2;
    }
    reverse(out.begin(), out.end());
    return out;
}

int main() {

    #ifndef ONLINE_JUDGE
    //freopen("355.in","r",stdin);
    #endif

    int base1, base2;
    string in;

    while( cin>>base1>>base2>>in ){

        long long value = parseValue(base1, in);

        if( value<0 ){ //wrong
            cout<<in<<" is an illegal base "<<base1<<" number\n";
            continue;
        }
        cout<<in<<" base "<<base1<<" = "<<toBase(base2, value)<<" base "<<base2<<"\n";
    }
    return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;

int change1(char a)
{
    if(a>='0' && a<='9')
        return a-'0';
    else
        return a-'A'+10;
}

void solve(unsigned long long n, int k)
{
    stack<int> ans;
    int temp;
    if(n==0)
    {
        printf("0");
        return;
    }
    while(n)
    {
        ans.push(n%k);
        n /= k;
    }
    while(!ans.empty())
    {
        temp = ans.top();
        ans.pop();
        if(temp<=9)
        printf("%d",temp);
        else printf("%c",temp-10+'A');
    }
}

int main()
{
    int i, b1, b2, len, t;
    char str[15];
    bool flag;
    unsigned long long sum, k;
    while(cin>>b1>>b2)
    {
        cin>>str;
        //cout<<str<<endl;
        len = strlen(str);
        sum = 0;  k=1;
        flag = true;
        for(i=len-1; i>=0; i--)
        {
            t = change1(str[i]);
            if( (t >= b1 || t < 0) || str[i]=='-')
            {
                cout<<str<<" is an illegal base "<<b1<<" number"<<endl;
                flag = false;      break;
            }
            sum += t*k;
            k *= b1;
        }

        if(flag)
        {
            cout<<str<<" base "<<b1<<" = ";
            solve(sum, b2);
            cout<<" base "<<b2<<endl;
        }
    }
    return 0;
}
*/
