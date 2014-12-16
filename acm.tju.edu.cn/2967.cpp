#include <iostream>

using namespace std;

void Trig();
void Rect();
void Pal();

int main()
{

    int C;
    while(cin>>C)
    {
        if(C<0)
            break;
        switch(C)
        {
        case 1:
            Trig();
            break;
        case 2:
            Pal();
            break;
        case 3:
            Rect();
            break;
        };

    }

    return 0;
}

void Trig()
{
    int H;
    cin>>H;
    int index=H-1;
    for(int i=1;i<=H;i++)
    {
        for(int j=0;j<index;j++)
            cout<<" ";
        for(int j=0;j<(i*2)/2-1;j++)
            cout<<"*";
        cout<<"*";
        for(int j=0;j<(i*2)/2-1;j++)
            cout<<"*";
        cout<<endl;
        index--;
    }
   
}

void Rect()
{
    int W,H;
    cin>>W>>H;
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
            cout<<"*";
            cout<<endl;
    }
    
}

void Pal()
{
    int W,H,index;
    cin>>W>>H;
    if(W>=H)
    {
        index=H-1;
        for(int i=0;i<H;i++)
        {
            for(int j=0;j<index;j++)
                cout<<" ";
            index--;
            for(int j=0;j<W;j++)
                cout<<"*";
            cout<<endl;
        }
        
    }
    else
    {
        index=0;
        for(int i=0;i<H;i++)
        {
            for(int j=0;j<index;j++)
                cout<<" ";
            for(int j=0;j<W;j++)
                cout<<"*";
            
            index++;
            cout<<endl;
        }
        
    }

} 
