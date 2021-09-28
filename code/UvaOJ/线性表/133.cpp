#include<stdio.h>
#include<string.h>
#define MAXN 21
// #define LOCAL
using namespace std;

int applicants[MAXN];

int pick(int position, int clock, int time, int n){
  while(time--){
    do{
      position = (position+clock+n-1)%n+1;
    }while(applicants[position]==0);
  }
  return position;
}

int main(){
  int n,k,m;
  int size;
  #ifdef LOCAL
    freopen("/Users/zhangzhihua/Desktop/project/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
    freopen("/Users/zhangzhihua/Desktop/project/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  for(;;){
    scanf("%d%d%d",&n,&k,&m);
    if(n==0&&k==0&&m==0){
      break;
    }
    int p1=n;
    int p2=1;
    size=n;
    memset(applicants,1,sizeof(applicants));
    while(size>0){
      p1 = pick(p1,1,k,n);
      p2 = pick(p2,-1,m,n);
      printf("%3d",p1);
      size--;
      if(p1!=p2){
        printf("%3d",p2);
        size--;
      }
      applicants[p1]=0;
      applicants[p2]=0;
      if(size>0){
        printf(",");
      }
    }
    printf("\n");
  }
  return 0;
}
