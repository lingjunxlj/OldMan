#include <cstdio>
#include <cstdlib>
#include <cstring>

char word[201][222];
int aii[201];
char letter[282];
char b[222];
int main()
{
	memset(word,'0',sizeof(word));
	memset(aii,0,sizeof(aii));
	memset(letter,'0',sizeof(letter));
	int len=0;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",word[i]);
		getchar();
		int sum=0;
		for(int j=0;j<strlen(word[i]);j++)
			sum+=word[i][j];
		aii[i]=sum;
	}
	
	while(gets(letter))
	{
		int u=0;
		int s=0;
		for(int k=0;k<strlen(letter)+1;k++)
		{
			
			if(letter[k]!=' '&&letter[k]!='\0')
			{
				b[u]=letter[k];
				s+=letter[k];
				u++;
			}
			else
			{
				len++;
					for(int h=0;h<n;h++)
						if(aii[h]==s)
						{
							printf("%s",word[h]);
							memset(b,0,sizeof(b));
							s=0;
							u=0;
						}
				printf("%c",letter[k]);
			}
		}
		printf("\n");
		
	}
}
