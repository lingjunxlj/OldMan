#include<iostream>
using namespace std;
typedef struct trees
{
    char data;
        struct trees*lc;
        struct trees*rc;
}trees;
template<class T>
class sqstack
{
    private:
        int m;
        int top;
        T *s;
    public:
        sqstack(int);
        void ins(T);
        T del();
        T rtop();
};
template<class T>
sqstack<T>::sqstack(int x)
{
    m=x;
    s=new T[m];
    top=0;
    return;
}
template<class T>
void sqstack<T>::ins(T x)
{
    top++;
    s[top-1]=x;
    return;
}
template<class T>
T sqstack<T>::del()
{
    T y=s[top-1];
    top--;
    return(y);
}
template<class T>
T sqstack<T>::rtop()
{
    return(s[top-1]);
}
void post(trees*);
void freeTree(trees*p);
int main()
{
    int t;char a;trees*p,*p2,*p3;
    sqstack<char>a_z(100);
    sqstack<trees*>diz(100);
    for(cin>>t,cin.get();t;t--)
    {
        while((a=cin.get())!='\n')
        {
            if(a>='a'&&a<='z')
            a_z.ins(a);
            else
            {
                p=new trees;p->data=a;p->lc=NULL;p->rc=NULL;
                if(a_z.rtop()>='a'&&a_z.rtop()<='z')
                {
                    p2=new trees;p2->data=a_z.del();p2->lc=NULL;p2->rc=NULL;
                    p3=new trees;p3->data=a_z.del();p3->lc=NULL;p3->rc=NULL;
                    p->lc=p3;p->rc=p2;
                    diz.ins(p);
                    a_z.ins(a);
                }
                else
                {
                    a_z.del();a_z.del();a_z.ins(a);
                    p->rc=diz.del();p->lc=diz.del();
                    diz.ins(p);
                }
            }
        }
        post(p);cout<<endl;freeTree(p);a_z.del();diz.del();
    }
}
void post(trees*p)
{
    if(p!=NULL)
    {
        post(p->lc);
        cout<<p->data;
        post(p->rc);
    }
}
void freeTree(trees *p)
{
    if(p->lc!=NULL)
    {
        freeTree(p->lc);
    }
    if(p->rc!=NULL)
    {
        freeTree(p->rc);
    }
    delete(p);
}
