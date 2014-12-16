#include <stdio.h>
int main(void)
{  
    int n,m,a,b,c,i,j;
    static int origin[1001][1001];
    int opt[1001],max_distance=0,min,vertex;
    int result=0,line[1001],s[1001],e[1001],start;    
    bool flag[1001];       
    scanf("%d",&n);
    scanf("%d",&m);   
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                origin[i][j]=1000000;
            }
        }	    
        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            origin[a][b]=c;
            origin[b][a]=c;
            if(c>max_distance)
                max_distance=c;
        }              
        for(i=1;i<=n;i++)
        {
            opt[i]=origin[1][i];
            line[i]=1;
        }	
        flag[1]=true;
        for(i=2;i<=n;i++)
        flag[i]=false;
        for(i=1;i<n;i++)		
        {
            min=max_distance+1;
            for(j=1;j<=n;j++)
            {
                if(!flag[j]&&min>opt[j])
                {
		    
                    min=opt[j];
                    vertex=j;
                }
            }	    
            s[i]=vertex;
            e[i]=line[vertex];	    		
            if(result<min)
                result=min;
            flag[vertex]=true;	    	
            for(j=1;j<=n;j++)
            {
                if(!flag[j])
                {
                    if(origin[j][vertex]<opt[j])
                    {
                        opt[j]=origin[j][vertex];
			
                        line[j]=vertex;
                    }
                }

            }
        }
        printf("%d\n%d\n",result,n-1);
        for(i=1;i<n;i++)
        {
            printf("%d %d\n",s[i],e[i]);
        }
    return 1;
}
