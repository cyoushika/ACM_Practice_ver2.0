#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
  int n;
  while(scanf("%d",&n)==1&&n){
    int level = floor(sqrt(double(n-1)))+1;
    int middle = level*level-(level-1);
    if(level%2==1){
      if(n<middle){
        printf("%d %d\n",level,level+n-middle);
      }
      else{
        printf("%d %d\n",level-n+middle,level);
      }
    }
    else{
      if(n<middle){
        printf("%d %d\n",level+n-middle,level);
      }
      else{
        printf("%d %d\n",level,level-n+middle);
      }
    }
  }
  return 0;
}
