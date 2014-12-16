#include <iostream>
#include <string>
#include <map>

#define N 1010

using namespace std;

int a, b, c;
int n;
string arr_b[N];

int main()
{
	while (scanf("%d %d %d", &a, &b, &c) != EOF)
	{
		map<string, int> hasha;
		for (int i = 0; i < a; i++)
		{
			string sa;
			cin >> sa;
			hasha[sa] = 1;
		}

		for (int i = 0; i < b; i++)
			cin >> arr_b[i];

		map<string, int> hashc;
		for (int i = 0; i < c; i++)
		{
			string sc;
			cin >> sc;
			hashc[sc] = 1;
		}

		int first = 1;
		for (int i = 0; i < b; i++)
		{
			if (hasha[arr_b[i]]==1 && hashc[arr_b[i]]==0)
			{
				if (!first)
					cout << ' ';
				else
					first = 0;
				cout << arr_b[i];
			}
		}

		if (!first)
			cout << endl;
		else
			cout << "No enemy spy" << endl;
	}

	return 0;
}
