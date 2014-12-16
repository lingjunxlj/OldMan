#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main(){
    int a[20];
    do{
        cin>>a[0];
        int i=0,j,k;
        if (a[0]==-1) break;
        while (a[i]!=0) {
          i++;
         cin>>a[i];
        }
        int count=0;
        for (j=0;j<i;j++){
            for (k=0;k<i;k++){
                if (a[j]==a[k]*2) 
                  count++;
            }
        }
     cout<<count<<endl;
    }while (a[0]!=-1);
    return 0;
} 
