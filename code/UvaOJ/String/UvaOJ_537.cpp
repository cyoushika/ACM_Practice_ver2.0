#include<stdio.h>
#include<string.h>
#include<ctype.h>
// #define LOCAL
#define MAXN 1000000

double P,U,I;

int main(){
  int n;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  scanf("%d",&n);
  char c;
  getchar();
  for(int i=1;i<=n;i++){
    int flag_u=0;
    int flag_p=0;
    int flag_i=0;
    int flag_d=0;
    P=U=I=0;

    double prefix=1.0;
    double dot=1.0;
    while((c=getchar())!='\n'){
      if(c=='U'&&(c=getchar())=='='){
        flag_u=1;
        flag_d=0;
        prefix=1.0;
        dot=1.0;
        while((c=getchar())!='V'){
          if(c=='m'){
            prefix=0.001;
          }
          else if(c=='k'){
            prefix=1000.0;
          }
          else if(c=='M'){
            prefix=1000000.0;
          }
          else if(c=='.'){
            flag_d=1;
          }
          else if(isdigit(c)){
            U=U*10+double(c-'0');
            if(flag_d){
              dot=dot*10.0;
            }
          }
        }
        U=U/dot*prefix;
        // printf("U=%.2lf\n",U);
      }
      else if(c=='I'&&(c=getchar())=='='){
        flag_i=1;
        flag_d=0;
        prefix=1.0;
        dot=1.0;
        while((c=getchar())!='A'){
          if(c=='m'){
            prefix=0.001;
          }
          else if(c=='k'){
            prefix=1000.0;
          }
          else if(c=='M'){
            prefix=1000000.0;
          }
          else if(c=='.'){
            flag_d=1;
          }
          else if(isdigit(c)){
            I=I*10+double(c-'0');
            if(flag_d){
              dot=dot*10.0;
            }
          }
        }
        I=I/dot*prefix;
        // printf("I=%.2lf\n",I);
      }
      else if(c=='P'&&(c=getchar())=='='){
        flag_p=1;
        flag_d=0;
        prefix=1.0;
        dot=1.0;
        while((c=getchar())!='W'){
          if(c=='m'){
            prefix=0.001;
          }
          else if(c=='k'){
            prefix=1000.0;
          }
          else if(c=='M'){
            prefix=1000000.0;
          }
          else if(c=='.'){
            flag_d=1;
          }
          else if(isdigit(c)){
            P=P*10+double(c-'0');
            if(flag_d){
              dot=dot*10.0;
            }
          }
        }
        P=P/dot*prefix;
        // printf("P=%.2lf\n",P);
      }
    }
    if(flag_u){
      if(flag_i){
        printf("Problem #%d\n",i);
        printf("P=%.2lfW\n",U*I);
      }
      else{
        printf("Problem #%d\n",i);
        printf("I=%.2lfA\n",P/U);
      }
    }
    else{
      printf("Problem #%d\n",i);
      printf("U=%.2lfV\n",P/I);
    }

    printf("\n");

  }
  return 0;
}
