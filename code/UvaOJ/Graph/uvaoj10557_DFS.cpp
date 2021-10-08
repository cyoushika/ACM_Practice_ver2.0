#include<stdio.h>
#include<string.h>
#define MAXN 110
//#define LOCAL

struct Room
{
    int energy;
    int doors[MAXN];
    int num_door;
    int history;
};

Room room[MAXN];
int n;

bool visit[MAXN];

bool canArrive(int pos);
bool Search(int pos, int energy);

int main()
{
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    while(scanf("%d",&n)!=EOF&&n!=-1)
    {
        int e, nd, d;
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&room[i].energy,&room[i].num_door);
            for(int j=0; j<room[i].num_door; j++)
            {
                scanf("%d",&room[i].doors[j]);
            }
            room[i].history = -1;
        }
        printf("%s\n",Search(1,100)?"winnable":"hopeless");
    }
    return 0;
}

bool Search(int pos, int energy)
{
//    printf("Room : %d, Energy: %d\n",pos,energy);
    if(energy<=0)
    {
//        printf("Energy Too Low!\n");
        return false;
    }
    if(pos==n)
    {
//        printf("Found The Goal!\n");
        return true;
    }
    if(room[pos].history!=-1)
    {
//        printf("A Loop!\n");
        if(energy>room[pos].history)
        {
            memset(visit, false, sizeof(visit));
            if(canArrive(pos))
            {
//                printf("Find The Goal Through the Loop!\n");
                return true;
            }
        }
//        printf("A Dead Loop!\n");
        return false;
    }

    room[pos].history = energy;
    for(int i=0; i<room[pos].num_door; i++)
    {
        if(Search(room[pos].doors[i],room[room[pos].doors[i]].energy+energy))
        {
            return true;
        }
    }
    return false;
}

bool canArrive(int pos)
{
    if(visit[pos])
    {
        return false;
    }
    if(pos==n)
    {
        return true;
    }
    visit[pos]=true;
    for(int i=0; i<room[pos].num_door; i++)
    {
        if(canArrive(room[pos].doors[i]))
        {
            return true;
        }
    }
    return false;
}
