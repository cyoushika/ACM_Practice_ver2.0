#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXN 110
// #define LOCAL

int main(){
  int t;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  scanf("%d",&t);
  t=t*2;
  getchar();
  char c;

  // char s1[MAXN];
  char s2[MAXN];
  char s3[MAXN];
  char s4[MAXN];
  char s5[MAXN];

  int count=0;

  while(t--){
    if(t%2==1){
      // memset(s1,'\0',sizeof(s1));
      memset(s2,'\0',sizeof(s2));
      memset(s3,'\0',sizeof(s3));
      memset(s4,'\0',sizeof(s4));
      memset(s5,'\0',sizeof(s5));
      while((c=getchar())!='<'){
        printf("%c",c);
      }
      count=0;
      while((c=getchar())!='>'){
        s2[count++]=c;
        printf("%c",c);
      }
      count=0;
      while((c=getchar())!='<'){
        s3[count++]=c;
        printf("%c",c);
      }
      count=0;
      while((c=getchar())!='>'){
        s4[count++]=c;
        printf("%c",c);
      }
      count=0;
      while((c=getchar())!='\n'){
        printf("%c",c);
        s5[count++]=c;
      }
      printf("\n");
    }
    else{
      while((c=getchar())!='.'){
        printf("%c",c);
      }
      getchar();
      getchar();
      for(int i=0;i<strlen(s4);i++){
        printf("%c",s4[i]);
      }
      for(int i=0;i<strlen(s3);i++){
        printf("%c",s3[i]);
      }
      for(int i=0;i<strlen(s2);i++){
        printf("%c",s2[i]);
      }
      for(int i=0;i<strlen(s5);i++){
        printf("%c",s5[i]);
      }
      while((c=getchar())!='\n'){
        printf("%c",c);
      }
      printf("\n");
    }
  }
  return 0;
}
