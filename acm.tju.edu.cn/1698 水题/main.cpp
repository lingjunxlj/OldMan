#include <iostream>
#include <string>
using namespace std;
int main()
{
	int max, T, n, i, j, flag, ans, k = 1;
	string s;
	cin >> T;
	while(T--)
	{
	    cin >> s;
		for(i = 0; i < s.length(); i++)
		{
			if(s[i] == '?')
			{
				ans = i;
				break;
			}
		}
		for(j = 0; j < 10; j++)
		{
            if (s.length()%3==1)
            flag = 9;

            else if (s.length()%3==2)
            flag = 3;

            else flag = 7;
		    max = 0;

			s[ans]=j + '0';
			for(i = 0; i < s.length();i++)
			{
			    max += ( int(s[i] - '0') ) * flag;

				if (flag == 9)
				flag=7;

				else if (flag == 7)
				flag = 3;

				else flag = 9;
			}
			if (max % 10 == 0)
			break;
		}
	    cout << "Scenario #" << k++ << ':' << endl;

        if(max % 10 == 0)
        cout << s << endl;
		cout << endl;
    }
	return 0;
}
