#include <iostream>
using namespace std;  
int main()
{
    int Z, I, M, L ;
    int temp, count ,next;
    int index = 1 ;
    while (1) 
    { 
        cin>>Z>>I>>M>>L ; 
        if (Z==0 && I==0 && M==0 && L==0) break;
        count = 1 ;  
        next = temp = (Z*L+I)%M ;
        while (temp != L) 
        {
            temp = (Z*temp+I)%M ;  
            if (temp == next) 
            break;
            else
            count++;
        }
        cout <<"Case "<<index++<<": "<<count<<endl;
        
    }        
    return 0;
}     
 
