#include<stdio.h>
#include<string.h>
int main()
{
	int i,Len;
	char a[200]; 
    while (1)
	{
		gets(a);
		Len=strlen(a);
		if(strcmp(a,"START")==0||strcmp(a,"END")==0);
		else if(strcmp(a,"ENDOFINPUT")==0)break;
		else
		{
			for(i=0;i<Len;i++)
			{
				if(a[i]<='Z'&&a[i]>='A')
				{
					if(a[i]<='E')
						a[i]=a[i]-5+26;
					else a[i]=a[i]-5;
				}
			}
			puts(a);
		}
	}
}
 
