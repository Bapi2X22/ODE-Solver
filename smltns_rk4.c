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

int main()
{
	float y,z,k1,k2,k3,k4,m1,m2,m3,m4,t,h=.05;
	FILE *fp=NULL;
	fp=fopen("res.txt","w");
	t=0;
	y=1;
	z=0;
	do
	{
	
	k1=h*f(t,y,z);
	m1=h*g(t,z,y);
	k2=h*f(t+h/2.0,y+k1/2.0,z+m1/2.0);
	m2=h*g(t+h/2.0,z+m1/2.0,y+k1/2);
	k3=h*f(t+h/2.0,y+k2/2.0,z+m2/2.0);
	m3=h*g(t+h/2.0,z+m2/2.0,y+k2/2.0);
	k4=h*f(t+h,y+k3,z+m3);
	m4=h*g(t+h,z+m3,y+k3);
	y+=(k1+2*k2+2*k3+k4)/6.0;
	z+=(m1+2*m2+2*m3+m4)/6.0;
	t=t+h;
	fprintf(fp,"%f\t%f\n",t,y);
	printf("%f\t\t%f\t\t%f\n",t,y,z);
}
while(t<=10.0);
}

