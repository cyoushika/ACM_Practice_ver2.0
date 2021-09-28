#include<stdio.h>
#include<string.h>
// #define LOCAL
#define MAXN 600

char a[MAXN],b[MAXN];
int c[MAXN],d[MAXN];
int result[MAXN];

int main(){
  int lena,lenb;
  int i,j;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while(scanf("%s%s",a,b)==2){
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    memset(result,0,sizeof(result));

    lena=strlen(a);
    lenb=strlen(b);
    
    for(i=0;i<lena;i++){
      c[i]=(a[lena-1-i]-'0');
    }
    for(i=0;i<lenb;i++){
      d[i]=(b[lenb-1-i]-'0');
    }
    for(i=0;i<lena;i++){
      for(j=0;j<lenb;j++){
        result[i+j]+=c[i]*d[j];
      }
    }
    for(i=0;i<lena+lenb;i++){
      result[i+1]+=result[i]/10;
      result[i]=result[i]%10;
    }
    i=lena+lenb-1;
    while(result[i]==0&&i>=0){
      i--;
    }
    if(i<0){
      printf("0\n");
    }
    else{
      for(j=i;j>=0;j--){
        printf("%d",result[j]);
      }
      printf("\n");
    }
    memset(a,'\0',sizeof(a));
    memset(b,'\0',sizeof(b));
  }
  return 0;
}
