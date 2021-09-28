#include<stdio.h>
#include<math.h>

// int main(){
//   int n;
//   scanf("%d",&n);
//   int a,b,c;
//   int m;
//   a=n%10;
//   b=(n/10)%10;
//   c=n/100;
//   m = a*100+b*10+c;
//   printf("%03d\n",m);
//   return 0;
// }

// int main(){
//   int a,b,c;
//   scanf("%d%d",&a,&b);
//   c = a;
//   a = b;
//   b = c;
//   printf("%d %d\n",a,b);
//   return 0;
// }

int main(){
  int a,b;
  scanf("%d%d",&a,&b);
  a = a+b;
  b = a-b;
  a = a-b;
  printf("%d %d\n",a,b);
  return 0;
}
