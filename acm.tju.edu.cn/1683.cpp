#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
    int a[300][300];
	char str1[100],str2[100];
	int len1,len2,i,j;
	while(cin>>str1>>str2)
	{
		
		j=0;
		len1 = strlen(str1);
		len2 = strlen(str2);
		for(i=0;i<len1;i++)
            for(j=0;j<len2;j++)
                if(str1[i]==str2[j]) a[i+1][j+1]=a[i][j]+1;
                else a[i+1][j+1]=a[i][j+1]>a[i+1][j]?a[i][j+1]:a[i+1][j];
        cout<<a[len1][len2]<<endl;
    }
    system("pause");
}

