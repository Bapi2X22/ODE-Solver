//    solve dy/dx=x+y



#include<stdio.h>
#include<math.h>
float f (float x,float y)
{
	return(x+y);
}

int main()
{
	float x,y,h=.001;
	FILE *fp=NULL;
	fp=fopen("res.txt","w");
	y=1;
	x=0;
	do
	{
		
		y+=h*f(x,y);
		x=x+h;
		fprintf(fp,"%f\t%f\n",x,y);
		printf("%f\t\t%f\n",x,y);
		
	}
	while (x<=5);
}
