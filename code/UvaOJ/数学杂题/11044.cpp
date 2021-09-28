#include<stdio.h>
#include<math.h>
// #define LOCAL

int main(){
  int m,n;
  int t;
  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  scanf("%d",&t);
  while(t--){
    scanf("%d%d",&m,&n);
    int x=ceil((m-2.0)/3.0);
    int y=ceil((n-2.0)/3.0);
    printf("%d\n",x*y);
  }
}
