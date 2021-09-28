#include<stdio.h>

int main(){
  int n;
  while(scanf("%d",&n)==1){
    int V = n;
    int E = n;
    int temp_v = 0;
    int temp_e = 0;
    for(int i=0;i<=n-2;i++){
      temp_v+=i*(n-2-i);
      temp_e+=i*(n-2-i)+1;
    }
    V+=n*temp_v/4;
    E+=n*temp_e/2;
    printf("%d\n",E-V+1);
  }
  return 0;
}
