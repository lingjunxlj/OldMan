#include <string>
#include <cstdio>
char a[200], b[200];
int main()
{
     int i, flag, flag1, k, flag2;
    a['A']='A';
    //a['B']=' ';
    //a['C']=' ';
    //a['D']=' ';
    a['E']='3';
    //a['F']=' ';
    //a['G']=' ';
    a['H']='H';
    a['I']='I';
    a['J']='L';
    //a['K']=' ';
    a['L']='J';
    a['M']='M';
    //a['N']=' ';
    a['O']='O';
    //a['P']=' ';
    //a['Q']=' ';
    //a['R']=' ';
    a['S']='2';
    a['T']='T';
    a['U']='U';
    a['V']='V';
    a['W']='W';
    a['X']='X';
    a['Y']='Y';
    a['Z']='5';
    a['1']='1';
    a['2']='S';
    a['3']='E';
    //a['4']=' ';
    a['5']='Z';
    //a['6']=' ';
    //a['7']=' ';
    a['8']='8';
    //a['9']=' ';
    //a['0']=' ';

    while(scanf("%s", b)!=EOF)
    {
        k=strlen(b);
        flag=1;
        if(k%2)
        {
            if(a[b[k/2]]!=b[k/2])
            {
                flag=2;
            }
        }
        for(i=0;i<k/2;i++)
        {

            if(flag==1 && (a[b[i]]==b[k-1-i] || b[i]==a[b[k-1-i]]) && b[i]==b[k-1-i])
            continue;

            if(b[i]==b[k-i-1])
            {
                if(flag!=3)
                    flag=2;

                continue;
            }
            if(a[b[i]]==b[k-1-i] || b[i]==a[b[k-1-i]])
            {
                flag=3;
                continue;
            }
            flag=0;
            break;
        }
        if(flag==2)
            printf("%s -- is a regular palindrome.\n\n",b);
        else
        {
            if(flag==3)
                printf("%s -- is a mirrored string.\n\n",b);

            else
            {
                if(flag==1)
                    printf("%s -- is a mirrored palindrome.\n\n",b);
                else
                    printf("%s -- is not a palindrome.\n\n",b);
            }
        }
    }
}
