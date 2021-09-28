#include<stdio.h>
#include<ctype.h>
#include<string.h>
// #define LOCAL

int a[10010];
int b[10010];

int main(){
  int k;
  int temp;
  char c;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while(scanf("%d",&k)==1){
    getchar();
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    int len=0;
    int flag=1;
    while((c=getchar())!='\n'){
      if(c=='-'){
        flag=-1;
      }
      else if(isdigit(c)){
        a[len]=a[len]*10+(c-'0');
      }
      else if(c==' '){
        a[len]=a[len]*flag;
        // printf("a[%d]: %d\n", len, a[len]);
        flag=1;
        len++;
      }
    }
    a[len]=a[len]*flag;
    // printf("a[%d]: %d\n", len, a[len]);
    len++;
    if(len==1){
      printf("q(x):\nr = %d\n",a[0]);
    }
    else{
      b[0]=a[0];
      printf("q(x): %d",b[0]);
      for(int i=1;i<len;i++){
        b[i]=a[i]+k*b[i-1];
        if(i<len-1){
          printf(" %d",b[i]);
        }
        else{
          printf("\nr = %d\n",b[i]);
        }
      }
    }
    printf("\n");
  }
  return 0;
}
