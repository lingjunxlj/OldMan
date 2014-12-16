#include "iostream"
#include "stack"
using namespace std;
int link[30][30],degree_in[30],degree[30],Top[30];
char a,b,c;
bool only,visit_m[30];
int n,m,record,count_n,circle;
int Top_sort()
{
    only = true;
    record = 0;
    stack<int> s;
    int i, j;
    for( i = 1; i <= n; i++)
    {
        if(visit_m[i] && !degree_in[i])
        {
            s.push(i);
            degree[i] = -1;
        }
    }
    if(s.size() > 1)
    only = false;
    while(!s.empty())
    {
        int t = s.top();
        Top[record++] = t;
        s.pop();
        for( i = 1; i <= n; i++)
        {
            if(link[t][i] == 1)
            {
                degree[i]--;
                for( j = 1; j <= n; j++)
                {
                    if(visit_m[j] && !degree[j])
                    {
                        s.push(j);
                        degree[j] = -1;
                    }
                }
            }
        }
        if(s.size() > 1)
        only=false;
    }
    for(int j = 1; j <= n; j++)
    {
        if(degree[j] > 0)
        return -1;
    }
    if(record == n && only)
    {
        return 1;
    }
    return 0;
}

int main()
{

    while(cin>>n>>m && n!=0&&m!=0)
    {
        int i, s;
        circle = -1;
        count_n = -1;
        record = 0;
        memset(link, 0, sizeof(link));
        memset(degree_in, 0, sizeof(degree_in));
        memset(visit_m, false, sizeof(visit_m));
        memset(degree, 0, sizeof(degree));
        for(i = 1; i <= m; i++)
        {
            cin>>a>>c>>b;
            int a1 = (int)( a - 'A' ) + 1;
            int b1 = (int)( b - 'A' ) + 1;
            if(circle == -1 && count_n == -1)
            {
                visit_m[a1] = true;
                visit_m[b1] = true;

                if(link[a1][b1] != 1)
                degree_in[b1]++;
                link[a1][b1] = 1;

                for(int j = 1; j <= n; j++)
                degree[j] = degree_in[j];
                s = Top_sort();
                if(s == 1)
                count_n = i;
                else if(s == -1)
                circle = i;
            }
        }
        if(s == 1)
        {
            cout<<"Sorted sequence determined after "<<count_n<<" relations: ";
            for(i = 0; i < n; i++)
            cout<<char(Top[i] + 64);
            cout<<"."<<endl;
        }
        if(s == -1)
        cout<<"Inconsistency found after "<<circle<<" relations."<<endl;
        if(s == 0)
        cout<<"Sorted sequence cannot be determined."<<endl;
    }
}


