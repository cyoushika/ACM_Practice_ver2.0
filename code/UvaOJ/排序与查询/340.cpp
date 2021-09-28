#include<stdio.h>
#include<string.h>

#define MAXN 100000
// #define LOCAL

int n;
int code[MAXN]={0};
int guess[MAXN]={0};
int visited[MAXN]={0};

int main(){
  int count=0;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while(scanf("%d",&n)==1&&n){
    memset(code,0,sizeof(code));
    for(int i=0;i<n;i++){
      scanf("%d",&code[i]);
    }
    printf("Game %d:\n",++count);
    while(1){
      for(int i=0;i<n;i++){
        scanf("%d",&guess[i]);
      }
      if(guess[0]==0){
        break;
      }
      int strong=0;
      int weak=0;
      for(int i=0;i<n;i++){
        if(code[i]==guess[i]){
          strong++;
          visited[i]=2;
        }
      }
      for(int i=0;i<n;i++){
        if(visited[i]!=2){
          for(int j=0;j<n;j++){
            if(visited[j]==0&&code[i]==guess[j]){
              weak++;
              visited[j]=1;
              break;
            }
          }
        }
      }
      printf("    (%d,%d)\n", strong, weak);
      memset(guess,0,sizeof(guess));
      memset(visited,0,sizeof(visited));
    }
  }
  return 0;
}
