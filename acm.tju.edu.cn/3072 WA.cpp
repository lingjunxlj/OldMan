#include <stack>
#include <iostream>
using namespace std; 
stack<int> source,spur,dest; 
long  long n;                                   
long  long count=0;  
void output()
{ 
    stack<int> temp1=spur,temp2=dest;
    while (!temp1.empty())
    {
        temp2.push(temp1.top());
        temp1.pop();
    }
    while (!temp2.empty())
    {
        cout<<temp2.top();
        temp2.pop();
    }
    cout<<endl; 
}
bool rearrange() 
{
    
    if (!source.empty())
    {
        
        spur.push(source.top());
        source.pop();    
        rearrange();
        source.push(spur.top());
        spur.pop();
    }  
    if(!spur.empty())
    {
        dest.push(spur.top());
        spur.pop();
        rearrange();
        spur.push(dest.top());
        dest.pop();
    }
    if (source.empty() && spur.empty() )
    output();
    return true;
}
int main()
{
    int CS;
    cin>>CS;
    while (CS--)
    {
        int i;
        cin>>n;
        for(int i=n;i>=1;i--)
        source.push(i);
        rearrange(); 
        while (!source.empty())
        {
            source.pop();
        }
        while (!dest.empty())
        {
           dest.pop();
        }
        while (!spur.empty())
        {
            spur.pop();
        }    
        
    }system("pause");
}
 

