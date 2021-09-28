#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 1000

int a[MAX+10];
//
// int main(){
//   int n,k;
//   scanf("%d%d",&n,&k);
//   memset(a,0,sizeof(a));
//   for(int i=1;i<=k;i++){
//     for(int j=i;j<=n;j+=i){
//       if(a[j]==0){
//         a[j]=1;
//       }
//       else{
//         a[j]=0;
//       }
//     }
//   }
//   int flag=0;
//   for(int i=1;i<=n;i++){
//     if(a[i]==1){
//       if(flag==0){
//         printf("%d",i);
//         flag=1;
//       }
//       else{
//         printf(" %d",i);
//       }
//     }
//   }
//   printf("\n");
//   return 0;
// }

int b[11][11];

int main(){
  int n,x,y,tot=0;
  scanf("%d",&n);
  memset(b,0,sizeof(b));
  x = 0;
  y = n-1;
  b[x][y] = 1;
  int counter = 1;
  while(counter<n*n){
    while(x+1<n && b[x+1][y]==0){
      counter++;
      b[x+1][y] = counter;
      x++;
      printf("%d\n",counter);
    }
    while(y-1>=0 && b[x][y-1]==0){
      counter++;
      b[x][y-1]=counter;
      y--;
      printf("%d\n",counter);
    }
    while(x-1>=0 && b[x-1][y]==0){
      counter++;
      b[x-1][y]=counter;
      x--;
      printf("%d\n",counter);
    }
    while(y+1<n && b[x][y+1]==0){
      counter++;
      b[x][y+1]=counter;
      y++;
      printf("%d\n",counter);
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      printf("%3d ",b[i][j]);
    }
    printf("\n");
  }
  return 0;
}
