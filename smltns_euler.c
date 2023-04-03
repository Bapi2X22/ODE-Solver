#include<math.h>
#include<stdio.h>
float f (float t,float y,float z)
{
	return (z);
}
float g (float t,float z,float y)
{
	return(-y);
}

main()
{
	float y,z,n,t,h=.05;
	FILE *fp=NULL;
	fp=fopen("res.txt","w");
	t=0;
	y=1;
	z=0;
	do
	{
       y+=h*f(t,y,z);
       z+=h*g(t,z,y);
       t+=h;
	fprintf(fp,"%f\t\t%f\t\t%f\n",t,y,z);
	//printf("%f\t\t%f\t\t%f\n",t,y,z);
}
while(t<=10.0);
}

