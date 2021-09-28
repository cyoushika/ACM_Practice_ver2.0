#include<stdio.h>

int main(){
  int t;
  int m;
  scanf("%d",&t);
  while(t>0){
    scanf("%d",&m);
    int a,b,c;
    int sum = 0;
    for(int i=0;i<m;i++){
      scanf("%d%d%d",&a,&b,&c);
      sum+=a*c;
    }
    printf("%d\n",sum);
    t--;
  }
}
