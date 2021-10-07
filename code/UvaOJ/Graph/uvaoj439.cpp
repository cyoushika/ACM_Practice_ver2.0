#include<stdio.h>
#include<string.h>
#define MAXN 10
#define LOCAL
using namespace std;

int visit[MAXN][MAXN];
char sr,sc,gr,gc;
int target_r, target_c;

int dx[8] = {-2, -2, 2, 2, -1, -1, 1, 1};
int dy[8] = {-1, 1, -1, 1, 2, -2, 2, -2};

int head;
int tail;
int found = 0;
int ans;

struct Node
{
    int x;
    int y;
    int step;
};

Node queue[MAXN*MAXN];

void BFS(int x, int y, int step)
{
    if(found)
    {
        return;
    }
    if(x<=0||x>8||y<0||y>=8)// Row: 1-8, Col: a-h (0-7)
    {
        return;
    }
    if(visit[x][y])
    {
        return;
    }
    if(x==target_r&&y==target_c)
    {
        ans = step;
        found=true;
        return;
    }
    queue[tail].x = x;
    queue[tail].y = y;
    queue[tail].step = step;
    visit[x][y]=1;
    tail++;
}

int main()
{
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    while(scanf("%c%c %c%c",&sc,&sr,&gc,&gr)!=EOF)
    {
        getchar();
        memset(visit,0,sizeof(visit));
        queue[0].x = sr-'0';
        queue[0].y = sc-'a';
        queue[0].step = 0;
        head=0;
        tail=1;
        target_r = gr-'0';
        target_c = gc-'a';
        found=0;
        ans=0;
        if(sr==gr&&sc==gc)
        {
            ans=0;
        }
        else
        {
            while(head<tail)
            {
                for(int i=0; i<8; i++)
                {
                    BFS(queue[head].x+dx[i],queue[head].y+dy[i],queue[head].step+1);
                }
                head++;
            }
        }
        printf("To get from %c%c to %c%c takes %d knight moves.\n",sr,sc,gr,gc,ans);
    }
    return 0;
}
