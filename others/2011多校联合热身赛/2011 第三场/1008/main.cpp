#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int main ()
{
	int Case;
	cin >> Case;
	while (Case--)
	{

		int X, N;
		scanf("%d %d", &X, &N);
		//cin >> X >> N;

		vector<pair<int,int> > x(N);//相当与结构体

		for (int i = 0; i < N; i++)
		{
			scanf("%d", &x[i].first);
			//cin >> x[i].first;
			x[i].second = -i; //sort优化
		}

		sort(x.begin(),x.end());//排序

		vector<int> y(N); //相当于数组

		for (int i = 0; i < N; i++)
		{
            y[-x[i].second] = min(x[i].first, X/(N-i));//记录位置
            X -= min(x[i].first, X/(N-i));//如果当前的钱比平摊所需的钱少就用光自己的钱

		}

		if (X > 0)
			cout << "IMPOSSIBLE" << endl;
		else
		{
			for (int i=0; i<N; i++)
			{
				if (i>0)
                    cout <<" ";
                cout <<y[i];
			}
			cout<<endl;
		}
	}

	return 0;
}
