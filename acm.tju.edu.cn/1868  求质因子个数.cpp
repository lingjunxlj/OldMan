#include <stdio.h> 


#define MAXN 1000005 

bool a[MAXN+1]={1,1,0}; 
int prime[80000]; 

void inita () 
{ 
    int i, j, k; 
    for (i=2; i*i<=MAXN; i++) 
        if (a[i]==0) 
            for (j=i*i;j<=MAXN;j+=i) 
                a[j]=1; 
} 

int main () 
{ 
    int input, count; 
    
    inita (); 
    while (scanf ("%d", &input) && input != 0) 
    { 
        if (!a[input]) 
        { 
            printf ("%d : %d\n", input, 1); 
            continue; 
        } 
        count = 0; 
        for (int i=2; i*i<=input; i++) 
            if (input%i==0) 
            { 
                if (!a[i]) 
                    count++; 
                if (!a[input/i]&&(i!=input/i)) 
                    count++; 
            } 
        printf ("%d : %d\n", input, count); 
    } 
    return 0;
} 
