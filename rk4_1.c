#include<stdio.h>
#include<math.h>
float f (float t,float x)
{
	return (x*t*t+t*t*sin(t*t*t));
}
int main()
{
	float i,n,k1,k2,k3,k4,t,x,ti=0,tf=1.0,h=.05;
	FILE *fp=NULL;
	fp=fopen("res.txt","w");
	n=(tf-ti)/h;
	t=ti;
	x=1.0;
	for(i=1;i<=n;i++)
	{
		k1=h*f(t,x);
		k2=h*f(t+h/2.0,x+k1/2.0);
		k3=h*f(t+h/2.0,x+k2/2.0);
		k4=h*f(t+h,x+k3);
	    x+=(k1+2*k2+2*k3+k4)/6.0;
	    t=t+h;
		fprintf(fp,"%f\t%f\n",t,x);
		printf("%f\t\t%f\n",t,x);
	}
}
