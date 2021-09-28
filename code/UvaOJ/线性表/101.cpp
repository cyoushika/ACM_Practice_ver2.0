#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// #define LOCAL
#define MAXN 25
using namespace std;

struct Block{
  int value;
  int stack;
  Block *above, *below;
  Block(){};
  Block(int v){
    value=v;
    stack=v;
    above=below=NULL;
  }

  void returning(){
    if(above){
      Block* up = above;
      while(up){
        up->stack = up->value;
        up->below->above=NULL;
        up->below=NULL;
        up = up->above;
      }
    }
    return;
  }

  void stack_sync(){
    if(above){
      Block* up = above;
      while(up){
        up->stack = stack;
        up = up->above;
      }
    }
    return;
  }
};

void move_onto(Block* from, Block* target){
  if(from->below){
    from->below->above=NULL;
    from->below=NULL;
  }
  from->returning();
  target->returning();
  from->below=target;
  target->above=from;
  from->stack = target->stack;
}

void move_over(Block* from, Block* target){
  if(from->below){
    from->below->above=NULL;
    from->below=NULL;
  }
  from->returning();
  Block* tail = target;
  while(tail->above){
    tail = tail->above;
  }
  tail->above = from;
  from->below = tail;
  from->stack = target->stack;
}

void pile_onto(Block* from, Block* target){
  if(from->below){
    from->below->above=NULL;
    from->below=NULL;
  }
  target->returning();
  from->below = target;
  target->above = from;
  from->stack = target->stack;
  from->stack_sync();
}

void pile_over(Block* from, Block* target){
  if(from->below){
    from->below->above=NULL;
    from->below=NULL;
  }
  Block* tail = target;
  while(tail->above){
    tail = tail->above;
  }
  tail->above = from;
  from->below = tail;
  from->stack = target->stack;
  from->stack_sync();
}

int main(){
  int n;
  #ifdef LOCAL
    freopen("/Users/zhangzhihua/Desktop/project/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
    freopen("/Users/zhangzhihua/Desktop/project/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif
  scanf("%d",&n);
  Block* blocks[MAXN];
  for(int i=0;i<n;i++){
    Block* b = new Block(i);
    blocks[i]=b;
  }

  char action[5];
  char relation[5];
  int from,to;

  for(;;){
    scanf("%s",action);
    if(!strcmp(action,"quit")){
      break;
    }
    scanf("%d%s%d",&from,relation,&to);
    if(from!=to && blocks[from]->stack != blocks[to]->stack){
      if(!strcmp(action,"move")){
        if(!strcmp(relation,"onto")){
          // printf("Try to move %d onto %d\n",from,to);
          move_onto(blocks[from],blocks[to]);
        }
        else{
          // printf("Try to move %d over %d\n",from,to);
          move_over(blocks[from],blocks[to]);
        }
      }
      else{
        if(!strcmp(relation,"onto")){
          // printf("Try to pile %d onto %d\n",from,to);
          pile_onto(blocks[from],blocks[to]);
        }
        else{
          // printf("Try to pile %d over %d\n",from,to);
          pile_over(blocks[from],blocks[to]);
        }
      }
    }
    // for(int i=0;i<n;i++){
    //   printf("%d:",i);
    //   if(blocks[i]->below==NULL){
    //     Block* up = blocks[i];
    //     while(up){
    //       printf(" %d",up->value);
    //       up = up->above;
    //     }
    //   }
    //   printf("\n");
    // }
    // printf("--------------------------------\n");
  }

  for(int i=0;i<n;i++){
    printf("%d:",i);
    if(blocks[i]->below==NULL){
      Block* up = blocks[i];
      while(up){
        printf(" %d",up->value);
        up = up->above;
      }
    }
    printf("\n");
  }
  return 0;
}
