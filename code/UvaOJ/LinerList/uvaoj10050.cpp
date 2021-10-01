#include<stdio.h>
#include<string.h>
#define MAXN 3700
//#define LOCAL

int main()
{
    int kase;
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    scanf("%d",&kase);
    int map[MAXN];
    while(kase--)
    {
        int p,D;
        memset(map,0,sizeof(map));
        scanf("%d",&D);
        scanf("%d",&p);
        int ans = 0;
        int party = 0;
        for(int i=0; i<p; i++)
        {
            scanf("%d",&party);
            int day = party;
            while(day<=D)
            {
//                printf("Party%d, Day = %d\n",i, day);
                if(map[day]==0&&(day%7!=0&&day%7!=6))
                {
                    ans++;
                    map[day]=1;
                }
                day+=party;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
