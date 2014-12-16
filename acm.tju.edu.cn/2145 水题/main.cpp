#include<iostream>
using namespace std;
int all, time1, time2, r, b, j, loca, h, a[51000], x[51000], w;
void reserve(int a[], int len, int m, int n)
{
  int p, q, a2[51000];
  for(p = 1; p <= len; p++)
    a2[p] = a[p];

  for(q = m; q <= n; q++)
    a[q] = a2[m + n - q];
}


int main()
{
    h = 0;
    while (1)
    {
        cin>>all;
        if(all == 0)
            break;
        h++;

        for(j = 1; j <= all; j++)
            a[j] = j;

        cin>>time1;
        for(j = 1; j <= time1; j++)
        {
            cin>>r>>b;
            reserve(a, all, r, b);
        }
        cout<<"Genome "<<h<<endl;

        cin>>time2;
        for(j = 1; j <= time2; j++)
        {
            cin>>loca;
            int e;

            for(e = 1; e <= all; e++)
            {
                if(a[e] == loca)
                cout<<e<<endl;
            }

        }
   }
}
