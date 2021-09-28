#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
// #define LOCAL
#define MAXN 53

using namespace std;

struct Card{
  char rank;
  char suit;
  Card(){}
  Card(char r, char s){
    rank=r;
    suit=s;
  }
  int isSame(Card c){
    return rank==c.rank||suit==c.suit;
  }
};

struct Pile{
  Card cards[MAXN];
  int top;
  Pile *left,*right;
  Pile(){
    top=0;
    left=right=NULL;
  }
  int isSame(Pile* p){
    return p->cards[p->top-1].isSame(cards[top-1]);
  }
  void add(Card c){
    cards[top++]=c;
  }

  Card pop(){
    return cards[--top];
  }
  int isEmpty(){
    return top==0;
  }
};

struct List{
  int size;
  Pile *head, *tail;
  List(){
    size=0;
    head=tail=NULL;
  }

  int read(){
    size=52;
    head=tail=NULL;
    char buf[3];
    Pile* tp=NULL;
    for(int i=0;i<52;i++){
      scanf("%s",buf);
      if(buf[0]=='#'){
        return 0;
      }
      Pile* p = new Pile();
      p->add(Card(buf[0],buf[1]));
      if(i==0){
        head=p;
      }
      else if(i==51){
        tail=p;
      }
      if(tp){
        tp->right = p;
        p->left=tp;
      }
      tp = p;
    }
    return 1;
  }

  void del(Pile* p){
    if(p->left){
      p->left->right = p->right;
    }
    if(p->right){
      p->right->left = p->left;
    }
    size--;
    delete p;
  }

  void move(Pile* from, Pile* to){
    to->add(from->pop());
    if(from->isEmpty()){
      del(from);
    }
  }

  int solve(){
    Pile* tp = head->right;
    for(;tp;tp=tp->right){
      if(tp->left&&tp->left->left&&tp->left->left->left&&tp->left->left->left->isSame(tp)){
        move(tp,tp->left->left->left);
        return 1;
      }
      if(tp->left&&tp->left->isSame(tp)){
        move(tp,tp->left);
        return 1;
      }
    }
    return 0;
  }

  void print(){
    printf("%d pile",size);
    printf(size>1?"s":"");
    printf(" remaining:");
    for(Pile *p=head;p;p=p->right){
      printf(" %d",p->top);
    }
    putchar('\n');
  }
}row;

int main(){
  #ifdef LOCAL
    freopen("/Users/zhangzhihua/Desktop/project/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
    freopen("/Users/zhangzhihua/Desktop/project/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while(row.read()){
    while(row.solve()){}
    row.print();
  }
}
