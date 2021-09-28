#include<stdio.h>
#include<string.h>
#include<math.h>
// #define LOCAL

int main(){
  int year;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while(scanf("%d",&year)==1){
    if(year==0) break;
    year=(year-1960)/10;
    int bit=pow(2,year+2);
    int count=1;
    double all=0;
    while(all<=bit*log(2)){//log(2^bit)->bit*log(2)
      all+=log(double(count));
      count=count+1;
    }
    printf("%d\n",count-2);
  }
  return 0;
}
