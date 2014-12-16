#include<cstdio>
#include<cstring>
using namespace std;
char str1[101][31], str2[101][31];
int len1, len2, flag;
int dp[101][101];
int ans[101][101];
void print (int x, int y)
{
    if (x < 1 | y < 1)
	return;
    if (ans[x][y] == 0)
    {
    	print (x - 1, y - 1);
   		if (!flag)
			printf ("%s", str1[x]);
   		else
	   		printf (" %s", str1[x]);
   		flag = 1;
	}
	if (ans[x][y] == 1)
   	print (x - 1, y);
	if (ans[x][y] == 2)
   	print (x, y - 1);
}
int main ()
{
	char tmp[31];

	while (scanf ("%s", tmp) != EOF)
	{
   		len1 = len2 = 0;
   		while (strcmp (tmp, "#") != 0)
   		{
    		strcpy (str1[++len1], tmp);
    		scanf ("%s", tmp);
   		}
   		scanf ("%s", tmp);
   		while (strcmp (tmp, "#") != 0)
   		{
    		strcpy (str2[++len2], tmp);
    		scanf ("%s", tmp);
   		}
   		int i, j;

		memset (dp, 0, sizeof (dp));
		for (i = 1; i <= len1; i++)
   		for (j = 1; j <= len2; j++)
    	if (strcmp (str1[i], str2[j]) == 0)
    	{
     		dp[i][j] = dp[i-1][j-1] + 1;
     		ans[i][j] = 0;
    	}
    	else if (dp[i-1][j] > dp[i][j-1])
    	{
     		dp[i][j] = dp[i-1][j];
     		ans[i][j] = 1;
    	}
    	else
    	{
     		dp[i][j] = dp[i][j-1];
     		ans[i][j] = 2;
    	}
   		flag = 0;
   		print (len1, len2);
   		printf ("\n");
	}
	return 0;
}
