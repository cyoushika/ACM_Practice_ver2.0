#include<stdio.h>
#include<string.h>
#define MAXN 3010
#define LOCAL

double a0;
double an1;
double c[MAXN];
double s[MAXN];

int main(){
  int t;

  #ifdef LOCAL
  freopen("/Users/zhangzhihua/Desktop/project/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("/Users/zhangzhihua/Desktop/project/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  scanf("%d",&t);
  int n;
  // double temp = 1e-9;
  while(t--){
    memset(c,0.0,sizeof(c));
    memset(s,0.0,sizeof(s));
    scanf("%d",&n);
    scanf("%lf",&a0);
    scanf("%lf",&an1);
    double S=0.0;
    for(int i=1;i<=n;i++){
      scanf("%lf",&c[i]);
      s[i]=s[i-1]+c[i];
      S+=s[i];
    }
    printf("%.2lf\n",(n*a0+an1-2*S)/(n+1));
    if(t>0){
      printf("\n");
    }
    S=0.0;
  }
  return 0;
}
