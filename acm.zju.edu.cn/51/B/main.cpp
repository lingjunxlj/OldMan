#include<iostream>
#include<cmath>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
char e[4][9][10]={{"I","II","III","IV","V","VI","VII","VIII","IX"},
                {"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
                {"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
                {"M","MM","MMM"}};
struct node
{
    int Int;
    string roma;
    string temp[5];
};
int t,n;
node a[20505];
bool cmp(node a,node b)
{
    if(a.roma[0]!=b.roma[0])
        return a.roma[0]<b.roma[0];
    if(a.roma[1]!=b.roma[1])
        return a.roma[1]<b.roma[1];
    if(a.roma[2]!=b.roma[2])
        return a.roma[2]<b.roma[2];
    if(a.roma[3]!=b.roma[3])
        return a.roma[3]<b.roma[3];
    if(a.roma[4]!=b.roma[4])
        return a.roma[4]<b.roma[4];
    if(a.roma[5]!=b.roma[5])
        return a.roma[5]<b.roma[5];
    if(a.roma[6]!=b.roma[6])
        return a.roma[6]<b.roma[6];
    if(a.roma[7]!=b.roma[7])
        return a.roma[7]<b.roma[7];
    if(a.roma[8]!=b.roma[8])
        return a.roma[8]<b.roma[8];
}
int main()
{
    int i,j;
    int shu,shu_n=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            a[i].roma = "";

        for(i=0;i<n;i++)
        {
            shu_n=0;
            scanf("%d",&a[i].Int);
            shu=a[i].Int;
            int k = 0;
            while(shu)
            {
                if (shu%10 != 0)
                {
                    a[i].temp[k++]=e[shu_n][shu%10-1];
                }

                shu/=10;
                shu_n++;
            }
            for (int j =  k - 1; j >=0; j--)
                a[i].roma += a[i].temp[j];
            //reverse(a[i].roma.begin(), a[i].roma.end());
            //cout<<a[i].roma<<endl;
        }
        sort(a,a+n,cmp);
        for(i=0;i<n;i++)
        {
            if(i<n-1)
                printf("%d ",a[i].Int);
            else
                printf("%d",a[i].Int);
        }
        printf("\n");
    }
    //system("pause");

}


