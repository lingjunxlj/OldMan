#include <iostream>
#include <cmath>
#include <vector>
using namespace std ;

char v[250][250];
char temp[500];
vector<char> Ans ;
int R , Col ;

void getAnswer()
{
    int i , j , t ,s = 0 ;
    char a[10] , ai ;
    for(i = 0 ; i < strlen(temp) ; i+=5)
    {
        s = 0 ;
        for(j = i ,t = 0 ; j < i+5 && j < strlen(temp) ; j++,t++)
        {
            if(temp[j] == '1')
            s+=pow(2.0,5-t-1) ;
        }
        if(t < 5)
        {
            for(j = i , ai = 0 ; j < strlen(temp);ai++ , j++)
            a[ai] = temp[j] ;
            a[ai] = '\0' ;
            while(ai < 5)
            {
                a[ai] = '0' ;
                ai++ ;
            }
            a[ai] = '\0' ;
            s = 0 ;
            for(ai = 0 ; ai < 5 ; ai++)
            if(a[ai] == '1')
            s+=pow(2.0,5-ai-1) ;
            if(s != 0)
            Ans.push_back(--s+'A') ;
            break ;
    }
    if(s == 0 && t == 5 )
    Ans.push_back(' ') ;
    else if(s != 0)
    Ans.push_back(--s+'A') ;
    }
    for(i = Ans.size()-1 ; i >= 0 ; i--)
    if(Ans[i] == ' ')
    Ans.pop_back() ;
    else
    break ;
    for(i = 0 ; i < Ans.size() ; i++)
    printf("%c",Ans[i]) ;
    printf("\n") ;
    Ans.erase(Ans.begin(),Ans.end()) ;
}
int judge(int Count , int s)
{
    if(Count == s)
    return 1 ;
    return 0 ;
}
void search()
{
    int index(0) ,flag(0) ;
    int sx(0) , sy(0) ,t(0) , Count = 0 ;
    int r = R , c = Col ;
    int s = R*Col ;
    while(Count < s)
    {
        flag = 0 ;
        while(sy < c)
        {
            temp[index++] = v[sx][sy++] ;
            Count++ ;
            flag = 1 ;
        }
        if(judge(Count,s))
        break ;
        if(flag)
        {
            sy-- ;
            sx++ ;
        }
        flag = 0 ;
        while(sx < r)
        {
            temp[index++] = v[sx++][sy] ;
            Count++ ;
            flag = 1 ;
        }
        if(judge(Count,s))
            break ;
        if(flag)
        {
            sx-- ;
            sy-- ;
        }
        flag = 0 ;
        while(sy >=t)
        {
            temp[index++] = v[sx][sy--] ;
            Count++ ;
            flag = 1 ;
        }
        if(judge(Count,s))
        break ;
        if(flag)
        {
            sx-- ;
            sy++ ;
        }
        flag = 0 ;
        while(sx > t)
        {
            temp[index++] = v[sx--][sy] ;
            Count++ ;
            flag = 1 ;
        }
        if(judge(Count,s))
        break ;
        if(flag)
        {
            sx++ ;
            sy++ ;
        }
        t++ ;
        r-- ;
        c-- ;
    }
    temp[index] = '\0' ;
    getAnswer() ;
}

int main()
{
    int T , i , j ;
    scanf("%d",&T) ;
    for(int k = 0 ; k < T ; k++)
    {
        scanf("%d %d",&R,&Col) ;
        getchar() ;
        for(i = 0 ; i < R ; i++)
        {
            for(j = 0 ; j < Col ; j++)
            {
                scanf("%c",&v[i][j]) ;
            }
        }
        getchar() ;
        printf("%d ",k+1) ;
        search() ;
    }
}
