#include<stdio.h>
#include<math.h>

double average(int a,int b,int c){
  int x = a+b+c;
  return x/3.0;
}

double temperature(int f){
  double c = 5*(f-32)/9.0;
  return c;
}

double sum(int n){
  return (1+n)*n/2.0;
}

double distance(double x1, double y1,double x2, double y2){
  return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void odd(int n){
  if(n%2==0){
    printf("yes\n");
  }
  else{
    printf("no\n");
  }
}

double discount(int n){
  double sum = 95*n;
  if(sum>=300){
    sum = sum * 0.85;
  }
  return sum;
}

double my_abs(double ff){
  if(ff<0){
    return -1.0 * ff;
  }
  else{
    return ff;
  }
}

void triangle(int a, int b, int c){
  if((a+b)<c || (a+c)<b || (b+c)<a){
    printf("no\n");
  }
  else{
    int x = a;
    if(x>b) x = b;
    if(x>c) x = c;

    int y = a;
    if(y<b) y = b;
    if(y<c) y = c;

    int z = a+b+c-x-y;

    int temp = x*x+z*z;
    if(temp==(y*y)){
      printf("yes\n");
    }
    else{
      printf("no\n");
    }
  }
}

int main(){
  printf("%lf\n", average(1,2,3));
  printf("%lf\n", temperature(75));
  printf("%lf\n", sum(5));
  printf("%lf\n", distance(0,0,1,1));
  odd(7);
  printf("%lf\n", discount(10));
  printf("%lf\n", my_abs(-12.34));
  triangle(3,4,6);
  return 0;
}
