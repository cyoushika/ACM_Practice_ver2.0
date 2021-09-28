#include<stdio.h>
// #define LOCAL

int main(){
  int count=0;
  int t;
  int n;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  scanf("%d",&t);
  while(t--){
    count=0;
    scanf("%d",&n);
    int temp=0;
    if(n>0){
      while(temp<n){
        count++;
        temp+=count;
      }
      while((temp-n)%2!=0){
        count++;
        temp+=count;
      }
      printf("%d\n",count);
    }
    else if(n<0){
      while(temp>n){
        count++;
        temp-=count;
      }
      while((temp-n)%2!=0){
        count++;
        temp-=count;
      }
      printf("%d\n",count);
    }
    else{
      printf("3\n");
    }
    if(t>0){
      printf("\n");
    }
  }
  return 0;
}
