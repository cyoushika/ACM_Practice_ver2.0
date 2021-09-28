#include<stdio.h>
// #define LOCAL

//1x1的正方形的每条边有2个端点，nxn的正方形的每条边上有n+1个点。
//从x轴方向的一条边上的n+1个点中，任取2点，得到一个边，视为长。
//再从y轴方向的一条边的n+1个点中任取2点，得到另一条边，视为宽。
//两条边（及其平行边）所围成的四边形，即为长方形（长=宽时为正方形）
//而取点的方法共有C(n+1,2)*C(n+1,2)种，得到的结果即所有长方形的个数（包含正方形）。
//同理可的，nxnxn的正方体里，共有C(n+1,2)*C(n+1,2)*C(n+1,2)个长方体。
//本题区分长方和正方，所以需要在结果的基础上减去正方的个数。
//二维下，正方形个数为Σ（i->n) i^2，三维下，正方体个数为Σ（i->n) i^3,以此类推。

int main(){
  long long int n;
  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while(scanf("%lld",&n)!=EOF){

    long long int temp=0,temp1=0,temp2=0,temp3=0,temp4=0,temp5=0,temp6=0;

    temp = (n+1)*n/2;
    temp2 = temp*temp;
    temp4 = temp*temp*temp;
    temp6 = temp2*temp2;
    while(n>0){
      temp1+=n*n;
      temp3+=n*n*n;
      temp5+=n*n*n*n;
      n--;
    }
    temp2-=temp1;
    temp4-=temp3;
    temp6-=temp5;
    printf("%lld %lld %lld %lld %lld %lld\n",temp1,temp2,temp3,temp4,temp5,temp6);
  }
  return 0;
}
