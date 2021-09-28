//题目大意：有个人在一个NxM的地图里上下左右移动，但是他只能走“.”的格子，不能走"#"个格子，初始位置是”@”，问他最多能走多少格
//要点：这个题里是可以来回走的（虽然不计数字），这就是说，这道题的答案其实是求从“@”开始的最大连通的"."数量，且@也算作1格。
//用DFS从@出发，遍历每个可以到达的格子，计数
//关于计数，我没有用全局变量来统计，如果用全局变量的话应该会方便一些。
//我这里采用的是迭代，每次DFS都有一个result，初始为0，如果周围有可以走的格子，就+1，并继续DFS搜索那个格子
//当没有格子可以走的时候，result=0，并开始return。每一层迭代的result都等于下一层所有迭代的result的和。
//比较繁琐，但是效果是一样的┑(￣Д ￣)┍
//另外，关于二维数组初始化的问题，我还没有想到除了双for循环清理以外的办法..
//不过这道题不需要清理，每个地图的界限都很明确，每次也都会重新写入，不清理也没什么问题..
//试用了一下char**指针，效果不是很好，访问的位置总是不对..

#include<stdio.h>
#define Max_N 21
int C,R; //Column, Row
int row[4] = {-1,0,1,0}; //行，顺时针，上，右，下，左
int column[4] = {0,1,0,-1};//列，顺时针，上，右，下，左
char map[Max_N][Max_N];

int dfs(int r,int c){
  //printf("we are here\n");
  int pointer_r,pointer_c;
  int i;
  int result = 0;
  for(i=0;i<4;i++){
    pointer_r = r+row[i];
    pointer_c = c+column[i];
    //printf("?:[%d,%d]\n",pointer_r,pointer_c);
    if(pointer_r>=0 && pointer_r<R && pointer_c>=0 && pointer_c<C){
      if(map[pointer_r][pointer_c]=='.'){
        //printf(".:[%d,%d]\n",pointer_r,pointer_c);
        result++;
        map[pointer_r][pointer_c]='#';
        result = result+dfs(pointer_r,pointer_c);
      }
    }
  }
  return result;
}

int main(){
  while(1){
    scanf("%d%d",&C,&R);
    if(C==0&&R==0){
      break;
    }
    else{
      int i,j;
      int x,y;//start_x,start_y

      for(i=0;i<R;i++){
        char keeper[Max_N];
        scanf("%s",keeper);
        for(j=0;j<C;j++){
          map[i][j]=keeper[j];
          if(keeper[j]=='@'){
            x=j;
            y=i;
          }
        }
      }
      //printf("x=%d,y=%d\n",x,y);
      int result = dfs(y,x)+1;
      printf("%d\n",result);
    }
  }
  return 0;
}
