#include<iostream>
#include<cmath>
#include<map>
using namespace std;
int main()
{
    multimap<double,double > map;
    int m, n, l, w;
    cin>>m;
    while(m--)
    {
        int count = 0;
        cin>>n>>l>>w;
        while(n--)
        {
            double X, R, cpend, cpbegin, temp;
            cin>>X>>R;
            if((R*R - (w/2) * (w/2)) >= 0)
            {
                temp = sqrt(R*R - (w/2) * (w/2));
                cpbegin=X - temp;
                cpend=X + temp;
                map.insert(make_pair(cpbegin,cpend));
            }
        }
        multimap<double,double, greater<double > > after;
        multimap<double,double >::iterator it=map.begin(), end=map.end();
        bool go, endonce = 0;
        double Jie = 0;
        while(it != end)
        {
            if(it->first<=Jie)
            {
                after.insert(make_pair(it->second,it->first));
                go=0;
            }
            if((it->first>=Jie)||(it->second>l))
            {
                count++;
                go=1;
            }
            it++;
            if(go)
            {
                multimap<double,double, greater<double> >::iterator newit = after.begin();
                Jie=newit->first;
                if(Jie>=l)
                {
                    endonce=1;
                    break;
                }
                after.clear();
            }
        }
        if(endonce)
            cout<<count<<endl;
        else
            cout<<0<<endl;
        map.clear();
   }
}
