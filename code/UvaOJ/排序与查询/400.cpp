#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define M 62
#define MAX 105
// #define LOCAL

char s[MAX][M];
int len[MAX];

int cmp_string(const void* _a, const void* _b){
  char* a = (char*) _a;
  char* b = (char*) _b;
  return strcmp(a,b);
}

int main(){
  int n;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while(scanf("%d",&n)==1){
    getchar();
    int col;
    int row;
    int max=0;
    int mod;
    for(int i=0;i<n;i++){
      scanf("%s",s[i]);
    }
    qsort(s,n,sizeof(s[0]),cmp_string);
    for(int i=0;i<n;i++){
      len[i]=strlen(s[i]);
      if(len[i]>max){
        max=len[i];
      }
    }
    col=(60-max)/(max+2)+1;
    mod=n%col;
    if(mod==0){
      row=n/col;
    }
    else{
      row=n/col+1;
    }

    for(int i=0;i<60;i++){
      printf("-");
    }
    printf("\n");
    for(int i=0;i<row;i++){
      int k=i;
      for(int j=0;j<col;j++){
        int r=0;
        printf("%s",s[k]);
        if(j<col-1){
          for(r=0;r<max+2-len[k];r++){
            printf(" ");
          }
        }
        else{
          for(r=0;r<max-len[k];r++){
            printf(" ");
          }
        }
        k=k+row;
        if(k>=n){
          break;
        }
      }
      printf("\n");
    }
    memset(s,'\0',MAX);
    memset(len,0,MAX);
    max=0;
  }
  return 0;
}
