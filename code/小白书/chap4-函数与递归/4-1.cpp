#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<assert.h>

// int f(int n){
//   int i,m=1;
//   for(i=1;i<=n;i++){
//     m*=i;
//   }
//   return m;
// }

// int c(int m,int n){
//   int p = m+1;
//   int q = 1;
//   int result = 1;
//   while(p<=n){
//     result*=p;
//     p+=1;
//     while(q<=n-m && result%q==0){
//       result/=q;
//       q+=1;
//     }
//   }
//   return result;
// }
//
// int main(){
//   int m,n;
//   scanf("%d%d",&m,&n);
//   printf("%d\n",c(m,n));
//   return 0;
// }

// int is_prime(int n){
//   for(int i=2;i*i<=n;i++){
//     //假设存在一个是x的因子，且不在2~sqrt(x)之间的数，
//     //那么必然存在一个在2~sqrt(x)之间的因子与之相乘得到x。
//     //否则，二者相乘必然大于x。比如100,若存在一个因子不在2~10之间
//     //那么必然有一个在2~10之间的因子与之相乘。否则两因子皆大于10的话，乘积也必然大于100.
//     if(n%i==0){
//       return 0;
//     }
//   }
//   return 1;
// }
//

int is_prime(int x){
  int i,m;
  assert(x>=0);
  if(x==1) return 0;
  m = floor(sqrt(x)+0.5);
  for(i=2;i<=m;i++){
    if(x%i==0){
      return 0;
    }
  }
  return 1;
}

int main(){
  int i,m;
  scanf("%d",&m);
  for(i=m-2;i>=3;i--){
    if(is_prime(i) && is_prime(i+2)){
      printf("%d %d\n",i,i+2);
      break;
    }
  }
  return 0;
}
