#include<stdio.h>
#include<math.h>
// #define LOCAL

int main(){
  int t;
  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif
  scanf("%d",&t);
  int a,b;
  while(t--){
    scanf("%d%d",&a,&b);
    int dis=b-a;
    int n = (int) sqrt(dis);
    if(n*n==dis&&n!=0){
      printf("%d\n",2*n-1);
    }
    else if(dis<=n*(n+1)){
      printf("%d\n",2*n);
    }
    else{
      printf("%d\n",2*n+1);
    }
  }
  return 0;
}
