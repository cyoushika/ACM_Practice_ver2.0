#include<stdio.h>
#include<string.h>
#define MAXN 200
// #define LOCAL

char buf[MAXN];
int result[MAXN];

int main(){
  memset(result,0,sizeof(result));
  memset(buf,'\0',sizeof(buf));

  int count=0;
  int rlen=0;
  int charge=0;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while(true){
    scanf("%s",buf);
    if(strcmp(buf,"0")==0){
      int len=199;
      while(result[len]==0&&len>=0){
        len--;
      }
      for(int i=len;i>=0;i--){
        printf("%d",result[i]);
      }
      if(len==-1){
        printf("0");
      }
      printf("\n");
      break;
    }
    else{
      int len = strlen(buf);
      int i,j;
      for(i=len-1,j=0;i>=0;i--,j++){
        result[j]+=(buf[i]-'0');
      }
      int count=199;
      while(result[count]==0&&count>=0){
        count--;
      }
      if(count>=0){
        for(j=0;j<=count;j++){
          result[j+1]+=result[j]/10;
          result[j]%=10;
        }
      }
      // for(i=len-1,j=0;i>=0;i--,j++){
      //   result[j]=result[j]+(buf[i]-'0')+charge;
      //   charge=0;
      //   if(result[j]>=10){
      //     charge=1;
      //     result[j]=result[j]%10;
      //   }
      // }
      // while(charge==1){
      //   result[j]=result[j]+charge;
      //   charge=0;
      //   if(result[j]>=10){
      //     charge=1;
      //     result[j]=result[j]%10;
      //   }
      //   j++;
      // }
    }
  }
  return 0;
}
