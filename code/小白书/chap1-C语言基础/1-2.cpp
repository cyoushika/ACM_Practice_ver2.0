#include<stdio.h>
#include<math.h>

// int main(){
//   int a,b;
//   scanf("%d%d",&a,&b);
//   printf("%d\n",a+b);
//   return 0;
// }

int main(){
  const double pi = 4*atan(1.0);
  double r,h,s1,s2,s;
  scanf("%lf%lf",&r,&h);
  s1=pi*r*r;
  s2=2*pi*r*h;
  s=s1*2+s2;
  printf("Area = %.3lf\n",s);
  return 0;
}
