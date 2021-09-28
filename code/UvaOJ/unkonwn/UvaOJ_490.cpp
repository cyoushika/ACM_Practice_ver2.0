#include<stdio.h>
#include<string.h>
#define MAXN 110

char map[MAXN][MAXN];
// char result[MAXN][MAXN];

int main(){
  char c;
  int row=0,col=0;
  int max = -100;

  for(int p=0;p<MAXN;p++){
    memset(map[p],'\0',sizeof(char));
    // memset(result[p],'\0',sizeof(char));
  }

  while((c=getchar())!=EOF){
    if(c=='\n'){
      if(col>max){
        max=col;
      }
      col=0;
      row++;
    }
    else{
      map[row][col++]=c;
    }
  }
  if(col!=0){
    if(col>max){
      max=col;
    }
    row++;
  }

  // printf("ROW: %d, MAX: %d\n",row,max);
  for(int i=0;i<max;i++){
    for(int j=row-1;j>=0;j--){
      if(map[j][i]=='\0'){
        printf(" ");
      }
      else{
        printf("%c",map[j][i]);
      }
    }
    printf("\n");
  }

  return 0;
}
