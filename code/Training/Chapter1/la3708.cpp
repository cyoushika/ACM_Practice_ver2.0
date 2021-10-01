#include<stdio.h>
#include<cmath>
using namespace std;

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        double ans = 0.0;
        for(int i=1;i<n;i++){
            double pos = (double) i/n*(n+m);
            printf("%d = %lf\n",i,pos);
            ans+=fabs(pos-floor(pos+0.5))/(n+m);
        }
        printf("%.4lf\n",ans*10000);
    }
    return 0;
}
