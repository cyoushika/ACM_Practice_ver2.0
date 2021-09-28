#include<stdio.h>
#include<math.h>
#define LOCAL

int main(){
  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif
  long long workNum, initH, lazyNum, sumH, n, k, num, h, i;
  long double temp, temp1;
  while(scanf("%lld%lld",&initH,&workNum)==2){
    if(initH==0&&workNum==0){
      break;
    }
    else if(initH==1){
      lazyNum=0;
      sumH=workNum*initH;
    }
    else{
      lazyNum=0;
      sumH=0;
      num=1;
      h=initH;
      for(k=1;k<=initH*workNum;k++){
        temp=pow((double)workNum,1.0/k)+1.0;
        temp1=pow((double)initH,1.0/k);
        if(fabs(temp-temp1)<0.001){
          break;
        }
      }
      n=(int)floor(0.5+temp)-1;
      for(i=0;i<k;i++){
        sumH+=num*h;
        lazyNum+=num;
        num*=n;
        h=h/(n+1);
      }
      sumH+=workNum;
    }
    printf("%lld %lld\n",lazyNum,sumH);
  }
  return 0;
}
