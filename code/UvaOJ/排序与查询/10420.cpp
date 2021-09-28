#include<stdio.h>
#include<string.h>
#define MAXN 2100
// #define LOCAL

char country[MAXN][80];
char buf[MAXN];
int girls[MAXN];

void qsort(char a[MAXN][80], int* b,int l,int r){
  int m=(l+r)/2;
  char mid[MAXN];
  strcpy(mid,a[m]);

  int i=l, j=r;
  char temp[MAXN];
  int gtemp=0;

  while(i<=j){
    while(strcmp(a[i],mid)<0) i++;
    while(strcmp(a[j],mid)>0) j--;
    if(i<=j){
      strcpy(temp,a[i]);
      strcpy(a[i],a[j]);
      strcpy(a[j],temp);

      gtemp=b[i];
      b[i]=b[j];
      b[j]=gtemp;

      i++;
      j--;
    }
  }
  if(i<r) qsort(a,b,i,r);
  if(j>l) qsort(a,b,l,j);
  return;
}

int main(){
  int n;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  scanf("%d",&n);

  int count=0;
  int p=0;
  char c;
  for(int i=0;i<n;i++){
    if(i==0){
      scanf("%s",country[0]);
      while((c=getchar())!='\n') p=0;
      girls[0]++;
      count++;
    }
    else{
      int flag=1;
      scanf("%s",buf);
      for(int j=0;j<count;j++){
        if(strcmp(buf,country[j])==0){
          girls[j]++;
          flag=0;
          break;
        }
      }
      if(flag){
        strcpy(country[count],buf);
        girls[count]++;
        count++;
      }
      while((c=getchar())!='\n') p=0;
    }
  }
  qsort(country,girls,0,count-1);
  for(int i=0;i<count;i++){
    printf("%s %d\n",country[i],girls[i]);
  }
  return 0;
}
