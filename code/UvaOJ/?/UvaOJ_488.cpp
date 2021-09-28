#include<stdio.h>
#include<string.h>
// #define LOCAL

int main(){
  int n;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  scanf("%d",&n);
  int h,f;
  for(int t=0;t<n;t++){
    // getchar();
    // getchar();
    scanf("%d",&h);
    scanf("%d",&f);
    for(int p=0;p<f;p++){
      for(int i=1;i<=h;i++){
        for(int j=1;j<=i;j++){
          printf("%d",i);
        }
        printf("\n");
      }
      for(int i=h-1;i>=1;i--){
        for(int j=1;j<=i;j++){
          printf("%d",i);
        }
        printf("\n");
      }
      if(p<f-1){
        printf("\n");
      }
    }
    if(t<n-1){
      printf("\n");
    }
  }
  return 0;
}
