
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAIN_MAX_COUNT 50050
#define SUB_MAX_COUNT 5

char mStr[MAIN_MAX_COUNT], pStr[SUB_MAX_COUNT];
char temp[50001];
inline void GetNextArray(char pstr[], int nextarr[])
{
	int m = 3;
	int k, q;
	nextarr[0] = -1;
	k = -1;

	for (q = 1; q < m; ++q)
	{
		while (k >= 0 && pstr[k + 1] != pstr[q])
			k = nextarr[k];
		if (pstr[k + 1] == pstr[q])
			++k;
		nextarr[q] = k;
	}
}
int nextarr[50001];
inline void KMP(char* a,char *b,int *next)
{
    int i=0,j=0;
    int n=0,lena,lenb;
    lena = strlen(a);
    lenb = 3;
  //while(i<strlen(a)) //continue with KMP way
  {
    while(i<lena)
    {
        if(a[i]==b[j])
        {
            i++;
            j++;
        }
        else if(j==0)
            i++;
        else
            j = next[j-1] + 1;
  //}
    if(j>=lenb) //匹配啦
    {
        n++;

        //i = i - next[j-1] - 1; //don't rewind i, KMP way

        //j=0;
        j = next[j-1] + 1; //keep along with KMP
    }
  }

  }
  printf("%d\n" ,n);

}
inline int KmpMatcher(char mstr[], char pstr[],int len)
{
	int n = len;
	int m = 3;
	//cout<<n<<"  "<<m<<endl;

	int i, q = -1, tms = 0;



	for (i = 0; i < n; ++i)
	{
		while (q >= 0 && pstr[q + 1] != mstr[i])
			q = nextarr[q];
		if (pstr[q + 1] == mstr[i])
			++q;
		if (q == m - 1)
		{
			++tms;
			q = nextarr[q];
		}
	}
	//free(nextarr);
	return tms;
}

int main()
{
	int t, x = 1;
	scanf ("%d", &t);
	strcpy(pStr, "wbw");
	while (t--)
	{
		int n, m;
		scanf ("%d%d", &n, &m);
		memset(mStr, 0, sizeof(mStr));
		//memset(pStr, 0, sizeof(pStr));
		scanf("%s", mStr);

		//cout<<pStr<<endl;
		printf("Case %d:\n", x++);
        GetNextArray(pStr, nextarr);

		while(m--)
		{

		    int op;
		    scanf ("%d", &op);
		    if (op == 0)
		    {
		        memset(temp, 0, sizeof(temp));
		        int a, b;
		        scanf("%d %d", &a, &b);
		        int top = 0;
		        for (int i = a; i <= b; i++)
                    temp[top++] = mStr[i];
                //cout<<temp<<endl;
		        printf ("%d\n", KmpMatcher(temp, pStr, b - a + 1));
		        //KMP(temp, pStr, nextarr);

		    }
		    else
		    {
		        int a;
		        char b[20];
		        scanf("%d", &a);
		        scanf("%s", b);
		        mStr[a] = b[0];
		    }

		}

	}

	return 0;
}
