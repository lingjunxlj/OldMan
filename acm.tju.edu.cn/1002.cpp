#include<iostream>
#include<string.h>
#include <stdlib.h>
using namespace std;

int out(int num_day){
     string s2;
         if(num_day==1)s2="imix";
    else if(num_day==2)s2="ik";
    else if(num_day==3)s2="akbal";
    else if(num_day==4)s2="kan";
    else if(num_day==5)s2="chicchan";
    else if(num_day==6)s2="cimi";
    else if(num_day==7)s2="manik";
    else if(num_day==8)s2="lamat";
    else if(num_day==9)s2="muluk";
    else if(num_day==10)s2="ok";
    else if(num_day==11)s2="chuen";
    else if(num_day==12)s2="eb";
    else if(num_day==13)s2="ben";
    else if(num_day==14)s2="ix";
    else if(num_day==15)s2="mem";
    else if(num_day==16)s2="cib";
    else if(num_day==17)s2="caban";
    else if(num_day==18)s2="eznab";
    else if(num_day==19)s2="canac";
    else s2="ahau";
    cout<<s2<<" ";
}
int main(){
    int num,sum,year,i,day,month,tzolkin_year,number,num_day;
   
    cin>>num;
    cout<<num<<endl;
    int shu[num][3];        
    int u=0; 
   while(u<num){
             string str,jia_str;
               cin>>str>>jia_str>>year;
               if(str[0]=='-'||year<0)break;
               int len=str.length();
               for(i=0;i<len&&str[i]!='.';i++);
               if(i==1){
                       day=str[0]-48;
                       }
                       
               if(i==2){
                        day=(str[0]-48)*10+str[1]-48;
                        if(day>19)break;
                        }        
               if(i>2)break;
            
               i=i+1;
              int cha =len-i;
              
              if(jia_str=="pop")month=1;
        else if(jia_str=="no")month=2;
        else if(jia_str=="zip")month=3;
        else if(jia_str=="zotz")month=4;
        else if(jia_str=="tzec")month=5;
        else if(jia_str=="xul")month=6;
        else if(jia_str=="yoxkin")month=7;
        else if(jia_str=="mol")month=8;
        else if(jia_str=="chen")month=9;
        else if(jia_str=="yax")month=10;
        else if(jia_str=="zac")month=11;
        else if(jia_str=="ceh")month=12;
        else if(jia_str=="mac")month=13;
        else if(jia_str=="kankin")month=14;
        else if(jia_str=="muan")month=15;
        else if(jia_str=="pax")month=16;
        else if(jia_str=="koyab")month=17;
        else if(jia_str=="cumhu")month=18;
        else if(jia_str=="uayet")month=19;
        else break;
        if(jia_str=="uayet"&&day>4)break;
        sum=(month-1)*20+day+1+year*365;
  
        tzolkin_year=sum/260;
        int temp=sum%260;
        if(temp==0){
                    number=14;
                   tzolkin_year=tzolkin_year-1; 
                    }
         else{           
        number=temp%13+1;
        }
        num_day=temp%20+1;
    
          u++;
       
        cout<<number-1<<" ";
        out(num_day-1);
        cout<<tzolkin_year<<endl;
  
        }  
		system("pause");                                                                                                
return 0;
}
