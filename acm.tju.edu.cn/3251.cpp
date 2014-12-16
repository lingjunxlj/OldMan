#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
 

int DateWeek(int year, int month, int day)

{

    if (month==1||month==2)

    {

       year -=1;

       month +=12;

    }

    return (day+1+2*month+3*(month+1)/5+year+(year/4)-year/100+year/400)%7;

}

int main()

{

    int w,year, month, day;

    year = 2009;

    cin>>day>>month;
	w=DateWeek(year,month,day);
    	if(w==1)
		cout<<"Monday"<<endl;
		if(w==2)
		cout<<"Tuseday"<<endl;
		if(w==3)
		cout<<"Wednesday"<<endl;
		if(w==4)
		cout<<"Thursday"<<endl;
		if(w==5)
		cout<<"Friday"<<endl;
		if(w==6)
		cout<<"Saturday"<<endl;
		if(w==0)
		cout<<"Sunday"<<endl;
	
	system("pause");
    return 0;

}
