#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 1000
// #define LOCAL

int main(){
  int round;
  char goal[MAXN];
  char guess[MAXN];

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while(true){
    scanf("%d",&round);
    if(round==-1){
      break;
    }
    else{
      printf("Round %d\n",round);
      scanf("%s",goal);
      scanf("%s",guess);
      int len_goal = strlen(goal);
      int len_guess = strlen(guess);
      int chance = 7;
      int left = len_goal;
      int win=0;
      int lose=0;

      for(int i=0;i<len_guess;i++){
        int flag=1;
        for(int j=0;j<len_goal;j++){
          if(goal[j]==guess[i]){
            left--;
            goal[j]=' ';
            flag=0;
          }
        }
        if(flag==1){
          chance--;
        }
        if(chance==0){
          lose=1;
        }
        if(left==0){
          win=1;
        }
        if(lose||win){
          break;
        }
      }

      if(win) printf("You win.\n");
      else if(lose) printf("You lose.\n");
      else printf("You chickened out.\n");
    }
  }
  return 0;
}
