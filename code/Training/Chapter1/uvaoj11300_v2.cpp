#include<stdio.h>
#include<algorithm>
#include<string.h>
#define MAXN 1000010
//#define LOCAL
using namespace std;

long long partitation(long long* arr, long long low, long long high)
{
    long long pivot = arr[low];
    while(low<high)
    {
        while(low<high&&arr[high]>=pivot)
        {
            high--;
        }
        arr[low] = arr[high];
        while(low<high&&arr[low]<=pivot)
        {
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low]=pivot;
    return low;
}

long long qselect(long long* arr, long long low, long long high, long long k)
{
    long long pivot = partitation(arr,low,high);
//    if(low<high){
//        qselect(arr,low,pivot-1,k);
//        qselect(arr,pivot+1,high,k);
//    }
//    return 0;
    if(pivot==k)
    {
        return arr[k];
    }
    else if(pivot<k)
    {
        return qselect(arr,pivot+1,high,k);
    }
    else
    {
        return qselect(arr,low,pivot-1,k);
    }
}

int n;
long long c[MAXN],a[MAXN],tot,M,x1,ans;

int main()
{
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    while(scanf("%d",&n)!=EOF)
    {
        memset(c,0,sizeof(c));
        memset(a,0,sizeof(a));
        tot=0;
        ans=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&a[i]);
            tot+=a[i];
        }
        M = tot/n;
        c[0]=0;
        for(int i=1; i<n; i++)
        {
            c[i] = c[i-1]+a[i]-M;
        }
        x1 = qselect(c,1,n,n/2);
//        int mid = n/2;
//        x1 = c[n/2];
//        printf("mid = %d\n",mid);
//        for(int i=1;i<=n;i++){
//            printf("%lld ",c[i]);
//        }
//        printf("\n");
        for(int i=1; i<=n; i++)
        {
            ans+=abs(x1-c[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
