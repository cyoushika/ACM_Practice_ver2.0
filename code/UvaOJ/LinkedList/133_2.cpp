#include<stdio.h>
#define MAXN 21
// #define LOCAL
using namespace std;

struct Applicant{
  int id;
  int del;
  Applicant *left, *right;
  Applicant(){}
  Applicant(int i){
    id=i;
    del=0;
    left=right=NULL;
  }

  Applicant* next_left(){
    Applicant* a=left;
    // printf("\nID:%d Del:%d\n",a->id,a->del);
    while(a->del==1){
      a = a->left;
      if(a->id == a->left->id){
        break;
      }
    }
    return a;
  }

  Applicant* next_right(){
    Applicant* a=right;
    // printf("\nID:%d Del:%d\n",a->id,a->del);
    while(a->del==1){
      a = a->right;
      if(a->id == a->right->id){
        break;
      }
    }
    return a;
  }
};

int main(){
  int n,k,m;
  int size;
  #ifdef LOCAL
    freopen("/Users/zhangzhihua/Desktop/project/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
    freopen("/Users/zhangzhihua/Desktop/project/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif
  for(;;){
    scanf("%d%d%d",&n,&k,&m);
    // printf("%d %d %d\n",n,k,m);
    if(n==0&&k==0&&m==0){
      break;
    }
    size=n;
    Applicant* current=NULL;
    Applicant *head,*tail;
    for(int i=1;i<=n;i++){
      Applicant* a = new Applicant(i);
      if(i==1){
        head=a;
      }
      else if(i==n){
        tail=a;
      }
      if(current){
        current->left = a;
        a->right = current;
      }
      current=a;
    }

    if(size>1){
      head->right=tail;
      tail->left=head;
      while(size>0){
        // printf("size:%d\n",size);
        for(int i=0;i<k-1;i++){
          head = head->left;
        }
        for(int i=0;i<m-1;i++){
          tail = tail->right;
        }
        head->del=1;
        head->left->right = head->right;
        head->right->left = head->left;
        printf("%3d",head->id);
        size--;

        if(tail->id!=head->id){
          printf("%3d",tail->id);
          size--;
          tail->del=1;
        }
        if(size>0){
          tail->left->right = tail->right;
          tail->right->left = tail->left;
          head = head->next_left();
          tail = tail->next_right();
          printf(",");
        }
      }
    }
    else{
      printf("  %d",head->id);
    }
    printf("\n");
  }
  return 0;
}
