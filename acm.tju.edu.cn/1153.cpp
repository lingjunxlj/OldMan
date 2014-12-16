#include <cstdio>
#include <string>
#include <iostream> 
using namespace std;
int main()
{
   int n, m;
   char word[100];     
   cin >> m;        
   while(m)
   {
    	cin >> word;  
		int len;
		len=strlen(word);           
		for(int i = len - 1; i >= 0; i--)		
            cout << word[i];
        	if(getchar() == '\n')
        	{
        	    m--;
       	     	cout << endl;
       	 	}
        	else
            	cout << ' ';
		}
            
     return 0;
 }
