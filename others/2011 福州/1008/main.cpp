#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
map<int, string>name;
map<string, int> name1;
int t;
int map1[10][10];
int flag[10];
string str2[10];
int num[100];
int num1[100];
int main()
{
    int t, x = 1;
    scanf("%d", &t);
    while(t--)
    {
        name.clear();
        name1.clear();
        memset(map1, 0, sizeof(map1));
        int n;
        scanf("%d", &n);
        for (int i = 0 ; i < n; i++)
            cin>>str2[i];
        sort(str2, str2 + n);
        //for (int i = 0 ; i < n; i++)
            //cout<<str2[i]<<endl;;
        for (int i = 0 ; i < n; i++)
        {

            name[i] = str2[i];
            name1[str2[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            int tt;
            scanf("%d", &tt);
            for (int j = 0; j < tt; j++)
            {
                string str1;
                cin>>str1;
                map1[i][name1[str1]] = 1;
                //map1[name1[str1]][i] = 1;
            }
        }

        for (int i = 0; i < n; i++)
            num[i] = i;
        for (int i = 0; i < n; i++)
            num1[i] = i;
        int fg = 0;
        int sum1 = 1;
        for (int i = 1; i <= n; i++)
        {
            sum1 *= i;
        }
        do
        {

            //for (int i = 0; i < n; i++)
                //printf("%d ", num[i]);
            //cout<<endl;
            int sum = 0;
            //int fg = 0;
            for (int i = 0; i < n; i++)
                num1[i] = i;
            do
            {
                int ans = 0;
                sum += 1;
                //printf("sum = %d\n", sum);
                memset(flag, 0, sizeof(flag));
                for (int i = 0; i < n; i++)
                {

                    for (int j = 0; j < n; j++)
                    {
                        if (!flag[num1[j]])
                        {
                            if (!map1[num1[j]][num[i]] )
                            {
                                ans++;
                                flag[num1[j]] = 1;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                }
                if(ans != n)
                    break;
            }while(next_permutation (num1, num1 + n));
            if (sum == sum1)
                {
                    printf("Case %d: Yes\n", x++);
                    cout<<name[num[0]];
                    for (int i = 1; i < n; i++)
                        cout<<" "<<name[num[i]];
                    cout<<endl;
                    fg = 1;
                    break;
                }

        }while(next_permutation (num, num + n));
        if (!fg)
            printf("Case %d: No\n", x++);
    }
}
