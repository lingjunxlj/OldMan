#include <iostream>
#include <stack>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
const int N=27;
struct M
{
    int x,y;
}matrix[N];
int n;
int solve(string s)
{
    int cnt=0,i;
    stack<M>st;
    M c,tmp;
    int len=s.size();
    for (i=0;i<len;i++)
    {
        if (s[i]>='A'&&s[i]<='Z')
        {
            tmp=matrix[s[i]-'A'];
            st.push(tmp);
        }
        else if (s[i]==')')
        {
            c=st.top();
            st.pop();
            tmp=st.top();
            st.pop();
            if (c.x!=tmp.y)
            return -1;
            cnt+=c.x*tmp.x*c.y;
            tmp.x=tmp.x;
            tmp.y=c.y;
            st.push(tmp);
        }
    }
    return cnt+1;
}
int main ()
{
    int i;
    string s;
    char ch;
    scanf("%d",&n);
    getchar();
    for (i=1;i<=n;i++)
    {
        cin>>ch;
        scanf("%d%d",&matrix[ch-'A'].x,&matrix[ch-'A'].y);
    }
    while (cin>>s)
    {
        int k=solve(s);
        if (k==-1)
        printf("error\n");
        else
        printf("%d\n", k-1);
    }
}
