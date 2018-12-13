//题目大意：一个通道里有编号1~10，顺序打乱的是个球，然后依次往下掉落，下面有两个收纳管和一个挡板
//通过操作挡板可以任意将球放到左边或者右边。如果要求每次放置球的时候，一定要放在
//比这个球编号小的球的上面，问能否完成收纳？
//解答：有两个思路，一个贪心，一个DFS，我用的是DFS，每次放一个球，然后遍历这样放以后的所有可能，
//只要找到一个解，就输出“YES”，并设立一个flag。如果到最后都没有找到完全收纳的办法，就NO。
//贪心的思路是，左边优先，左边放不下了再放右边，可以保证左边都是大号
#include<stdio.h>
#include<string.h>
int n;
int left[10];
int right[10];
int map[10];
int left_pointer;
int right_pointer;
int cnt;
int flag;

void dfs(int a){
  if(cnt==10&&flag==1){
    printf("YES\n");
    flag=0;
    return ;
  }
  else if(map[a]>left[left_pointer]){
    cnt++;
    left_pointer++;
    left[left_pointer]=map[a];
    dfs(a+1);
  }
  else if(map[a]>right[right_pointer]){
    cnt++;
    right_pointer++;
    right[right_pointer]=map[a];
    dfs(a+1);
  }
  else{
    return ;
  }
  return ;
}

int main(){
  scanf("%d",&n);
  int i;
  int j;
  for(i=0;i<n;i++){
    cnt = 0;
    flag = 1;
    left_pointer = 0;
    right_pointer = 0;

    for(j=0;j<10;j++){
      scanf("%d",&map[j]);
    }
    left[left_pointer]=map[0];
    cnt++;
    dfs(1);
    if(cnt!=10&&flag==1){
      printf("NO\n");
    }
  }
  return 0;
}
