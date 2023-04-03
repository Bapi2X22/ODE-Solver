#include<stdio.h>
#include<math.h>
#define pi 3.14159
float f(float z,float y,float t)
{
	return(z);
}
float g(float z,float y,float t)
{
	return(-sin(y));
}
int main()
{
	float a,x,y,z,t,i,h,n,k1,k2,k3,k4,m1,m2,m3,m4;
	int k,h1;
	
	printf("give amplitude: ");
	scanf("%f",&a);
	FILE *fp=NULL;
	fp=fopen("res.txt","w");
	
	y=a;
	z=0.0;
	t=0.0;
	h=.01;
	n=8*pi/h;
	for(i=1.0;i<=n;i++)
	{
		k1=h*f(z,y,t);
		m1=h*g(z,y,t);
		k2=h*f(z+m1/2.0,y+k1/2.0,t+h/2.0);
		m2=h*g(z+m1/2.0,y+k1/2.0,t+h/2.0);
		k3=h*f(z+m2/2.0,y+k2/2.0,t+h/2.0);
		m3=h*g(z+m2/2.0,y+k2/2.0,t+h/2.0);
		k4=h*f(z+m3,y+k3,t+h);
		m4=h*g(z+m3,y+k3,t+h);
		y=y+(k1+2*(k2+k3)+k4)/6.0;
		z=z+(m1+2*(m2+m3)+m4)/6.0;
		t=t+h;
		fprintf(fp,"%f\t%f\n",t,y);
	}
}













//do
//	{
//	k1=h*f(t,y,z);
//	m1=h*g(t,z,y);
//	k2=h*f(t+h/2.0,y+k1/2.0,z+m1/2.0);
//	m2=h*g(t+h/2.0,z+m1/2.0,y+k1/2);
//	k3=h*f(t+h/2.0,y+k2/2.0,z+m2/2.0);
//	m3=h*g(t+h/2.0,z+m2/2.0,y+k2/2.0);
//	k4=h*f(t+h,y+k3,z+m3);
//	m4=h*g(t+h,z+m3,y+k3);
//	y+=(k1+2*k2+2*k3+k4)/6.0;
//	z+=(m1+2*m2+2*m3+m4)/6.0;
//	t=t+h;
//	fprintf(fp,"%f\t\t%f\t\t%f\n",t,y,z);
////	printf("%f\t\t%f\t\t%f\n",t,y,z);
//			
//	}
//	while (t<=8*pi);
