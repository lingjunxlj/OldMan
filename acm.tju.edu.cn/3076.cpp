#include<iostream>
using namespace std;
const int MAXV = 10000000; 
bool flag[MAXV+1]; 
int prime[MAXV+1]; 
int size; 
void genPrime(int max)
{
    memset(flag, true, sizeof(flag));
    for(int i = 2; i <= max / 2; i++)
    {
        if(flag[i])
        {
            for(int j = i << 1 ; j <= max; j += i)
            {
                flag[j] = false;
            }
        }
    }
    for(int i = 2 ; i <= max; i++)
    {
        if(flag[i])
        {
            prime[size++] = i;
        }
    }
}
int main()
{
    genPrime(MAXV);
   
    int x;
    while (cin>>x&&x!=0)
    {
        if (x==1)
        cout<<0<<endl;
        else if (flag[x]==true)
        cout<<0<<endl;
        else
        {
            int i,j,s=1;
            for (i=x-1;;i--)
            {
                if (flag[i]==false)
                s++;
                else
                break;
            }
            for (i=x+1;;i++)
            {
                if (flag[i]==false)
                s++;
                else
                break;
            }
            cout<<s+1<<endl;
        }
    }    
    return 0;
}
