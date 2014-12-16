#include<iostream>
using namespace std;

int main()
{
        char a[80],b[80];
        long long sum;
        while(cin>>a>>b)
        {
            sum=0;
            int len1=strlen(a);
            int len2=strlen(b);
            int i;
            for (i=len1>len2?len2:len1; i >=0 ; i--)
            sum+=a[i]^b[i];
            if(sum==0)
            cout<<"No"<<endl;
            else
            cout<<"Yes"<<endl;
       }
       return 0;

}
