#include <iostream>
#include <string>
using namespace std;
int i,j,N,M;
int main()
{
    string str1[51];
    string flag;
    cin>>N;
    for (i=0;i<N;i++)
    cin>>str1[i];
    cin>>M;
    while (M--)
    {
        cin>>flag;
        for (i=0;i<N;i++)
        {
            int temp=flag.find(str1[i]);
            if (temp>=0)
            {
                cout<<"A new hero discovered"<<endl;
                break;
            }

        }
        if (i==(N))
        cout<<"Just an ordinary person"<<endl;
    }
}

