#include<stdio.h>
#include<math.h>

// int main(){
//   int a,b,n;
//   double m;
//   for(a=1;a<=9;a++){
//     for(b=0;b<=9;b++){
//       n = a*1100+b*11;
//       m = sqrt(n);
//       if(floor(m+0.5)==m){
//         printf("%d\n",n);
//       }
//     }
//   }
//   return 0;
// }

int main(){
  int x,n,high,low;
  for(x=1;;x++){
    n=x*x;
    if(n>=1000&&n<=9999){
      high = n/100;
      low = n%100;
      if(high/10==high%10 && low/10==low%10){
        printf("%d\n",n);
      }
    }
    else if(n>9999){
      break;
    }
  }
}
