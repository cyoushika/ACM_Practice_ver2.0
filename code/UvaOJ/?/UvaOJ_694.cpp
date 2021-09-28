#include<stdio.h>
// #define LOCAL

int main(){
  long long int m,n;
  int count=1;
  int terms=0;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while(true){
    scanf("%lld%lld",&m,&n);
    long long int a = m;
    long long int l = n;
    if(m==-1&&n==-1){
      break;
    }
    terms=0;
    while(true){
      if(m==1){
        terms++;
        break;
      }
      else if(m>n){
        break;
      }
      else if(m%2==0){
        // printf("Even\n");
        m = m/2;
        terms++;
      }
      else if(m%2==1){
        // printf("Odd\n");
        m = 3*m+1;
        terms++;
      }
    }
    printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n",count,a,l,terms);
    count++;
  }
  return 0 ;
}
