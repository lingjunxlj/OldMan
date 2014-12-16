#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
struct Key
{
    int pos;
    char c;
};
bool cmp (const Key A, const Key B)
{
    return A.c < B.c;
}
char grids[20][200];
Key keys[30];
int main()
{
    int i, j;
    string temp;
    int l;
    while( getline(cin, temp) )
    {
        if(temp == "THEEND") break;
        l = temp.length();
        for(i = 0; i < l; i++)
        {
            keys[i].pos = i;
            keys[i].c = temp[i];
        }
        sort( keys, keys+l, cmp);
        getline(cin, temp);
        int pp = 0;
        for(i = 0; i<l; i++)
        {
            for(j = 1; j <= temp.length()/l; j++)
            {
                grids[j][keys[i].pos+1] = temp[pp++];
            }
        }
        for(int i=1;i<=temp.length()/l;i++)
        {
            for(int j=1;j<=l;j++)
            {
                cout<<grids[i][j];
            }
        }
        cout<<endl;
    }

}
