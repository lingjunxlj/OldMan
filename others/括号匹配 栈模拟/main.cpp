#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
stack<char>q;
char str[10010];
int main()
{
	int t, i, k;

	cin>>t;
	while(t--)
	{
		cin>>str;
		if( strlen(str) % 2 != 0 ||( str[0] != '[' && str[0] != '(' ) )
		{
			cout<<"No"<<endl;
			continue;
		}
		k = 0;
		for( i = 0 ; i < strlen(str) ; i ++ )
		{
			if( str[i] == '[' || str[i] == '(' )
			q.push(str[i]);
			else
			{
				if( str[i] == ']')
				{
					if( q.top() != '[')
					{
						k = 1 ; break ;
					}
					else
					q.pop();
				}
				else
				{
					if( q.top() != '(')
					{
						k = 1 ; break ;
					}
					else
					q.pop();
				}
			}
		}
		q.empty();
		if( k == 0 )
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
	return 0;
}
