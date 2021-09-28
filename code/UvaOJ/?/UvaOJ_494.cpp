#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(){
  char c;
  int count=0;
  int flag=0;
  while((c=getchar())!=EOF){
    if(isalpha(c)){
      flag=1;
    }
    else if(c=='\n'){
      if(flag==1){
        count++;
      }
      printf("%d\n",count);
      count=0;
      flag=0;
    }
    else if(flag==1){
      count++;
      flag=0;
    }
  }
  return 0;
}
