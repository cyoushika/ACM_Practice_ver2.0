#include<stdio.h>
#include<string.h>
#include<iostream>
#define MAXN 50
#define MAX_QUEUE 5000000
//#define LOCAL
using namespace std;

enum Color
{
    GREEN = 0,
    BLACK = 1,
    RED = 2,
    BLUE = 3,
    WHITE = 4,
};

enum Direction
{
    NORTH = 0,
    SOUTH = 1,
    WEST = 2,
    EAST = 3,
};

struct Status
{
    int x;
    int y;
    Color color;
    int time;
    Direction direction;
};

Status queue[MAX_QUEUE];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int kase=0;
int head;
int tail;
bool found;
int m, n;
int ans=0;

char map[MAXN][MAXN];

int visit[MAXN][MAXN][10][10];

void BFS();
void INIT();
void Search(int x, int y, Direction direction, Color color, int t);

int main()
{
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    while(scanf("%d%d",&m,&n)!=EOF&&m)
    {
        getchar();
        for(int i=0; i<m; i++)
        {
            gets(map[i]);
        }
        BFS();
        if(++kase>1)
        {
            printf("\n");
        }
        printf("Case #%d\n",kase);
        if(found)
        {
            printf("minimum time = %d sec\n",ans);
        }
        else
        {
            printf("destination not reachable\n");
        }
    }
    return 0;
}

void BFS()
{
    INIT();
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(map[i][j]=='S')
            {
                Search(i,j,NORTH,GREEN,0);
                break;
            }
        }
    }

    while(head<tail)
    {
        Status now = queue[head];
        if(map[now.x][now.y]=='T'&&now.color==GREEN)
        {
            ans = now.time;
            found = true;
            break;
        }

        for(int i=0; i<4; i++)
        {
            int times_turn;
            if(now.direction==i)
            {
                times_turn=1;
            }
            else
            {
                if(now.direction+i!=1&&now.direction+i!=5)
                {
                    times_turn=2;
                }
                else
                {
                    times_turn=3;
                }
            }
            Search(now.x+dx[i],now.y+dy[i],(Direction) i, (Color)((now.color+1)%5), now.time+times_turn);
        }
        head++;
    }
}

void INIT()
{
    memset(visit, 0, sizeof(visit));
    head=0;
    tail=0;
    found=false;
}

void Search(int x, int y, Direction direction, Color color, int t)
{
    if(x<0||x>=m||y<0||y>=n)
    {
        return;
    }
    if(map[x][y]=='#')
    {
        return;
    }
    if(visit[x][y][direction][color]&&t>=visit[x][y][direction][color])
    {
        return;
    }
    visit[x][y][direction][color]=t;
    int pos_insert = tail++;
    while(t<queue[pos_insert-1].time)
    {
        queue[pos_insert] = queue[pos_insert-1];
        --pos_insert;
    }
    queue[pos_insert].x=x;
    queue[pos_insert].y=y;
    queue[pos_insert].direction=direction;
    queue[pos_insert].color = color;
    queue[pos_insert].time = t;
}
