#include<stdio.h>
#include<math.h>
#include <unistd.h>
#include <limits.h>

#define LOCAL
#define INF 100000000
// int main(){
// #ifdef LOCAL
//   freopen("input.txt","r",stdin);
//   freopen("output.txt","w",stdout);
// #endif
//   printf(">>>>START<<<<\n");
//   int x,n=0,min=INF,max=-INF,s=0;
//   while(scanf("%d",&x)==1){
//     s+=x;
//     if(x<min) min=x;
//     if(x>max) max=x;
//     n++;
//     printf("x=%d, min=%d, max=%d\n",x,min,max);
//   }
//   printf("%d %d %.3lf\n",min,max,double(s/n));
//   return 0;
// }

int main(){
  // char cwd[PATH_MAX];
  //  if (getcwd(cwd, sizeof(cwd)) != NULL) {
  //      printf("Current working dir: %s\n", cwd);
  //  } else {
  //      perror("getcwd() error");
  //      return 1;
  //  }
  //  return 0;

  FILE *fin, *fout;
  fin = fopen("./Desktop/ACM_Practice/code/小白书/input.in","rb");
  fout = fopen("./Desktop/ACM_Practice/code/小白书/output.out","wb");
  int x,n=0,min=INF,max=-INF,s=0;
  if(fin==NULL){
    printf("File Not Exist!\n");
  }
  else{
    while(fscanf(fin,"%d",&x)==1){
      s+=x;
      if(x<min) min=x;
      if(x>max) max=x;
      n++;
      // printf("x=%d, min=%d, max=%d\n",x,min,max);
    }
    fprintf(fout, "%d %d %.3lf\n", min,max,(double)s/n);
  }
  fclose(fin);
  fclose(fout);
  return 0;
}
