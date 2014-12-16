#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
int Score(double a,double b)
{
    a=sqrt(a*a+b*b);
	if(a<=3)return 100;
	else
		if(a<=6)return 80;
		else
			if(a<=9)return 60;
			else
				if(a<=12)return 40;
				else
					if(a<=15)return 20;
					else
						return 0;

}

int main()
{
    double x1, y1, x2, y2, x3, y3;
    double x4, y4, x5, y5, x6, y6;
    int point1=0, point2=0;
    while(cin>>x1>>y1)
    {
        if(x1 == -100)
        break;
        point1=0, point2=0;
        point1=point1 + Score(x1,y1);
        cin>>x2>>y2;
        point1=point1 + Score(x2,y2);
        cin>>x3>>y2;
        point1=point1 + Score(x3,y3);
        cin>>x4>>y4;
        point2=point2 + Score(x4,y4);
        cin>>x5>>y5;
        point2=point2 + Score(x5,y5);
        cin>>x6>>y6;
        point2=point2 + Score(x6,y6);

        if(point1 >= point2)
        {
            if(point1 == point2)
            printf("SCORE: %d to %d, TIE.\n",point1,point2);
            else  printf("SCORE: %d to %d, PLAYER 1 WINS.\n",point1,point2);
        }
        else printf("SCORE: point1 to point2, PLAYER 2 WINS.\n",point1,point2);
    }
    return 0;
}


