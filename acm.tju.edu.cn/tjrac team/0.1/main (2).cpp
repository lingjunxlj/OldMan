#include <iostream>
#include <algorithm>
using namespace std;
int num1[801],num2[801];
int main()
{
    int x,y=0;
    scanf("%d",&x);
    while (x--)
    {
        y++;
        int n;
        scanf("%d",&n);
        int i;
        int sum=0;
        for (i=0;i<n;i++)
        scanf("%d",&num1[i]);
        for (i=0;i<n;i++)
        scanf("%d",&num2[i]);
        for (i=0;i<n;i++)
        sum+=(num1[i]*num2[i]);
        int min=sum;
        do{
            int sum=0;
            for (i=0;i<n;i++)
            sum+=(num1[i]*num2[i]);
            if (min>sum)
            min=sum;
        }while (next_permutation (num1, num1 + n));
        printf("Case #%d: %d\n",y,min);
    }

}
