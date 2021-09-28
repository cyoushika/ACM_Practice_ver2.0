#include<stdio.h>
#include<string.h>

int f(int n){
  if(n==0){
    return 1;
  }
  else{
    return n*f(n-1);
  }
}

int main(){
  printf("%d\n",f(3));
  return 0;
}
