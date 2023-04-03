#include<stdio.h>
#include<math.h>
double dx(double t, double x, double y, double z){
    return -10*(x-y);
}
double dy(double t, double x, double y, double z){
    return 50*x-x*z-y;
}
double dz(double t, double x, double y, double z){
    return x*y-8/3.0*z;
}
int main(){
    double x0,y0,z0,t0,x,y,z,t,h;
    //t0=0,x0=0,y0=1,z0=0;
    FILE *fp=NULL;
    fp=fopen("res.txt","w");
    h=0.01;
    t=10;
    t0=0; x0=0;y0=1;z0=0;
//    printf("Enter the initial values of t, x, y, and z:\nt0 = ");
//    scanf("%lf",&t0);
//    printf("x0 = ");
//    scanf("%lf",&x0);
//    printf("y0 = ");
//    scanf("%lf",&y0);
//    printf("z0 = ");
//    scanf("%lf",&z0);
//    printf("Enter the step-width:\nh = ");
//    scanf("%lf",&h);
    double k1,k2,k3,k4,m1,m2,m3,m4,n1,n2,n3,n4;
    //RK-4
    while(t0<=t){
        if(t0>1){
            fprintf(fp,"%lf\t%lf\t%lf\t%lf\n",t0,x0,y0,z0);
        }
        k1=h*dx(t0,x0,y0,z0);
        m1=h*dy(t0,x0,y0,z0);
        n1=h*dz(t0,x0,y0,z0);
        k2=h*dx(t0+h/2.0,x0+k1/2.0,y0+m1/2.0,z0+n1/2.0);
        m2=h*dy(t0+h/2.0,x0+k1/2.0,y0+m1/2.0,z0+n1/2.0);
        n2=h*dz(t0+h/2.0,x0+k1/2.0,y0+m1/2.0,z0+n1/2.0);
        k3=h*dx(t0+h/2.0,x0+k2/2.0,y0+m2/2.0,z0+n2/2.0);
        m3=h*dy(t0+h/2.0,x0+k2/2.0,y0+m2/2.0,z0+n2/2.0);
        n3=h*dz(t0+h/2.0,x0+k2/2.0,y0+m2/2.0,z0+n2/2.0);
        k4=h*dx(t0+x0,x0+k3,y0+m3,z0+n3);
        m4=h*dy(t0+x0,x0+k3,y0+m3,z0+n3);
        n4=h*dz(t0+x0,x0+k3,y0+m3,z0+n3);
         
        x=x0+1/6.0*(k1+2*k2+2*k3+k4);   
        y=y0+1/6.0*(m1+2*m2+2*m3+m4);
        z=z0+1/6.0*(n1+2*n2+2*n3+n4);
         
        x0=x;
        y0=y;
        z0=z;
        t0=t0+h;
    }
}
