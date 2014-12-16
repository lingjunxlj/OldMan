#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int ID(string id)
{
    int res,i,j,k;
    int len;
    char buff[100];
    long long x;
    len=id.size();
    for (x=0;x<100000;x++)
    {
        string str;
        sprintf(buff,"%lld",x*x);
        str=buff;
        if (str.size()>len)
        break;
        while (str.size()<len)
        {
            str='0'+str;
        }
        k=0;
        for (j=0;j<len;j++)
        {
            if (id[j]!=str[j])
            k++;
        }
        if (k<res)
        res=k;
    }
    return res;
}

int main()
{

    string id;
    while (cin>>id)
    {
        printf("%d\n",ID(id));
    }
}
