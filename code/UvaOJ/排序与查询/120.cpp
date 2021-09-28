#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXN 32
// #define LOCAL

int stack[MAXN];

void solve(int* a, int l, int r, int len);
void reverse(int* a, int l, int r);

int main(){
  char c;
  int count=0;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while((c=getchar())!=EOF){
    if(isdigit(c)){
      stack[count]=stack[count]*10+(c-'0');
      // model[count++]=(c-'0');
      printf("%c",c);
    }
    else if(c=='\n'){
      count++;
      printf("\n");
      if(count>1){
        solve(stack,0,count-1,count);
      }
      printf("0\n");
      count=0;
      memset(stack,0,sizeof(stack));
    }
    else{
      printf("%c",c);
      count++;
    }
  }
  return 0;
}

void solve(int* a, int l, int r, int len){
  // printf("Stack: ");
  // for(int i=0;i<len;i++){
  //   printf("%d ",a[i]);
  // }
  // printf("\n");

  if(r==0){
    return;
  }

  int max=0;
  int imax=0;
  for(int i=l;i<=r;i++){
    if(a[i]>max){
      max=a[i];
      imax=i;
    }
  }

  if(imax==r){
    solve(a,l,r-1,len);
  }
  else if(imax==l){
    printf("%d ",len-r);
    reverse(a,l,r);
    solve(a,l,r-1,len);
  }
  else{
    printf("%d ",len-imax);
    reverse(a,l,imax);
    solve(a,l,r,len);
  }
}

void reverse(int* a, int l, int r){
  int i=l,j=r;
  int temp;
  while(i<=j){
    temp=a[i];
    a[i++]=a[j];
    a[j--]=temp;
  }
}
