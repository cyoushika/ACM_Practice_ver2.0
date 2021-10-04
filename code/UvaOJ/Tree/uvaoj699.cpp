#include<stdio.h>
#include<string.h>
#define MAXN 1000
//#define LOCAL
using namespace std;
int answer[MAXN];

void build(int p)
{
    int v;
    scanf("%d",&v);
    if(v==-1)
    {
        return;
    }
    answer[p]+=v;
    build(p-1);
    build(p+1);
}

bool init()
{
    int v;
    scanf("%d",&v);
    if(v==-1)
    {
        return false;
    }
    int pos = MAXN/2;
    memset(answer,0,sizeof(answer));
    answer[pos] = v;
    build(pos-1);
    build(pos+1);
    return true;
}

int main()
{
    int kase=1;
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    while(init())
    {
        int p=0;
        while(answer[p]==0) p++;
        printf("Case %d:\n",kase++);
        printf("%d",answer[p++]);
        while(answer[p]!=0)
        {
            printf(" %d",answer[p++]);
        }
        printf("\n\n");
    }
    return 0;
}
