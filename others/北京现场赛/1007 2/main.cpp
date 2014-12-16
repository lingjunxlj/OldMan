#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[50011];
int dp[50011];
const int MAXN = 50100;

int main()
{
    int t, x= 1;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        memset(dp, 0, sizeof(dp));
        memset(array, 0, sizeof(array));
        scanf("%d %d", &n, &m);
        scanf("%s", str);

        for (int i = 2; i < n; i++)
            if (str[i] == 'w' && str[i - 1] == 'b' && str[i - 2] == 'w')
                dp[i] = dp[i - 2] + 1;
            else
                dp[i] = dp[i - 1];

        //for (int i = 0; i < n; i++)
            //printf("%d ", dp[i]);
        //printf("\n");

        printf("Case %d:\n", x++);
        while(m--)
        {
            int op;
            scanf("%d", &op);
            if (op == 0)
            {
                int a, b;
                scanf("%d %d", &a, &b);

                //cout<<dp[-1]<<endl;
                printf("%d\n", dp[b] - dp[a]);

            }
            else
            {
                int a;
                char b[100];
                scanf("%d", &a);
                scanf("%s", &b);
                char temp = str[a];
                //str[a] = b[0];
                if (temp != b[0])
                {
                    str[a] = b[0];
                    if (a >= 2)
                    {
                        if (str[a - 1] == 'b' && str[a - 2] == 'w')
                        {
                            if (str[a] == 'w')
                            {
                                for (int i = a; i < n; i++)
                                    dp[i]++;
                            }
                            else
                            {
                                 for (int i = a; i < n; i++)
                                    dp[i]--;
                            }
                        }
                        if (str[a + 1] == 'b' && str[a + 2] == 'w')
                        {
                            if (str[a] == 'w')
                            {
                                for (int i = a + 2; i < n; i++)
                                    dp[i]++;
                            }
                            else
                            {
                                 for (int i = a + 2; i < n; i++)
                                    dp[i]--;
                            }


                        }


                    }
                    else
                    {
                        if (str[a + 1] == 'b' && str[a + 2] == 'w')
                            {
                                if (str[a] == 'w')
                                {
                                    for (int i = a + 2; i < n; i++)
                                        dp[i]++;
                                }
                                else
                                {
                                    for (int i = a + 2; i < n; i++)
                                        dp[i]--;
                                }


                            }
                    }
                }

            }
        }




    }
}
