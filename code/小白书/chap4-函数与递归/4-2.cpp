#include<stdio.h>
#include<string.h>

void swap(int* a, int* b){
  int t=*a;
  *a = *b;
  *b = t;
}

int main(){
  int a=3, b=4;
  swap(&a,&b);
  printf("%d %d\n",a,b);
  return 0;
}
