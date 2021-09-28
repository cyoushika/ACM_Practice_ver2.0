#include<stdio.h>
// #define LOCAL

int main(){
  int h,u,d,f;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while(scanf("%d%d%d%d",&h,&u,&d,&f)==4){
    if(h==0&&u==0&&d==0&&f==0){
      break;
    }
    double dis = 0;
    int per = 0;
    int day=1;
    double move = 0;
    // printf("-------------------------------------\n");
    // printf("Day    Initial    Height    Slided\n");
    while(true){
      // printf("%d    %lf    ",day,(double)dis);
      move = u*(1.0-per/100.0);
      if(move<0){
        move=0;
      }
      dis+=move;
      // printf("%lf    ",dis);
      if(dis>h){
        // printf("\n");
        printf("success on day %d\n",day);
        break;
      }
      dis-=d;
      // printf("%lf    \n",dis);
      if(dis<0){
        printf("failure on day %d\n",day);
        break;
      }
      day++;
      per+=f;
    }
  }
  return 0;
}
