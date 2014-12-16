#include <iostream>
using namespace std;
int i,l,n;
char irregular[30][25];
char plural[30][25];
char str[25];
bool is_consonant(char c)
{
	if((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'))
		return false;
	
	return true;
}

int is_irregular(char * str)
{
	for(int i=0; i<l; i++)
		if(strcmp(str, irregular[i]) == 0)
			return i;

	return -1;
}

int main()
{
	cin>>l>>n;

	for(i=0; i<l; i++)
		cin>>irregular[i]>>plural[i];

	for(i=0; i<n; i++)
	{
		cin>>str;

		int index = is_irregular(str);
		if(index != -1)
			cout<<plural[index]<<endl;
		else if(is_consonant(str[strlen(str)-2]) && (str[strlen(str)-1] == 'y'))
		{
			int pre_len = strlen(str);

			str[pre_len-1] = 'i';
			str[pre_len] = 'e';
			str[pre_len+1] = 's';
			str[pre_len+2] = '\0';

			cout<<str<<endl;
		}
		else if(	(str[strlen(str)-1] == 'o') || 
					(str[strlen(str)-1] == 's') || 
					(str[strlen(str)-1] == 'x') || 
					((str[strlen(str)-1] == 'h') && (str[strlen(str)-2] == 'c')) ||
					((str[strlen(str)-1] == 'h') && (str[strlen(str)-2] == 's')))
		{
			int pre_len = strlen(str);

			str[pre_len] = 'e';
			str[pre_len+1] = 's';
			str[pre_len+2] = '\0';

			cout<<str<<endl;
		}
		else
		{
			int pre_len = strlen(str);

			str[pre_len] = 's';
			str[pre_len+1] = '\0';

			cout<<str<<endl;
		}
	}

	return 0;
}
 
