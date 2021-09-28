#include<stdio.h>
#define MAXN 100000
// #define LOCAL

int a[MAXN];

void qsort(int* a, int l, int r){
  int i=l,j=r;
  int m=(l+r)/2;
  int mid=a[m];
  while(i<=j){
    while(a[i]<mid) i++;
    while(a[j]>mid) j--;
    if(i<=j){
      int temp = a[i];
      a[i]=a[j];
      a[j]=temp;
      i++;
      j--;
    }
  }
  if(i<r) qsort(a,i,r);
  if(l<j) qsort(a,l,j);
  return;
}

int main(){
  int m,n;
  int t;
  int count=0;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while(scanf("%d%d",&m,&n)==2&&(m&&n)){
    printf("CASE# %d:\n",++count);
    for(int i=0;i<m;i++){
      scanf("%d",&a[i]);
    }
    qsort(a,0,m-1);
    int j=0;
    for(int i=0;i<n;i++){
      scanf("%d",&t);
      for(j=0;j<m;j++){
        if(a[j]==t){
          break;
        }
      }
      if(j==m){
        printf("%d not found\n",t);
      }
      else{
        printf("%d found at %d\n",t,j+1);
      }
    }
  }
  return 0;
}
