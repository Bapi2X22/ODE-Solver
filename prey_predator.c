#include<stdio.h>
#include<math.h>
double dx(double t, double x, double y, double gamma1, double gamma2){
    return gamma1*x-gamma2*x*y;
}
double dy(double t, double x, double y, double gamma3, double gamma4){
    return -gamma3*y+gamma4*x*y;
}
int main(){
    FILE *fp=NULL;
    fp=fopen("res.txt","w");
    double gamma1=0.25, gamma2=0.01, gamma3=1, gamma4=0.01;
    double t0=0,x0=100,y0=5,x,y,t=t0,tf=20;
    double h=0.01;
    double k1,k2,k3,k4,m1,m2,m3,m4;
    while(t<=tf){
        fprintf(fp,"%lf\t%lf\t%lf\n",t0,y0,x0);
        k1=h*dx(t0,x0,y0,gamma1,gamma2);
        m1=h*dy(t0,x0,y0,gamma3,gamma4);
        k2=h*dx(t0+h/2.0,x0+k1/2.0,y0+m1/2.0,gamma1,gamma2);
        m2=h*dy(t0+h/2.0,x0+k1/2.0,y0+m1/2.0,gamma3,gamma4);
        k3=h*dx(t0+h/2.0,x0+k2/2.0,y0+m2/2.0,gamma1,gamma2);
        m3=h*dy(t0+h/2.0,x0+k2/2.0,y0+m2/2.0,gamma3,gamma4);
        k4=h*dx(t0+h,x0+k3,y0+m3,gamma1,gamma2);
        m4=h*dy(t0+h,x0+k3,y0+m3,gamma3,gamma4);
        t=t0+h;
        x=x0+(k1+2*(k2+k3)+k4)/6.0;
        y=y0+(m1+2*(m2+m3)+m4)/6.0;
        x0=x;
        y0=y;
        t0=t;   
    }
 
}

