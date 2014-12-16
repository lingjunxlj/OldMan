#include <iostream>
using namespace std;

long long str[500002];
long long biao[500002];

void ChangeString(long long s[],long long n)
{
    long long *temp = new long long[n];
    memcpy(temp,s,n*sizeof(long long));
    memcpy(s+1,temp,n*sizeof(long long));
    delete[] temp;
}
void Convert(long long s[],long long n)
{
    for(long long i=0,j=n-1;i<=j;++i,--j)
        swap(s[i],s[j]);
}

int main()
{
    long long n,m;
    biao[0] = 0;
    for(int i=1;i<=50000;++i)
        biao[i] = biao [i-1] + i;
    while(cin>>n>>m,n!=-1 || m!=-1)
    {
        long long i;
        for(i=0;i<n;++i)
            str[i] = i+1;
        long long min = n-1;
        for(i=0;;++i)
        {
            if(biao[i]>=m)
                break;
        }
        Convert(str+n-i-1,i+1);
        if(biao[i] != m)
        {
            long long t = biao[i]-m;
            long long c = str[n-i-1+t];
            ChangeString(str+n-i-1,t);
            str[n-i-1] = c;
        }
        cout<<str[0];
        for(long long i=1;i<n;++i)
            cout<<" "<<str[i];
        cout<<endl;
    }
    return 0;
}
