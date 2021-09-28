#include<stdio.h>
#include<math.h>

// int main(){
//   long long int n;
//   scanf("%lld",&n);
//   int counter = 0;
//   while(n!=1){
//     if(n%2==0){
//       n = n/2;
//       counter++;
//     }
//     else{
//       n = 3*n+1;
//       counter++;
//     }
//   }
//   printf("%d\n",counter);
//   return 0;
// }
int factorial(int n){
  if(n==1){
    return 1;
  }
  else{
    return n*factorial(n-1)%1000000;
  }
}

int main(){
  int n;
  int sum=0;
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    sum = (sum+factorial(i))%1000000;
  }
  printf("%d\n",sum);
}
