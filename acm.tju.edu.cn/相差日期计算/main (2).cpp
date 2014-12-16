#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
char map[151][71];
char in[71];
int next[1000001];
char kp[1000001];  //Ô­´®
void init()
{
	int i,j;
	next[0] = -1;
	j = -1;
	i = 0;
	while(kp[i])
	{
		if(j == -1 || kp[i] == kp[j])
		{
			i++;
			j++;
			if(kp[i] != kp[j]) next[i] = j;
			else next[i] = next[j];
		}
		else j = next[j];
	}
}
int KMP()
{
	int i,j,l;
	i = j = 0;
	l = strlen(kp);
    init();
	while(in[i] && j < l)
	{
		if(j == -1 || in[i] == kp[j])
		{
			i++;
			j++;
		}
		else j = next[j];
	}
	if(j == l) return i;
	return -1;
}

int main()
{
    int n;

    while (scanf("%d",&n),n)
    {
        int i;
        for (i=0;i<n;i++)
        cin>>map[i];
        cin>>kp;
        init();
        int flag[151],max=-1;
        memset(flag,0,sizeof(flag));
        for (i=0;i<n;i++)
        {
            strcpy(in,map[i]);
            flag[i]=KMP();
            if (flag[i]>max)
            max=flag[i];
        }
        cout<<max<<endl;
        for (i=0;i<n;i++)
        if (flag[i]==max)
        cout<<map[i]<<endl;
    }
}








