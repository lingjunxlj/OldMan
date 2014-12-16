#include <iostream>
#include <string>
using namespace std;
int num[10];
int temp;
void play(int a)
{
    int i;
    if( a<= 0)
    return;
    int b = a%10;
    a /= 10;
    for(i = 0; i <= b; i++)
    num[i]+=temp;
    int aa=a;
    while(aa)
    {
        num[aa % 10] += (b + 1) * temp;
        aa /= 10;
    }
    for(i = 0; i < 10; i++)
    num[i] += a * temp;
    num[0] -= temp;
    temp *= 10;
    play(a - 1);
}
int main()
{
    int i, a, b;
    while(cin>>a>>b)
    {
        if (a==-1&&b==-1)
        break;
        if(a > b)
        {
            i = a;
            a = b;
            b = i;
        }
        for(i = 0;i < 10; i++)
        num[i] = 0;

        temp = 1;
        play( b );

        temp = -1;
        play(a - 1);

        cout<<num[0];
        //for(i = 1;i < 10; i++)
        //cout<<" "<<num[i];
        cout<<endl;
    }
}
