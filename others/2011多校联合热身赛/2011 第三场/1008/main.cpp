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

		vector<pair<int,int> > x(N);//�൱��ṹ��

		for (int i = 0; i < N; i++)
		{
			scanf("%d", &x[i].first);
			//cin >> x[i].first;
			x[i].second = -i; //sort�Ż�
		}

		sort(x.begin(),x.end());//����

		vector<int> y(N); //�൱������

		for (int i = 0; i < N; i++)
		{
            y[-x[i].second] = min(x[i].first, X/(N-i));//��¼λ��
            X -= min(x[i].first, X/(N-i));//�����ǰ��Ǯ��ƽ̯�����Ǯ�پ��ù��Լ���Ǯ

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
