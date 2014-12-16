#include<iostream>
#include <cstdlib>
using namespace std;
int a[10001];

int c(int l, int r , int n)
{
    int mid = (l + r) / 2;
    cout<<mid<<endl;
    system("pause");

    if(a[mid] == n)
    {
        cout<<"end"<<mid<<endl;
        return mid;
    }

    else if(a[mid] > n)
        c(l, mid, n);

    else
        c(mid + 1, r, n);




}

int main ()
{
    int i,j;
    for(i = 1; i <= 1000; i++)
        a[i]=i;
    int n;
    while(cin>>n)
    {
        j = c(1, 100, n);
        cout<<j<<endl;
    }
    return 0;
}
