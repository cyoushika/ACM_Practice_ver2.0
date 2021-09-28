#include<stdio.h>
#include<math.h>

void qsort(int *a,int p,int q){
  int i=p,j=q;
  int mid=(p+q)/2;
  while(i<=j){
    while(a[i]<a[mid]){
      i++;
    }
    while(a[j]>a[mid]){
      j--;
    }
    if(i<=j){
      int temp = a[i];
      a[i]=a[j];
      a[j]=temp;
      i++;
      j--;
    }
  }
  if(i<q){
    qsort(a,i,q);
  }
  if(p<j){
    qsort(a,p,j);
  }
  return;
}

int main(){
  int a[10] = {};
  scanf("%d%d%d",&a[0],&a[1],&a[2]);
  qsort(a,0,2);
  for(int i=0;i<2;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[2]);
  return 0;
}
