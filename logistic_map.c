#include<stdio.h>
#include<math.h>
double xn1(double alpha, double xn){
    return alpha*xn*(1-xn);
}
int main(){
    FILE *fp=NULL;
    fp=fopen("res.txt","w");
    double alpha,x=0.1,x1;
    //for(x=0.1;x<=1;x=x+0.1){
        if(x!=0&&x!=0.5&&x!=1){
            for(alpha=0;alpha<=4;alpha=alpha+0.05){  
                int i=1;    
                x1=xn1(alpha,x);        
                do{
                    if(i>=10000){
                        fprintf(fp,"%lf\t%lf\n",xn1(alpha,x1),alpha);
                    }                   
                    x1=xn1(alpha,x1);
                    i++;
                }while(i<=10100);    
            }
        }
    //}
}
