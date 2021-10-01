#include<stdio.h>
#include<string.h>
#include<map>
#include<queue>
#define MAXN 1010
//#define LOCAL
using namespace std;

int main()
{
    int t;
    int c=0;
    int n,value;
    int kase = 0;
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    while(scanf("%d",&t)!=EOF)
    {
        if(t==0)
        {
            break;
        }
        printf("Scenario #%d\n",++kase);
        map<int,int> team;
        for(int i=0; i<t; i++)
        {
            scanf("%d",&n);
            while(n--)
            {
                scanf("%d",&value);
                team[value]=i;
            }
        }
        char action[10];
        queue<int> qteam;
        queue<int> qvalue[MAXN];
        while(scanf("%s",action)!=EOF)
        {
            if(action[0]=='S')
            {
                break;
            }
            else if(action[0]=='D')
            {
                int t = qteam.front();
                printf("%d\n",qvalue[t].front());
                qvalue[t].pop();
                if(qvalue[t].empty())
                {
                    qteam.pop();
                }
            }
            else
            {
                scanf("%d",&value);
                int t = team[value];
                if(qvalue[t].empty())
                {
                    qteam.push(t);
                }
                qvalue[t].push(value);
            }
        }
        printf("\n");
    }
    return 0;
}
