#include<stdio.h>
#include<string.h>
const int MAXD = 20;
int s[1<<MAXD]; //Max Node = 2^MAXD - 1
int main(){
  int D,I;
  while(scanf("%d%d",&D,&I)==2){
    int k=1;
    for(int i=0;i<D-1;i++){
      if(I%2){
        printf("D=%d,I=%d,k=%d,\n",i,I,k);
        k=k*2;
        I=(I+1)/2;
      }
      else{
        printf("D=%d,I=%d,k=%d,\n",i,I,k);
        k=k*2+1;
        I/=2;
      }
    }
    printf("%d\n",k);
  }
  // while(scanf("%d%d",&D,&I)==2){
  //   memset(s,0,sizeof(s));
  //   int k,n = (1<<D)-1;
  //   for(int i=0;i<I;i++){
  //     k=1;
  //     for(;;){
  //       s[k]=!s[k];
  //       k = s[k]?k*2:k*2+1;
  //       if(k>n){
  //         break;
  //       }
  //     }
  //   }
  //   printf("%d\n",k/2);
  // }
  return 0;
}
