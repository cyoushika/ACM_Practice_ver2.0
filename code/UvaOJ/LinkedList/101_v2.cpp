#include<stdio.h>
#include<string.h>
// #define LOCAL
using namespace std;

struct Block{
  int stack;
  int origin;
  Block *above, *below;

  Block(){};

  Block(int v){
    origin = v;
    stack = v;
    above=below=NULL;
  }

  void returning(){
    if(above){
      Block* up = above;
      while(up){
        up->stack = up->origin;
        up->below->above = NULL;
        up->below = NULL;
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

void move_onto(Block* from, Block* to){
  if(from->below){
    from->below->above=NULL;
    from->below = NULL;
  }
  from->returning();
  to->returning();
  to->above = from;
  from->below = to;
  from->stack = to->stack;
}

void move_over(Block* from, Block* to){
  if(from->below){
    from->below->above=NULL;
    from->below = NULL;
  }
  from->returning();
  Block* up=to;
  while(up->above){
    up = up->above;
  }
  up->above = from;
  from->below = up;
  from->stack = up->stack;
}

void pile_onto(Block* from, Block* to){
  if(from->below){
    from->below->above=NULL;
    from->below = NULL;
  }
  to->returning();
  from->below = to;
  to->above = from;
  from->stack = to->stack;
  from->stack_sync();
}

void pile_over(Block* from, Block* to){
  if(from->below){
    from->below->above=NULL;
    from->below = NULL;
  }
  Block* up = to;
  while(up->above){
    up = up->above;
  }
  up->above = from;
  from->below = up;
  from->stack = up->stack;
  from->stack_sync();
}

int main(){
  int n;
  #ifdef LOCAL
    freopen("/Users/zhihua-z/Desktop/project/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
    freopen("/Users/zhihua-z/Desktop/project/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif
  scanf("%d",&n);
  char action[5],direction[5];
  int from,to;
  Block* blocks[25];
  for(int i=0;i<n;i++){
    Block* b = new Block(i);
    blocks[i] = b;
  }
  while(true){
    scanf("%s",action);
    if(!strcmp(action,"quit")){
      break;
    }
    scanf("%d%s%d",&from,direction,&to);
    if(from!=to&&blocks[from]->stack!=blocks[to]->stack){
      if(!strcmp(action,"move")){
        if(!strcmp(direction,"onto")){
          move_onto(blocks[from],blocks[to]);
        }
        else{
          move_over(blocks[from],blocks[to]);
        }
      }
      else{
        if(!strcmp(direction,"onto")){
          pile_onto(blocks[from],blocks[to]);
        }
        else{
          pile_over(blocks[from],blocks[to]);
        }
      }
    }
  }
  for(int i=0;i<n;i++){
    printf("%d:",i);
    if(!blocks[i]->below){
      Block* up = blocks[i];
      while(up){
        printf(" %d",up->origin);
        up = up->above;
      }
    }
    printf("\n");
  }
  return 0;
}
