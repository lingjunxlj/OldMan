#include <iostream>
#include <string>
using namespace std;
int main()
{
    int x,y=0;
    while (cin>>x&&x!=0)
    {
        y++;
        int i,num[100];
        char str[x][100];
        for (i=0;i<x;i++)
        cin>>str[i];
        printf ("SET %d\n",y);
        if (x%2==1)
        {
            for (i=0;i<x;i+=2)
            cout<<str[i]<<endl;
            for (i=1;i<x;i+=2)
            cout<<str[x-i-1]<<endl;
        }
        else
        {
            for (i=0;i<x;i+=2)
            cout<<str[i]<<endl;
            for (i=1;i<x;i+=2)
            cout<<str[x-i]<<endl;
        }
    }
}
        
            
        
             
