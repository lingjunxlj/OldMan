#include <cstdio>
int max(int x,int y)
{
    return x>y?x:y;
}
int main()
{
    int x;
    scanf("%d",&x);
    while (x--)
    {
        int pre,n;
        scanf("%d %d",&n,&pre);
        int x,MIN=-n,MAX=0;
        for (int i=1;i<n;i++)
        {
            scanf("%d",&x);
            if (x>pre)
            MAX=max(MIN+1,MAX);
            if (x<pre)
            MIN=max(MIN,MAX+1);
            pre=x;
        }
        printf("%d\n",max(MAX,MIN)+1);
    }
}
/*
这到题目显然是一道ＤＰ题。

设：在求的数列中，如果这个数比左右的数大，则称为大值，反之为小值。

原先想到的是，对于每个数，设置２个值，一个为小值一个为大值。小值为前面所有比此数大的数的大值加１，如果为０个不用加了，因为第一个数必须为大值．大值为前面所有比此数小的数的小值＋１．这个算法的时间复杂度为O(n^2)。TLE。

参考 大牛们的代码。设置2个值，mi，mx。表示一个数的为小值，和大值时串的长度。显然一个大值和小值的串的长度是相互递增的。即 mi=max(mi,mx+1),

mx=max(mi+1,mx);设置一个标号值pre表示前一个值。比较当前值，如果小，则当前值为大值是的串长一定不会变化。只需要比较为小值时，串是否变化就行。反之同理。

其实这道题也就是求一串数组成的w型的拐角有多少个。并不需要关系具体是那几个数组成这样的拐角。

*/
