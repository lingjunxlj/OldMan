#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxint=100;
struct stk
{
    char name[100];
    int days;
    int weight;
    int new_weight;
};

int cmp(const void * a , const void * b )
{
    return ((stk*)b)->new_weight > ((stk*)a)->new_weight?1:-1;
}

int main()
{
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);
    stk a[maxint];
    char start[maxint];
    int num;
    cin>>start;
    bool flag = 0;
    do
    {
        num = 0;
        if (flag)
        cout<<endl;
        flag = 1;
        while(1)
        {
            cin>>a[num].name;
            if (!strcmp(a[num].name, "END"))
            break;

            cin>>a[num].days>>a[num].weight;

            a[num].new_weight = a[num].weight - a[num].days;

            if (a[num].new_weight < 1)
            a[num].new_weight = 1;

            num++;
        }
        qsort(a,num,sizeof(a[0]),cmp);
        for (int i=0;i<num;i++)
        cout<<a[i].name<<endl;

        //cout<<endl;
    }while(cin>>start);
    return 0;
}
