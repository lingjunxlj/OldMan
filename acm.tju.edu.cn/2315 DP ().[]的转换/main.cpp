#include <string>
#include <iostream>
using namespace std;

int len;
int d[110][110];
char s[110], result[110];

string ans[110][110];

int main()
{
    int i, j, k, p, len;
    scanf("%s", s + 1);

    len = strlen(s + 1);

    for (i = 1; i <= len; i++)
    {

        d[i][i] = 1;

        if (s[i] == '(')
        ans[i][i] = "()";

        else if (s[i] == ')')
        ans[i][i] = "()";

        else if (s[i] == '[')
        ans[i][i] = "[]";

        else if (s[i] == ']')
        ans[i][i] = "[]";

    }
    for (p = 1; p <= len ; p++)
    {
        for (i = 1; i <= len - p; i++)
        {

            j = i + p;
            d[i][j] = 0x7fff;

            if (s[i] == '(' && s[j] == ')')
            {

                if (d[i + 1][j - 1] < d[i][j])
                {
                    d[i][j] = d[i + 1][j - 1];
                    ans[i][j] = '(' + ans[i + 1][j - 1] + ')';
                }

            }

            else if (s[i] == '[' && s[j] == ']')
            {
                if (d[i + 1][j - 1] < d[i][j])
                {
                    d[i][j] = d[i + 1][j - 1];
                    ans[i][j] = '[' + ans[i + 1][j - 1] + ']';
                }
            }

            for (k = i; k < j ; k++)
            {
                if (d[i][k] + d[k + 1][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k + 1][j];
                    ans[i][j] = ans[i][k] + ans[k + 1][j];
                }
            }


        }
    }

    cout << ans[1][len] << endl;
}
