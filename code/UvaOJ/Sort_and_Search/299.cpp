#include<stdio.h>
#include<string.h>
// #define LOCAL

int trains[55]={0};

int mysort(int* a, int l, int r){
  int count=0;
  for(int i=r;i>=0;i--){
    for(int j=i-1;j>=0;j--){
      if(a[j]>a[i]){
        count++;
      }
    }
  }
  return count;
}

int main(){
  int t;
  int n;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  scanf("%d",&t);
  int count=0;
  while(t--){
    scanf("%d",&n);
    memset(trains,0,sizeof(trains));
    for(int i=0;i<n;i++){
      scanf("%d",&trains[i]);
    }
    count=mysort(trains,0,n-1);
    // for(int i=0;i<20;i++){
    //   printf("%d ",trains[i]);
    // }
    // printf("\n");
    printf("Optimal train swapping takes %d swaps.\n",count);
  }
  return 0;
}
