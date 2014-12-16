#include<stdio.h>
#include<string.h>
int insert(int date,char month[],int year)
{
 int day,mon,i,j,yeart,day0;
 char ch[10];
 if(strcmp(month,"pop")==0)
  mon=1;
 else if(strcmp(month,"no")==0)
  mon=2;
 else if(strcmp(month,"zip")==0)
  mon=3;
 else if(strcmp(month,"zotz")==0)
  mon=4;
 else if(strcmp(month,"tzec")==0)
  mon=5;
 else if(strcmp(month,"xul")==0)
  mon=6;
 else if(strcmp(month,"yoxkin")==0)
  mon=7;
 else if(strcmp(month,"mol")==0)
  mon=8;
 else if(strcmp(month,"chen")==0)
  mon=9;
 else if(strcmp(month,"yax")==0)
  mon=10;
 else if(strcmp(month,"zac")==0)
  mon=11;
 else if(strcmp(month,"ceh")==0)
  mon=12;
 else if(strcmp(month,"mac")==0)
  mon=13;
 else if(strcmp(month,"kankin")==0)
  mon=14;
 else if(strcmp(month,"muan")==0)
  mon=15;
 else if(strcmp(month,"pax")==0)
  mon=16;
 else if(strcmp(month,"koyab")==0)
  mon=17;
 else if (strcmp(month,"cumhu")==0)
  mon=18;
 else if(strcmp(month,"uayet")==0)
  mon=19;
 day=(mon-1)*20+date+1+365*year;
 yeart=day/260;
 day0=day-yeart*260;
 if(day0%260==0)
  printf("13 ahau %d\n",(yeart-1)); 
 else {
  if(day0%13==0)
   i=13;
  else i=day0-(day0/13)*13;
  if(day0%20==0)
   j=20;
  else j=day0-(day0/20)*20;
  switch (j)
  {
   case 1:strcpy(ch,"imix");break;
   case 2:strcpy(ch,"ik");break;
   case 3:strcpy(ch,"akbal");break;
   case 4:strcpy(ch,"kan");break;
   case 5:strcpy(ch,"chicchan");break;
   case 6:strcpy(ch,"cimi");break;
   case 7:strcpy(ch,"manik");break;
   case 8:strcpy(ch,"lamat");break;
   case 9:strcpy(ch,"muluk");break;
   case 10:strcpy(ch,"ok");break;
   case 11:strcpy(ch,"chuen");break;
   case 12:strcpy(ch,"eb");break;
   case 13:strcpy(ch,"ben");break;
   case 14:strcpy(ch,"ix");break;
   case 15:strcpy(ch,"mem");break;
   case 16:strcpy(ch,"cib");break;
   case 17:strcpy(ch,"caban");break;
   case 18:strcpy(ch,"eznab");break;
   case 19:strcpy(ch,"canac");break;
   case 20:strcpy(ch,"ahau"); 
  }
  printf("%d %s %d\n",i,ch,yeart);
 }
} 
int main()
{
 int date,year;
 char month[10];
 int i,n;
 scanf("%d",&n);
 getchar();
 if(n!=0) printf("%d\n",n);
 for(i=0;i<n;i++)
 {
  scanf("%d",&date);
  getchar();
  scanf("%s%d",month,&year);
  insert(date,month,year);
 }
}



