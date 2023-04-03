#include<stdio.h>
#include<math.h>
float f(float t,float x)
{ return (x*t*t+t*sin(pow(t,3))) ; }


int main ()
{ 
float f(float t,float x);
float t =0,x =1.0,s,h,ti,tf; 
int i ,n; 
float k1,k2,k3,k4;

FILE *res1=NULL;
res1=fopen("res.txt","w");

ti =0;
tf = 1.0;
h=0.05;
do
{
	x=x+h*f(t,x) + h^2 f(t,x) /2! + h*h*h*h * F();   
	t=t+h;
	fprintf(res1,"%f\t%f\n" ,t,x);
}
while (t<=tf);

//for(t=h;t<tf;t+=h)
//{
//s =-0.3*cos(pow(t,3))-0.1*sin(pow(t,3))+1.3*exp(0.33*pow(t,3));
//fprintf(res2,"%f %f\n",t,s);
//}

}
