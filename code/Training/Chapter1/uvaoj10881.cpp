#include<stdio.h>
#include<algorithm>
#define MAXN 10010
#define LOCAL
using namespace std;

struct Ant{
    int position;
    int direction;
    int ID;

    bool operator < (const Ant& a) const{
        return position<a.position;
    }

    Ant(){};

    Ant(int i, int p, int d){
        ID = i;
        position = p;
        direction = d;
    }
};

int order[MAXN];
char dir[][10] = {"L","Turning","R"};

Ant before[MAXN],after[MAXN];

int main(){
    int k;
    scanf("%d",&k);
    for(int t = 1;t<=k;t++){
        printf("Case #%d:\n",t);
        int L,T,n;
        scanf("%d%d%d",&L,&T,&n);
        int p,d;
        char c;
        for(int i=0;i<n;i++){
            before[i].ID = i;
            scanf("%d %c",&p,&c);
            before[i].position = p;
            if(c=='L'){
                d = -1;
            }
            else{
                d = 1;
            }
            before[i].direction = d;
            after[i].direction = d;
            after[i].position = p+T*d;
        }
        sort(before,before+n);
        for(int i=0;i<n;i++){
            order[before[i].ID] = i;
        }
        sort(after,after+n);
        for(int i=0;i<n-1;i++){
            if(after[i].position==after[i+1].position){
                after[i].direction = after[i+1].direction = 0;
            }
        }
        for(int i=0;i<n;i++){
            int a = order[i];
            if(after[a].position<0||after[a].position>L){
                printf("Fell off\n");
            }
            else{
                printf("%d %s\n",after[a].position,dir[after[a].direction+1]);
            }
        }
        printf("\n");
    }
    return 0;
}
