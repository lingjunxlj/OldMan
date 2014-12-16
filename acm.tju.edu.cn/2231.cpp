#include<iostream>
#include<algorithm>
using namespace std;

int n , s ; 
int a[30];

int cmp ( const void * a ,const void * b ){
    return *(int*)b-*(int*)a;
}

bool dfs(int dep, int s){
    if (dep==n) return false;
    if (s-a[dep]==0) return true;
    if (dfs(dep+1,s-a[dep])) return true;
    if (dfs(dep+1,s))return true;
    return false;
}

int main(){
    while(cin>>n>>s){
        if (n==0&&s==0) break;
        for (int i=0;i<n;i++) cin>>a[i];
        qsort(a,n,sizeof(a[0]),cmp);
        if (dfs(0,s)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
