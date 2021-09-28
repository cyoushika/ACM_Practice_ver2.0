#include<stdio.h>
#include<string.h>
// #define LOCAL
#define MAXN 10240

int main(){
  char op;
  char buf[MAXN];
  long long y;
  int data[MAXN];
  int ans[MAXN];

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while(scanf("%s %c %lld",buf,&op,&y)==3){
    memset(data,0,sizeof(data));
    memset(ans,0,sizeof(ans));
    int len=strlen(buf);
    for(int i=0;i<len;i++){
      data[i]=buf[len-1-i]-'0';
    }
    long long d=0;
    for(int i=len-1;i>=0;i--){
      d=d*10+data[i];
      ans[i]=d/y;
      d%=y;
    }
    while(len>0&&ans[len-1]==0){
      len--;
    }
    if(len==0){
      len=1;
    }
    if(op=='/'){
      for(int i=len-1;i>=0;i--){
        printf("%d",ans[i]);
      }
      printf("\n");
    }
    else{
      printf("%lld\n",d);
    }
  }
  return 0;
}
