#include<iostream>
#include<cmath>
#include <cstdio>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
{
    float a,b,c;
    double x1,x2;
    //cout<<"������a��b��c��"<<endl;
    cin>>a>>b>>c;
    if(a!=0)
    {
    if((b*b-4*a*c)>=0)
    {
    x1=(-b+sqrt(b*b-4*a*c))/(2*a);
    x2=(-b-sqrt(b*b-4*a*c))/(2*a);
    if (x1 == x2)
        //cout<<x1<<endl;
        printf("%.2lf\n", x1);
    else
    //cout<<<<x1<<" "<<<<x2<<endl;
    printf("%.2lf %.2lf\n", min(x1, x2), max(x1, x2));
    }
    else
    cout<<"NO"<<endl;

    }
    else
    {
    if(b==0)//2��=���ж���ȣ�һ���Ǹ�ֵ��
    {
        if(c==0)//����Ҳ��һ���ġ�
            cout<<"xΪ�����"<<endl;
        else
            cout<<"NO"<<endl;
    }
    else
    {
        x1=-c/b;
        x2=-c/b;
    }
     if (x1 == x2)
        //cout<<x1<<endl;
        printf("%.2lf\n", x1);
    else
    //cout<<<<x1<<" "<<<<x2<<endl;
    printf("%.2lf %.2lf\n", min(x1, x2), max(x1, x2));

}
}


}
