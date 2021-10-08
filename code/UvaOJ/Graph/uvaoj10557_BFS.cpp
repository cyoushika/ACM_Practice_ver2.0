#include<stdio.h>
#include<string.h>
#define MAXN 110
#define MAX_QUEUE 1000000
#define MAX_ENERGY 100000
#define LOCAL

struct Room
{
    int energy;
    int num_doors;
    int doors[MAXN];
    int history;
};

Room room[MAXN];

struct Status
{
    int pos;
    int energy;
};

Status queue[MAX_QUEUE];

int head;
int tail;

int found;
int n;

void BFS(int pos, int energy)
{
//    printf("Room #%d, Energy: %d\n",pos, energy);
    if(found==1)
    {
        return;
    }
    if(energy<=0)
    {
        return;
    }
    if(pos==n)
    {
        found=1;
        return;
    }

    if(energy>room[pos].history)
    {
        room[pos].history = energy;
    }
    else
    {
        return;
    }
    queue[tail].pos = pos;
    queue[tail].energy = energy;
    tail++;
}

int main()
{
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    while(scanf("%d",&n)!=EOF&&n!=-1)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&room[i].energy,&room[i].num_doors);
            for(int j=0; j<room[i].num_doors; j++)
            {
                scanf("%d",&room[i].doors[j]);
            }
            room[i].history=0;
        }
        head = 0;
        tail = 1;
        found = 0;
        queue[head].energy=100;
        queue[head].pos=1;
        while(head<tail)
        {
            if(queue[head].energy>MAX_ENERGY)
            {
                break;
            }
            int pos = queue[head].pos;

            for(int i=0; i<room[pos].num_doors; i++)
            {
                int next = room[pos].doors[i];
                BFS(next,queue[head].energy+room[next].energy);
            }
            head++;
        }
        if(found==0)
        {
            printf("hopeless\n");
        }
        else{
            printf("winnable\n");
        }
    }
    return 0;
}
