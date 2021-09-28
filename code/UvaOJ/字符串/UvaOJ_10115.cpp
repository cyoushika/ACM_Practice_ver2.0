#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define LOCAL

char buf[400];
char temp[400];
char rules[30][100];

int main(){
  int n;
  char c;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while(scanf("%d",&n)!=EOF&&n){
    getchar();
    while((c=getchar())!=EOF){
      printf("%c",c);
    }
    // memset(temp,'\0',sizeof(temp));
    // memset(buf,'\0',sizeof(buf));
    // for(int i=0;i<30;i++){
    //   memset(rules[i],'\0',sizeof(rules[i]));
    // }

    int count=0;

    for(int i=0;i<2*n;i++){
      while((c=getchar())!='\n'){
        rules[i][count++]=c;
      }
      count=0;
    }

    count=0;
    while((c=getchar())!='\n'){
      buf[count++]=c;
    }

    int b_len = strlen(buf);

    for(int i=0;i<2*n;i+=2){
      int len = strlen(rules[i]);

      count=0;
      int change = 0;

      for(int j=0;j<b_len;j++){
        int flag=1;
        for(int k=0;k<strlen(rules[i]);k++){
          if(j+k>=b_len||buf[j+k]!=rules[i][k]){
            flag=0;
            break;
          }
        }
        if(flag){
          int l;
          for(int k=0,l=0;k<i;k++,l++){
            temp[l]=buf[k];
          }
          for(int k=0;k<strlen(rules[i+1]);k++,l++){
            temp[l]=rules[i+1][k];
          }
          for(int k=i+strlen(rules[i]);k<=len;k++,l++){
            temp[l]=buf[k];
          }
          temp[l]='\0';
          len=strlen(temp);
          for(int k=0;k<=len;k++){
            buf[k]=temp[k];
          }
          change=1;
        }
        if(change){
          break;
        }
      }
      if(change){
        i-=2;
      }
    }
    printf("%s\n",buf);
  }
  return 0;
}
