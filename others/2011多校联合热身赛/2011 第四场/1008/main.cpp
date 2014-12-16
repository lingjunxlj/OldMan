#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct In
{
    long long a;
    long long b;
    long long c;
    int temp;
    int bl;
}num[10101];

bool cmp(In x, In y)
{
    if (x.c != y.c)
        return x.c > y.c;
    else
    {
        if(x.temp != y.temp)
            return x.temp > y.temp;
        else
            return x.bl < y.bl;
    }

}

/*
int cmp( const void *aa , const void *bb )
{
    struct In *cc = (struct In *)aa;
    struct In *dd = (struct In *)bb;
    if(cc->c != dd->c)
        return  dd->c - cc->c;
    else
    {
        if(cc->temp != dd->temp)
            return  dd->temp - cc->temp;
        else
            return   cc->bl - dd->bl;
    }

}
*/
char fu[3] ={'<','=','>'};
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        memset(num, 0, sizeof(num));
        for (int i = 0; i < n; i++)
        {
            scanf("%I64d %I64d", &num[i].a, &num[i].b);
            num[i].c = num[i].a + num[i].b;
            if(num[i].a > num[i].b)
                num[i].temp = 2;
            if(num[i].a == num[i].b)
                num[i].temp = 1;
            if(num[i].a < num[i].b)
                num[i].temp = 0;
            num[i].bl = i;

        }
        sort(num, num + n, cmp);
        //qsort(num,n,sizeof(num[0]),cmp);
        for (int i = 0; i < n ;i ++)
        {
            printf("%I64d+%I64d=[%c%I64d]\n", num[i].a, num[i].b, fu[num[i].temp], num[i].c);
            //cout<<num[i].a<<"+"<<num[i].b<<"="<<"["<<fu[num[i].temp]<<num[i].c<<"]"<<endl;
            //printf("num[i].bl = %d\n", num[i].bl);
        }
        printf("\n");

    }
}
