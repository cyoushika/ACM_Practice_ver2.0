#include<stdio.h>
#include<string.h>
#define MAXN 200010

int main(){
    int T;
    scanf("%d",&T);
    long long a[MAXN];
    while(T--){
        int n;
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        long long point = -999;
        long long temp = 0;
        for(int i=0;i<n;i++){
            // printf("a[%d]:%lld->",i,a[i]);
            temp+=a[i];
            for(int step = i+a[i];step<n;){
                temp += a[step];
                step = step+a[step];
                // printf("a[%d]:%lld->",step,a[step]);
            }
            if(temp>point){
                point=temp;
                // printf("Start from %d: %lld\n",i,point);
            }
            temp=0;
            // printf("\n");
        }
        printf("%lld\n", point);
    }
}
