#include<stdio.h>
#include<math.h>

const double eps = 1e-9;

double area(double x0, double y0, double x1, double y1, double x2, double y2){
  return x0*y1+x2*y0+x1*y2-x2*y1-x0*y2-x1*y0;
}

int main(){
  double x0,y0,x1,y1,x2,y2;
  while(scanf("%lf%lf%lf%lf%lf%lf",&x0,&y0,&x1,&y1,&x2,&y2)==6){
    int count = 0;
    double all = fabs(area(x0,y0,x1,y1,x2,y2));
    // printf("Real Area: %.2lf\n",all);
    for(int i=1;i<100;i++){
      for(int j=1;j<100;j++){
        double s1 = fabs(area(i,j,x1,y1,x2,y2));
        double s2 = fabs(area(x0,y0,i,j,x2,y2));
        double s3 = fabs(area(x0,y0,x1,y1,i,j));
        double all2 = s1+s2+s3;
        // printf("Area: %.2lf\n",all2);
        if(fabs(all-all2)<=eps){
          // printf("In the area!\n");
          count++;
        }
      }
    }
    printf("%d\n",count);
  }
  return 0;
}
