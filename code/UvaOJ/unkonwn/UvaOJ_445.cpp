#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXN 1000
// #define LOCAL

char buf[MAXN];

int main(){
  char c;
  int sum=0;
  int count=0;
  int pointer=0;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while((c=getchar())!=EOF){
    if(isdigit(c)){
      sum+=(c-'0');
    }
    else if(c=='\n'||c=='!'){
      printf("\n");
    }
    else{
      for(int i=0;i<sum;i++){
        if(c=='b'){
          printf(" ");
        }
        else{
          printf("%c",c);
        }
      }
      sum=0;
    }
  }
  return 0;
}
