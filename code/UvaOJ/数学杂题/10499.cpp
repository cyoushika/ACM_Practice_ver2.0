/*
题意：为了促进经济，数学家提议用商品的表面积代替体积作为交易的标准。一个商人买了一个实心球体。
为了将利益最大化，他将球体分成了n份。每份均延球的中心轴切下。求分割完毕后，商人的利润增加了多少。

解答：因为是延球的中心轴分割的，每切出一份，增加了2个面积为πr^2/2的半圆，合在一起就是πr^2。
切成N份，则为N*πr^2。而球体本身的表面积为4πr^2，新增的面积占原有面积的比例，即为商人的利润。

需要注意的是：放N=1时，意味着不切，所以不增加任何面积，利润率应该为0.
 */
#include<stdio.h>
// #define LOCAL

int main(){
  int n;
  double temp;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while(scanf("%d",&n)==1){
    if(n<0){
      break;
    }
    if(n==1){
      printf("0%%\n");
      continue;
    }
    temp=(double)n/4*100;
    printf("%.0lf%%\n",temp);
  }
  return 0;
}
