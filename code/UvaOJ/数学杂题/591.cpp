#include<stdio.h>
// #define LOCAL

int main(){
  int n;
  int t=0;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while(scanf("%d",&n)!=EOF&&n){
    t++;
    printf("Set #%d\n",t);
    int h[110];
    int total=0;
    for(int i=0;i<n;i++){
      scanf("%d",&h[i]);
      total+=h[i];
    }
    int avg = total/n;
    int count=0;
    for(int i=0;i<n;i++){
      if(h[i]>avg){
        count+=(h[i]-avg);
      }
    }
    printf("The minimum number of moves is %d.\n\n",count);
  }
  return 0;
}
