#include<stdio.h>
#include<string.h>

using namespace std;

struct Card{
  char suit;
  char rank;
  Card(){};
  Card(char s,char r){
    suit = s;
    rank = r;
  }

  bool isSame(Card c){
    return c.rank==rank||c.suit==suit;
  }
};

struct Pile{
  Card cards[60];
  int top;
  Pile *left, *right;
  Pile(){
    top=0;
    left=right=NULL;
  }

  void add_card(Card c){
    cards[top++]=c;
  }

  Card remove_card(Card c){
    return cards[--top];
  }

  bool isEmpty(){
    return top==0;
  }

  int isSame(Pile* p){
    return p->cards[p->top-1].isSame(cards[top-1]);
  }
};
