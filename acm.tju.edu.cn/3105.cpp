#include <iostream>
using namespace std;
const int MAX=100001;
int prime[MAX],table[MAX],top;
void Prime() 
{   				
        int i,j; 
        prime[1] = 1; 
        for(i = 2 ; i * i <= MAX ; i++) 
		{
            if(!prime[i])
			{ 
                for(j = i * i ; j <= MAX ; j += i) 
                prime[j] = 1; 
			}
		}
        table[1] = 2; 
        top = 1; 
        for(i=3;i<=MAX;i+=2) 
        {
			if(!prime[i])
			{ 
				table[++top] = i; 
			}
		}
}
int main()
{
	Prime();
	int x;
	cin>>x;
	while (x--)
	{
		int n;
		cin>>n;
		cout<<table[n]<<endl;
	}
	
}
		
