#include<stdio.h>
#include<string.h>
#define MAXN 210
//#define LOCAL
using namespace std;

int edges[MAXN][MAXN];
int colors[MAXN];
int n,l;
int sx, sy;
bool flag;

void DFS(int x,int color)
{
    if(!flag)
    {
        return;
    }
    if(colors[x]!=-1)
    {
        if(colors[x]!=color)
        {
            flag=false;
            return;
        }
        else
        {
            return;
        }
    }
    colors[x]=color;
    for(int i=0; i<n; i++)
    {
        if(edges[x][i])
        {
            DFS(i,(color+1)%2);
        }
    }
    return;
}

int main()
{
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    while(scanf("%d",&n)!=EOF&&n)
    {
        scanf("%d",&l);
        memset(edges,0,sizeof(edges));
        memset(colors,-1,sizeof(colors));
        int x,y;
        for(int i=0; i<l; i++)
        {
            scanf("%d%d",&x,&y);
            edges[x][y]=1;
            edges[y][x]=1;
            if(i==0)
            {
                sx=x;
            }
        }
        flag=true;
        DFS(sx,0);
        printf("%s\n",flag?"BICOLORABLE.":"NOT BICOLORABLE.");
    }
    return 0;
}
