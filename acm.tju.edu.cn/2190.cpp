#include<set>
using namespace std;
multiset<int>my;
int main()
{ 
    int n,i;
    while(scanf("%d",&n),n) 
    {       
        my.clear();     
        while(n--) 
        {    
            char temp;      
            scanf("\n%c",&temp);      
            if(temp=='B')   
            {       
                int x;       
                scanf("%d",&x);       
                my.insert(x);   
            }    
            else    
            {      
                int y=*my.begin();       
                printf("%d\n",y);    
                my.erase(my.begin());    
            } 
        } 
    } 
    return 0;
}
