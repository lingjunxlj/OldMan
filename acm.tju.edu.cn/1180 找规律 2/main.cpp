#include<iostream>
#include<vector>
using namespace std;

vector<int> data;

void Inversion(int n,int t){
    int i=1,j;
    while(i*(i-1)/2<t) i++;
    for(j=1;j<=n-i;j++) data.push_back(j); //n-i以前的数1~n-i直接按顺序压入
    int p=i-1;
    int need=t-p*(p-1)/2;
    int just=n-i+need+1;
    data.push_back(just);
    for(j=n;data.size()<n;j--){
        if(j!=just) data.push_back(j);
    }
}

int main()
{
    int N,T;
    while(cin>>N&&cin>>T&&N!=-1)
    {
        data.clear();
        Inversion(N,T);
        for(int y=0;y<(data.size());y++)
        {
            if (y!=data.size()-1)
            cout<<data[y]<<" ";
            else
            cout<<data[y];
        }
            cout<<endl;
    }
    return 0;
}
