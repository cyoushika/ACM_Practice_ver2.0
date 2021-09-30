#include<stdio.h>
#include<algorithm>
#define MAXN 1000010
//#define LOCAL
using namespace std;

long long A[MAXN], C[MAXN], tot, M;

int main()
{
    int n;
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    while(scanf("%d",&n)==1)
    {
        tot=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&A[i]);
            tot += A[i];
        }
        M = tot/n;
        C[0] = 0;
        for(int i=1; i<n; i++)
        {
            C[i] = C[i-1]+A[i]-M;
        }
        sort(C,C+n);
        long long x1 = C[n/2];
        long long ans = 0;
        for(int i=0; i<n; i++)
        {
            ans += abs(x1-C[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
