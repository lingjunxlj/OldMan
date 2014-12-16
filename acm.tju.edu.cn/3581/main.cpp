#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    int joy;
    int price;
    double metric;
    int num;
}queue[25002];
bool cmp(const node x, const node y)
{
    return x.metric > y.metric;
}
int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>queue[i].joy>>queue[i].price;
        queue[i].metric = (double)queue[i].joy/(double)queue[i].price;
        //cout<<queue[i].metric<<"----"<<endl;
        queue[i].num = i + 1;
    }
    sort(queue, queue + n, cmp);
    int sum = 0;
    for (int i = 0; i < 3; i++)
        sum += queue[i].price;

    cout<<sum<<endl;

    for (int i = 0; i < 3; i++)
        cout<<queue[i].num<<endl;


}
