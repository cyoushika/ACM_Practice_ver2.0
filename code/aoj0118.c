//题目大意：有个人临死之前留下了遗言，说自己把果园子按照苹果，kaki，橘子的区域分开种。现在遗产继承人希望按区域分配土地。
//每一块区域都只有一种果树，每棵树上下左右如果是种类相同的树，就视为同一区域。问现在果园子有几个区域？
//要点：没什么难度，上下左右移动，DFS遍历，把搜索过的地方用“@，*，#”以外的符号代替

#include<stdio.h>
#define Max_N 101
int N,M;
int map[Max_N][Max_N];
int result = 0;

int row[4] = {-1,1,0,0};//上下左右
int column[4] = {0,0,-1,1};//上下左右

void dfs(int r,int c,char target){
  int i;
  int pointer_r,pointer_c;
  for(i=0;i<4;i++){
    pointer_r = r+row[i];
    pointer_c = c+column[i];
    if(pointer_r>=0&&pointer_r<N&&pointer_c>=0&&pointer_c<M){
      if(map[pointer_r][pointer_c]-target==0){
        map[pointer_r][pointer_c]='.';
        dfs(pointer_r,pointer_c,target);
      }
    }
  }
}

int main(){
  while(1){
    scanf("%d%d",&N,&M);
    if(N==0&&M==0){
      break;
    }
    else{
      int i,j;
      result = 0;
      for(i=0;i<N;i++){
        char keeper[Max_N];
        scanf("%s",keeper);
        for(j=0;j<M;j++){
          map[i][j]=keeper[j];
        }
      }

      //printf("\n");
      for(i=0;i<N;i++){
        for(j=0;j<M;j++){
          //printf("%c",map[i][j]);
          if(map[i][j]!='.'){
            result++;
            char target = map[i][j];
            map[i][j]='.';
            //printf("we are here\n");
            dfs(i,j,target);
          }
        }
        //printf("\n");
      }
    }
    printf("%d\n",result);
  }
  return 0;
}
