#include <iostream>
using namespace std;

int sx[] = {0, 3, 6, 8, 10};

int main()
{
	int s,d;
	while(cin >> s >> d)
	{
		int i;
		int max = d*(-12);
		for(i=1;i<=4;i++)
		{
			if(s*i<d*(5-i))
			{
				if(max < (s*sx[i] - d*(12-sx[i])))
					max = (s*sx[i] - d*(12-sx[i]));
			}
		}
		if(max>0)
			cout << max << endl;

		else
			cout << "Deficit" << endl;

	}
	return 0;
}

