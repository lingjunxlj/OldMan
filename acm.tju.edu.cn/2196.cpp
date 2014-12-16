#include <iostream>
#include <set>
using namespace std;
multiset <int> kelly;
int main()
{
    int x,y;
    while (1)
    {
        cin>>x;
        kelly.clear();
        if (x==0)
        break;
        char ch;
        int i,min;
        
        for (i=0;i<x;i++)
        {
            cin>>ch;
            if (ch=='B')
            {
                cin>>y;
                kelly.insert(y);
            }
            else
            {
                min=*kelly.begin();
                cout<<min<<endl;
                kelly.erase(kelly.begin());                                       
            }
        }
    }
}
            
                
        
            
