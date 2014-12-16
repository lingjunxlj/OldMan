#include<iostream>

using namespace std;
void print(int a,int p,int c)
{
 int i;
 if(p==1)
 {
  switch(a)
  {
  case 0:
  case 2:
  case 3:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9: cout<<'-';break;
  case 1:
  case 4:cout<<' ';break;
  }
 }
 if(p==2)
  {
  switch(a)
  {
  case 0:
  case 4:
  case 8:
  case 9:cout<<'|';for(i=0;i<c;i++)cout<<' ';cout<<'|';break;//cout<<"| |";break;
  case 1:
  case 2:
  case 3:
  case 7: cout<<' ';for(i=0;i<c;i++)cout<<' ';cout<<'|';break;
  case 5:
  case 6:cout<<'|';for(i=0;i<c;i++)cout<<' ';cout<<' ';break;
  }
 }
 if(p==3)
  {
  switch(a)
  {

  case 2:
  case 3:
  case 5:
  case 6:
  case 4:
  case 8:
  case 9: cout<<'-';break;
  case 0:
  case 1:
  case 7:cout<<' ';break;
  }
 }
 if(p==4)
  {
    switch(a)
    {
        case 0:
        case 8:
        case 6:cout<<'|';for(i=0;i<c;i++)cout<<' ';cout<<'|';break;
        case 1:
        case 3:
        case 4:
        case 5:
        case 9:
        case 7:cout<<' ';for(i=0;i<c;i++)cout<<' ';cout<<'|';break;
        case 2:cout<<'|';for(i=0;i<c;i++)cout<<' ';cout<<' ';break;
    }
 }
 if(p==5)
  {
  switch(a)
  {
  case 0:
  case 2:
  case 3:
  case 5:
  case 6:
  case 8:
  case 9: cout<<'-';break;
  case 7:
  case 1:
  case 4:cout<<' ';break;
  }
 }
}
int main()
{
 int i,j,a,b,u,p,k,t ;
 int s[8];
 t = 0;
 while(1)
 {
        cin>>a>>b;
  if(a==0&&b==0)
   break;
    if (t)
        cout<<endl;
    t++;
  i=0;
  if(b==0)
  {
   s[0]=0;
   i=1;
  }
  while(b!=0)
  {
   s[i]=b%10;
   b=b/10;
   i++;
  }
  for(p=1;p<=5;p++)
  {
   u=a;
     if(p==1||p==3||p==5)

     {
      for(j=i-1;j>=0;j--)
      {
           if(j==i-1)
          cout<<' ';
              for(k=0;k<a;k++)
     {
                 print(s[j],p,a);
     }
     if(j!=0)
            cout<<"   ";
      }
      cout<<endl;
   }

   else
   {
    while(u>0)
    {
        for(j=i-1;j>=0;j--)
     {
          print(s[j],p,a);
       if(j!=0)
        cout<<' ';
     }
     cout<<endl;
        u--;
    }
   }

  }

 }

 return 0;


}

