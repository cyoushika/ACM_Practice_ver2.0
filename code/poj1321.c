//题目大意：有个nxn的棋盘，上面有#和.，#代表盘面，.代表空白。棋子只能在盘面上放置，且每个棋子完全相同。
//问，现在要放k个棋子到棋盘上，且要保证每颗棋子的行，列都没有另一颗棋子，有多少种放法
//题目要点：
//1. 遍历从第一行第一列，从左向右开始，每行遍历完毕后换行。
//为了避免重复解，摆放一颗棋子后，总是向下一行遍历，因此本题目不需要记录行的状态
//2. 遍历期间需要判断当前列是否可放，所以需要记录列的状态
//3. 在遍历结束之后，需要返回之前的状态（相当于没有放那颗棋子）

#include<stdio.h>
#include<string.h>

char map[10][10];
int n,k;
int column[10]={0};
int ans;
int cnt;

void dfs(int r){
  int i;
  if(cnt==k){
    ans++;
    return ;
  }
  else{
    if(r>=n){
      return ;
    }
    else{
      for(i=0;i<n;i++){
        if(map[r][i]=='#'&&column[i]!=1){
          column[i]=1;//放下棋子
          cnt++;
          dfs(r+1);//开始遍历放下这个棋子以后的情况
          column[i]=0;//遍历完毕后恢复原样，即没有放这个棋子的时候的状态
          cnt--;
        }
      }
      dfs(r+1);//上一行都遍历完毕，开始遍历下一行
    }
  }
}

int main(){
  int i;
  while(1){
    scanf("%d%d",&n,&k);
    if(n==-1&&k==-1){
      break;
    }
    else{
      memset(column,0,sizeof(column));
      for(i=0;i<n;i++){
        scanf("%s",map[i]);
      }
      cnt=ans=0;
      dfs(0);
      printf("%d\n",ans);
    }
  }
  return 0;
}
