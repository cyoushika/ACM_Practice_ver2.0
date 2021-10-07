#include<stdio.h>
#include<string.h>
#define MAXN 35
//#define LOCAL

char map[MAXN][MAXN][MAXN];
int start_L, start_R, start_C;
int goal_L,goal_R,goal_C;

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,-1,1,0,0};
int dz[6] = {0,0,0,0,-1,1};

int ans;

struct Status
{
    int x;
    int y;
    int z;
    int time;
};

int head, tail;
int L,R,C;

int found;

Status queue[MAXN*MAXN*MAXN];

void BFS(int l, int r, int c, int time)
{
    if(found)
    {
        return;
    }
    if(l<0||l>=L||r<0||r>=R||c<0||c>=C)
    {
        return;
    }
    if(map[l][r][c]=='#')
    {
        return;
    }
    if(l==goal_L&&r==goal_R&&c==goal_C)
    {
        ans=time;
        found=1;
        return;
    }
    queue[tail].z = l;
    queue[tail].x = r;
    queue[tail].y = c;
    queue[tail].time = time;
    map[l][r][c]='#';
    tail++;
}

int main()
{
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    while(scanf("%d%d%d",&L,&R,&C)!=EOF&&L)
    {
        getchar();
        memset(map,'#',sizeof(map));
        for(int i=0; i<L; i++)
        {
            for(int j=0; j<R; j++)
            {
                for(int k=0; k<C; k++)
                {
                    map[i][j][k] = getchar();
                    if(map[i][j][k]=='S')
                    {
                        start_L = i;
                        start_R = j;
                        start_C = k;
                    }
                    else if(map[i][j][k]=='E')
                    {
                        goal_L = i;
                        goal_R = j;
                        goal_C = k;
                    }
                }
                getchar();
            }
            getchar();
        }
        if(start_L==goal_L&&start_R==goal_R&&start_C==goal_C)
        {
            ans = 0;
        }
        else
        {
            head = 0;
            tail = 1;
            ans = 0;
            found=0;
            queue[0].z = start_L;
            queue[0].x = start_R;
            queue[0].y = start_C;
            queue[0].time = 0;
            while(head<tail)
            {
                for(int i=0; i<6; i++)
                {
                    BFS(queue[head].z+dz[i],queue[head].x+dx[i],queue[head].y+dy[i],queue[head].time+1);
                }
                head++;
            }
        }
        if(found)
        {
            printf("Escaped in %d minute(s).\n",ans);
        }
        else
        {
            printf("Trapped!\n");
        }
    }
    return 0;
}


