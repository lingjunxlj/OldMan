#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n,i,t=1;
    string ddr;
    cin>>n;

    while(n)
    {
        i=0;
        cin>>ddr;
        cout<<"URL #"<<t<<endl;
        cout<<"Protocol = ";
        while(ddr[i]!=':')
        {
            cout<<ddr[i];
            i++;
        }
        cout<<endl;
        cout<<"Host     = ";
        i+=3;
        while(ddr[i]!=':'&&ddr[i]!='/'&&i<ddr.size())
        {
            cout<<ddr[i];
            i++;
        }
        cout<<endl;
        if(i==ddr.size())
        {
            cout<<"Port     = <default>"<<endl;
            cout<<"Path     = <default>"<<endl;
        }
        else
        {
            if(ddr[i]==':')
            {
                cout<<"Port     = ";
                i+=1;
                while((ddr[i]!='/')&&(i<ddr.size()))
                {
                    cout<<ddr[i];
                    i++;
                }
                cout<<endl;
                if(i==ddr.size())
                    cout<<"Path     = <default>"<<endl;
                else
                {
                    cout<<"Path     = ";
                    while(i+1<ddr.size()) 
                    {
                        cout<<ddr[i+1];
                        i++;
                    }
                    cout<<endl;
                }
            }
            else
            {
                cout<<"Port     = <default>"<<endl;
                                cout<<"Path     = ";
                while(i+1<ddr.size())
                {
                    cout<<ddr[i+1]; 
                    i++;
                }
                cout<<endl;
            }
        }
        n--;
        t++;
        cout<<endl;
    }
    return 0;
}
