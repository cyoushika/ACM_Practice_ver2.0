#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXN 60
//#define LOCAL
using namespace std;

char map[MAXN][MAXN];
int his[MAXN][MAXN];
int dh[4]= {-1,1,0,0};
int dw[4]= {0,0,1,-1};
int ans[MAXN];
int pointer;

void DFS_X(int row, int col, int h, int w)
{
    map[row][col] = '*';
    for(int i=0; i<4; i++)
    {
        int r = row+dh[i];
        int c = col+dw[i];
        if(r>=0&&r<h&&c>=0&&c<w&&map[r][c]=='X')
        {
            DFS_X(r,c,h,w);
        }
    }
}

void DFS(int row, int col, int h, int w)
{
    if(map[row][col]=='X')
    {
        ans[pointer]++;
        DFS_X(row,col,h,w);
    }
    map[row][col]='.';
    for(int i=0; i<4; i++)
    {
        int r = row+dh[i];
        int c = col+dw[i];
        if(r>=0&&r<h&&c>=0&&c<w&&his[r][c]==0&&map[r][c]!='.')
        {
            DFS(r,c,h,w);
        }
    }
}

int main()
{
    int w,h;
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    int kase=0;
    while(scanf("%d%d",&w,&h)!=EOF&&w!=0)
    {
        getchar();
        printf("Throw %d\n",++kase);
        memset(map,'\0',sizeof(map));
        memset(ans,0,sizeof(ans));
        memset(his,0,sizeof(his));
        pointer=0;

        for(int i=0; i<h; i++)
        {
            scanf("%s",map[i]);
        }
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                if(map[i][j]=='*')
                {
                    DFS(i,j,h,w);
                    pointer++;
                }
            }
        }

        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                if(map[i][j]=='X')
                {
                    ans[pointer]++;
                    DFS_X(i,j,h,w);
                    pointer++;
                }
            }
        }
        sort(ans,ans+pointer);
        for(int i=0; i<pointer-1; i++)
        {
            printf("%d ",ans[i]);
        }
        printf("%d\n\n",ans[pointer-1]);
    }
    return 0;
}
