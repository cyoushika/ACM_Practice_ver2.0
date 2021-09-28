#include<stdio.h>
#include<string.h>

int main(){
  int n;
  int arr[100];
  int max;
  int count;
  while(true){
    scanf("%d",&n);
    getchar();
    if(n==0){
      break;
    }
    char buf[100];
    max = -100;
    for(int i=0;i<n;i++){
      count=0;
      char c;
      while((c=getchar())!='\n'){
        if(c=='X'){
          count++;
        }
      }
      if(count>max){
        max=count;
      }
      arr[i]=count;
    }
    int sum = 0;
    for(int i=0;i<n;i++){
      sum+=(max-arr[i]);
    }
    printf("%d\n",sum);
  }
}
