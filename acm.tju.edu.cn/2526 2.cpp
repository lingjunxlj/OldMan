#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int x,y=0,i;
	cin>>x;
	while (x--)
	{
		y++;
		string add;
		cin>>add;
		cout<<"URL #"<<y<<endl;
		cout<<"Protocol = ";
		i=0;
		while(add[i]!=':')
		{
			cout<<add[i];
			i++;
		}
		cout<<endl;
		cout<<"Host     = ";
        i+=3;
        while(add[i]!=':'&&add[i]!='/'&&i<sizeof(add))
        {
            cout<<add[i];
            i++;
        }
		cout<<endl;
		if(i==sizeof(add))
        {
            cout<<"Port     = <default>"<<endl;
            cout<<"Path     = <default>"<<endl;
        }
        else
        {
            if(add[i]==':')
            {
                cout<<"Port     = ";
                i+=1;
                while((add[i]!='/')&&(i<sizeof(add)))
                {
                    cout<<add[i];
                    i++;
                }
                cout<<endl;
                if(i==sizeof(add))
                    cout<<"Path     = <default>"<<endl;
                else
                {
                    cout<<"Path     = ";
                    while(i+1<sizeof(add)) 
                    {
                        cout<<add[i+1];
                        i++;
                    }
                    cout<<endl;
                }
            }
            else
            {
                cout<<"Port     = <default>"<<endl;
                                cout<<"Path     = ";
                while(i+1<sizeof(add))
                {
                    cout<<add[i+1]; 
                    i++;
                }
                cout<<endl;
            }
        }
        
        cout<<endl;
    }
    return 0;
}
		
		
