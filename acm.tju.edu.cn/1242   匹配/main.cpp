#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    short data[30];
    short str[100];
    int m;
    cin>>m;
    while(m--)
    {
        int index=0,n;
        cin>>n;
        data[0]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>data[i];
            for(int j=1;j<=data[i]-data[i-1];j++)
            {
                str[index]=-2;
                index++;
            }
            str[index++]=-1;
        }
        for(int i=0;i<index;i++)
        {
            if(str[i]==-1)
            {
                int result=1;
                for(int j=i-1;j>=0;j--)
                {
                    if(str[j]==-2)
                    {
                        str[j]=0;
                        str[i]=result;
                        if(i==index-1)
                            cout<<result;
                        else
                            cout<<result<<" ";
                        break;
                    }
                    else
                    {
                        result+=str[j];
                        str[j]=0;
                    }
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
