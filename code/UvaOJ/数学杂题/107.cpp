#include<stdio.h>
#include<math.h>
// #define LOCAL

int main(){
  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  long long workcat, H, lazycat, total_h, k, n, num, h, i;
  long double temp, temp1;
  while(scanf("%lld%lld",&H,&workcat)==2){
    if(H==0&&workcat==0){
      break;
    }
    else if(H==1){
      total_h=workcat*H;
      lazycat=0;
    }
    else{
      lazycat=0;
      total_h=0;
      num = 1;//最开始只有一只猫
      h=H;//初始的高度
      for(k=1;k<=H*workcat;k++){
        //workcat = N^k => N=k_root(workcat)
        //H/(N+1)^k=1 => H=(N+1)^k => N+1 = k_root(H) = k_root(workcat)+1
        temp=pow((double)workcat,1.0/k)+1.0;
        temp1=pow((double)H,1.0/k);
        if(fabs(temp-temp1)<0.001){
          break;
        }
      }
      n=(int)floor(0.5+temp)-1;//N=每个帽子里的猫
      for(int i=0;i<k;i++){
        total_h+=num*h;
        lazycat+=num;
        num*=n;
        h=h/(n+1);
      }
      total_h+=workcat;
    }
    printf("%lld %lld\n",lazycat, total_h);
  }
  return 0;
}
