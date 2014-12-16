#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	   int no;
	   node *next;
}*first,*list,*newnode;
bool f[1001][1001];
int main(){
    int t,n,a,b,temp,i,j;
    bool flag;

    while(scanf("%d",&n)!=EOF){
        memset(f,0,sizeof(f));
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
			    scanf("%d",&t);
			    if(t) f[i+1][j+1]=1;
            }
		}
		printf("1\n%d\n",n);
		if(n==1) {printf("1\n");continue;}
		first=new node;
		first->next=NULL;
		first->no=1;
		for(i=2;i<=n;i++){
            flag=1;
            newnode=new node;
            newnode->no=i;
            if(f[i][first->no]){
                newnode->next=first;
                first=newnode;
                flag=0;
			}
			if(flag){
	            list=first;
                while(list->next!=NULL&&flag){
		            if(f[list->no][i]&&f[i][list->next->no]){
                        newnode->next=list->next;
                        list->next=newnode;
                        flag=0;
				    }
				    list=list->next;
			    }
			    if(flag&&f[list->no][i]) {
	                 newnode->next=NULL;
                     list->next=newnode;
                }
		    }
	    }
	    while(first->next!=NULL){
	        printf("%d ",first->no);
	        first=first->next;
	    }
	    printf("%d\n",first->no);
    }
    //system("pause");
    return 0;
}
