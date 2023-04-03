#include<stdio.h>
#include<math.h>
 
double f4(double x){
    double t0,t1,sum,R;
    t0=1;
    sum=t0;
    int i;
    for(i=1;i<=10;i++){
        R=-(x*x)/((2.0*i+1.0)*2.0*i);
        t1=R*t0;
        sum=sum+t1;
        t0=t1;
    }
    return sum;
}
double dy(double x, double y, double z){
    return z;
}
double dz(double x, double y, double z){
    return -z-4*x*y+f4(x);
}
 
int main(){
    double x0,y0,z0,x,y,z,h;
    FILE *fp=NULL;
    fp=fopen("res.txt","w");
    printf("Enter the initial values of t, x, y, and z:\nx0 = ");
    scanf("%lf",&x0);
    printf("y0 = ");
    scanf("%lf",&y0);
    printf("z0 = ");
    scanf("%lf",&z0);
    printf("Enter the step-width:\nh = ");
    scanf("%lf",&h);
     
    x=10;
    double k1,k2,k3,k4,m1,m2,m3,m4;
    while(fabs(x-x0)>0.000000001){
        //fprintf(fp,"%lf\t%lf\n",x0,f4(x0));       
        fprintf(fp,"%lf\t%lf\t%lf\n",x0,y0,z0);
         
        k1=h*dy(x0,y0,z0);
        m1=h*dz(x0,y0,z0);
        k2=h*dy(x0+h/2.0,y0+k1/2.0,z0+m1/2.0);
        m2=h*dz(x0+h/2.0,y0+k1/2.0,z0+m1/2.0);      
        k3=h*dy(x0+h/2.0,y0+k2/2.0,z0+m2/2.0);
        m3=h*dz(x0+h/2.0,y0+k2/2.0,z0+m2/2.0);
        k4=h*dy(x0+h,y0+k3,z0+m3);
        m4=h*dz(x0+h,y0+k3,z0+m3);
         
        y=y0+1/6.0*(k1+2*k2+2*k3+k4);
        z=z0+1/6.0*(m1+2*m2+2*m3+m4);
                 
        y0=y;
        z0=z;
        x0=x0+h;
    }
 
}
