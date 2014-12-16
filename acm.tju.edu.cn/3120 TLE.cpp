#include <stdio.h> 
#include <string.h> 
int num,s[100001],follow[100001]; 
int main() 
{               
               int t,j,c=0,res,max;               
               while(scanf("%d",&num)) 
               { 
                      res=0;  
					  memset(follow,0,sizeof(follow));			                  
                      for(t=0;t<num;t++) 
                      scanf("%d",&s[t]); 
                      for(t=num-1;t>=0;t--) 
                      { 
                              max=0; c=0;
                              for(j=t+1;j<num;j++) 
                                           if(s[j]>s[t]) 
                                                    if(max<follow[j]) 
                                                               max=follow[j]; 
                              
							  follow[t]=max+1;
                              if(res<follow[t]) res=follow[t];
                    	} 
                        printf("%d\n",res); 
                 } 
                 
}

				
				
				
				
				
					
		
