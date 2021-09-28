#include<stdio.h>
#include<math.h>

double n,p;

int main(){
  while(scanf("%lf%lf",&n,&p)!=EOF){
    printf("%d\n",(int)(pow(p,1/n)+0.5));
  }
  return 0;
}
