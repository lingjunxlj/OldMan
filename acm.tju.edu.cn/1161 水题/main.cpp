#include<iostream>
#include<string.h>
using namespace std;
char str[100];
int len;
int REFER[26]={2,2,2, 3,3,3, 4,4,4, 5,5,5, 6,6,6, 7,0,7,7, 8,8,8, 9,9,9,0 };
int weight[10000000];
int POW[7]={1000000,100000,10000,1000,100,10,1};
char out[9];
int main()
{
	memset(weight,0,sizeof(weight));
	int n;
	scanf("%d",&n);
	int num,index;
	for(int mem=0;mem<n;mem++){
		scanf("%s",str);
		len=strlen(str);
		num=0;
		index=0;
		for(int i=0;i<len;i++){
			if(str[i]>='0' && str[i]<='9')
				num+=(str[i]-'0')*POW[index++];
			else if(str[i]>='A' && str[i]<='Z')
				num+=(REFER[int(str[i]-'A')])*POW[index++];
		}
		weight[num]++;
	}
	int xx=0;
	out[8]='\0';
	for(int i=0;i<10000000;i++){
		if(weight[i]>=2){
			for(int j=0;j<8;j++)
				out[j]='0';
			out[3]='-';
			int temp=i;
			int k=7;
			while(temp>0){
				if(k==3)
					k--;
				out[k]='0'+(temp-(temp/10)*10);
				temp/=10;
				k--;
			}
			printf("%s %d\n",out,weight[i]);
			xx++;
		}
	}
	if(xx==0)
		printf("No duplicates.\n");
	return 0;
}

