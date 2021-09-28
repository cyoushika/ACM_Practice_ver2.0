#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXN 52
#define MAXK 22

// #define LOCAL

char map[MAXN][MAXN];
char word[MAXK][MAXN];

int n,m;
int k;

//up up-right right down-right down down-left left up-left

const int dx[] = {0,1,1,1,0,-1,-1,-1};
const int dy[] = {-1,-1,0,1,1,1,0,-1};

int walk(int dir,int x,int y,int cur, char wd[], int num){
  if(cur==num){
    return 1;
  }
  if(x<0||x>=n) return 0;
  if(y<0||y>=m) return 0;
  if(tolower(wd[cur])==map[y][x]){
    return walk(dir,x+dx[dir],y+dy[dir],cur+1,wd,num);
  }
  else{
    return 0;
  }
}

void solve(int idx){
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      for(int d=0;d<8;d++){
        if(walk(d,j,i,0,word[idx],strlen(word[idx]))){
          printf("%d %d\n",i+1,j+1);
          return ;
        }
      }
    }
  }
}

int main(){
  int t;
  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif
  scanf("%d",&t);
  while(t--){
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++){
      scanf("%s",map[i]);
      for(int j=0;j<n;j++){
        map[i][j]=tolower(map[i][j]);
      }
    }
    scanf("%d",&k);

    for(int i=0;i<k;i++){
      scanf("%s",word[i]);
    }

    for(int i=0;i<k;i++){
      solve(i);
    }

    if(t){
      printf("\n");
    }
  }
  return 0;
}
