#include<iostream>
#include<map>
#include<stack>
using namespace std;
struct MN
{
    int rows,cols;
    int em;
    MN(int r = 0,int c = 0,int e = 0):rows(r),cols(c),em(e){}
} ;
map<char,MN> M;
int main()
{
    int n,r = 0,c = 0;
    cin >> n;
    char a;
    for(int i = 0; i < n;i++)
    {
        cin >> a >> r >> c;
        M[a] = MN(r,c,0);
    }
    char str[100];
    stack<MN> S;
    while(scanf("%s",str) != EOF)
    {
        bool flag = true;
        int s = 0;
        int len = strlen(str);
        for(int i = 0; i < len&&flag;i++)
        {
            if(str[i] >= 'A'&&str[i] <= 'Z')
            S.push(M[str[i]]);
            else if(str[i] == ')')
            {
                MN b = S.top();
                S.pop();
                MN a = S.top();
                S.pop();
                if(a.cols != b.rows)
                {
                    flag = false;
                    break;
                }
                else
                {
                    s += a.rows*a.cols*b.cols;
                    MN c(a.rows,b.cols,s);
                    S.push(c);
                }
            }
            if(i == len - 1)
            break;
        }
        if(!flag)
        cout << "error" << endl;
        else
        {
            cout << S.top().em << endl;
            S.pop();
        }
    }
    return 0;
}
