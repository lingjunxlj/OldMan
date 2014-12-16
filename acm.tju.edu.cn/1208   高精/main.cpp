#include <iostream>
#include <string>
using namespace std;
int main()
{
    string t1="1",t2="1",t;
    int num;
    int i,j,k;
    int z;
    while(scanf("%d",&num) !=EOF)
    {
        t1="1";t2="1";
        if(num==1||num==2)
        {
            printf("%d\n",1);
            continue;
        }
        for(k=3;k<=num;k++)
        {
            t="";
            z=0;
            for(i=t1.length()-1,j=t2.length()-1;i>=0;i--,j--)
            {
                t+=(char)( (t1[i]-48+t2[j]-48+z)%10 +48);
                z=(int)(t1[i]-48+t2[j]-48+z)/10;
            }
            for(i=j;i>=0;i--)
            {
                t+=(char)( (t2[i]-48 +z)%10+48);
                z=(int)(t2[i]-48+z)/10;
            }
            if(z>0)
            {
                t+=(char)(z+48);
            }
            t1="";
            t1=t2;
            t2="";
            for(i=t.length()-1;i>=0;i--)
            t2+=t[i];
        }
        cout<<t2<<endl;
    }
}
