#include<stdio.h>
// #define LOCAL

int main(){
  long long int a, b;
  int kase=0;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while(scanf("%lld%lld",&a,&b)==2&&a&&b){
    printf("Case %d: %lld\n",++kase,a*(a-1)*b*(b-1)/4);
    //从两轴各取2个点连线可构成一个交点，
    //a轴有C(a,2)个取法，b轴有C(b,2)个取法，所以共有C(a,2)*C(b*2)个交点
    //下面的计算法方法是对的，但是太慢了
    // long long int i,j;
    // long long int count=0;
    // for(int i=1;i<=a;i++){
    //   for(int j=1;j<=b;j++){
    //     count+=(i-1)*(b-j);//a轴该点左侧剩余点*b轴该点右侧剩余点，即为交点个数
    //     count+=(a-i)*(j-1);//a轴该点右侧剩余点*b轴该点左侧剩余点，即为交点个数
    //   }
    // }
    // printf("Case %d: %lld\n",++kase, count/2);//每个交点都被计算了2次，故除以2
  }
  return 0;
}
