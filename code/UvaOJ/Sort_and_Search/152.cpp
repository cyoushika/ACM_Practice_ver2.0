#include<stdio.h>
#include<math.h>
#include<string.h>
// #define LOCAL
#define MAXN 5010

int x[MAXN]={0};
int y[MAXN]={0};
int z[MAXN]={0};
double d[MAXN]={0.0};
int ans[256]={0};

void qsort(double* a, int l, int r){
  int i=l,j=r;
  int m=(l+r)/2;
  double mid = a[m];
  while(i<=j){
    while(a[i]<mid) i++;
    while(a[j]>mid) j--;
    if(i<=j){
      double temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      i++;
      j--;
    }
  }
  if(i<r) qsort(a,i,r);
  if(j>l) qsort(a,l,j);
  return;
}

int main(){
  int a,b,c;
  int len=0;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while(scanf("%d%d%d",&a,&b,&c)==3){
    if(a==0&&b==0&&c==0){
      break;
    }
    else{
      x[len]=a;
      y[len]=b;
      z[len]=c;
      len++;
    }
  }
  int count=0;
  double bais = 1e-10;
  for(int i=0;i<len;i++){
    for(int j=0;j<len;j++){
      if(i!=j){
        d[count]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]);
        d[count]=sqrt(d[count]);
        count++;
      }
    }
    qsort(d,0,count-1);
    // for(int i=0;i<len-1;i++){
    //   printf("%.2lf ",d[i]);
    // }
    // printf("\n");
    count=0;
    // printf("%.2lf\n",d[0]);
    ans[(int)(ceil(d[0]+bais))]++;
  }
  for(int i=1;i<=10;i++){
    printf("%4d",ans[i]);
  }
  printf("\n");
  return 0;
}
