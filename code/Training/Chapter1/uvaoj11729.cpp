#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#define MAXN 1010
//#define LOCAL
using namespace std;

struct Job
{
    int j;
    int b;
    Job() {};
    Job(int br, int jo)
    {
        b = br;
        j = jo;
    }

    bool operator < (const Job& x) const{
        return j>x.j;
    }
};

int cmp_job(const void* _a, const void* _b)
{
    Job* a = (Job*) _a;
    Job* b = (Job*) _b;
    return (a->j<b->j);
}

int main()
{
    int n;
    int b,j;
    int kase=0;
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    while(true)
    {
        scanf("%d",&n);
        Job jobs[MAXN];
        kase++;
        if(n==0)
        {
            break;
        }
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&b,&j);
            jobs[i] = Job(b,j);
        }
//        qsort(jobs,n,sizeof(jobs[0]),cmp_job);
        sort(jobs,jobs+n);
        int s=0, ans=0;
        for(int i=0; i<n; i++)
        {
            s+=jobs[i].b;
            ans = max(ans,s+jobs[i].j);
        }
        printf("Case %d: %d\n",kase, ans);
    }
    return 0;
}
