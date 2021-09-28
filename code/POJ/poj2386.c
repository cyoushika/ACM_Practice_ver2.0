//题目大意：有一块地图，有W有.，逐个遍历，求连成片的W的个数（每个方块都与周围的8个方向的方块相连）
//解答：深度搜索，每次找到一个W就算一片，然后开始遍历，把所有遍历到的方块都变成“.”或者写一个记录数组。

#include<stdio.h>
#define Max_N 101

int row[8] = {-1,-1,0,1,1,1,0,-1}; //行，顺时针，上，右上，右，右下，下，左下，左，左上
int column[8] = {0,1,1,1,0,-1,-1,-1}; //列，顺时针，上，右上，右，右下，下，左下，左，左上
char map[Max_N][Max_N];
int record[Max_N][Max_N];
int N,M;

void dfs(int r, int c){
  int pointer_r,pointer_c;
  int i;
  for(i=0;i<8;i++){
    pointer_r = r+row[i];
    pointer_c = c+column[i];
    if(pointer_r>=0 && pointer_r<N && pointer_c>=0 && pointer_c<M){
      if(record[pointer_r][pointer_c]!=1){
        record[pointer_r][pointer_c]=1;
        if(map[pointer_r][pointer_c]=='W'){
          dfs(pointer_r,pointer_c);
        }
      }
    }
  }
}

int solve(){
  int result = 0;
  int i,j;
  for(i=0;i<N;i++){
    for(j=0;j<M;j++){
      if(map[i][j]=='W'&&record[i][j]!=1){
        result++;
        record[i][j]=1;
        dfs(i,j);
      }
    }
  }
  return result;
}

int main(){
  scanf("%d%d",&N,&M);

  int i=0,j=0;
  char keeper[Max_N];

  for(i=0;i<N;i++){
    scanf("%s",keeper);
    for(j=0;j<M;j++){
      map[i][j]=keeper[j];
      record[i][j]=0;
    }
  }

  int re = solve();
  printf("%d",re);
  return 0;
}
