#include<stdio.h>
#include<string.h>
// #define LOCAL

int DNA[10];
int dish[42];
int temp[42];

int main(){
  int n;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  scanf("%d\n",&n);

  while(n>0){
    for(int i=0;i<10;i++){
      scanf("%d",&DNA[i]);
      // printf("Got %d\n",DNA[i]);
    }

    memset(dish,0,sizeof(dish));
    memset(temp,0,sizeof(temp));

    temp[20]=1;
    dish[20]=1;
    for(int i=0;i<50;i++){
      for(int j=1;j<=40;j++){
        if(dish[j]==0){
          printf(" ");
        }
        else if(dish[j]==1){
          printf(".");
        }
        else if(dish[j]==2){
          printf("x");
        }
        else if(dish[j]==3){
          printf("W");
        }
      }
      printf("\n");
      for(int j=1;j<=40;j++){
        temp[j]=dish[j-1]+dish[j]+dish[j+1];
      }
      for(int j=1;j<=40;j++){
        dish[j]=DNA[temp[j]];
      }
    }
    if(n-1>0){
      printf("\n");
    }
    n--;
  }
}
