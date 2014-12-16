#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;

double r,w,v,k,E,mul[2],temp,sum,r2,eps;

int main(){
double i;
while (1){
scanf("%lf%lf%lf%lf%lf",&r,&w,&v,&k,&E);
eps=1e-5;
if (r<eps&&w<eps&&v<eps&&k<eps&&E<eps) break;
E/=k;
sum=0;
r2=r*r;
temp=2*r*sin(w/2*eps);
temp*=temp;
mul[0]=sqrt(temp+(v*eps*v*eps));
for (i=eps/2;;i+=eps){
temp=mul[0]*sqrt(r2+v*i*v*i);
sum+=temp;
if (sum>E){
sum-=temp;
break;
}
}
if (i<eps) i=0;
else i-=eps;
eps=1e-6;
temp=2*r*sin(w/2*eps);
temp*=temp;
mul[1]=sqrt(temp+(v*eps*v*eps));
i+=eps/2;
for (;;i+=eps){
temp=mul[1]*sqrt(r2+v*i*v*i);
sum+=temp;
if (sum>E) break;
}
printf("%.4lf\n",i);
}
return 0;
}
