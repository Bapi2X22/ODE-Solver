#include<stdio.h>
#include<math.h>
float f (float x,float y)
{
	return(x+y);
}
int main()
{
	float x,y,k1,k2,k3,k4,h=.001;
	FILE *fp1=NULL;
	fp1=fopen("res1.txt","w");
	y=1;
	x=0;
	do
	{
		
		k1=h*f(x,y);
		k2=h*f(x+h/2.0,y+k1/2.0);
		k3=h*f(x+h/2.0,y+k2/2.0);
		k4=h*f(x+h,y+k3);
		y+=(k1+2*k2+2*k3+k4)/6.00;
		x=x+h;
		if (x>=1)
	{
			fprintf(fp1,"%f\t%f\n",x,y);
		printf("%f\t\t%f\n",x,y);}
		
	}
	while (x<=5);
}
