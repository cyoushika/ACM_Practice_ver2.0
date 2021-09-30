#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#define MAXN 20010
using namespace std;

int cmp_int(const void* _a, const void* _b){
    int* a = (int*) _a;
    int* b = (int*) _b;
    return *a-*b;
}

int dragon[MAXN];
int knight[MAXN];

int main(){
    int n,m;
    while(true){
        scanf("%d%d",&n,&m);
        if(n==0&&m==0){
            break;
        }
        memset(dragon,0,sizeof(dragon));
        memset(knight,0,sizeof(knight));
        for(int i=0;i<n;i++){
            scanf("%d",&dragon[i]);
        }
        for(int i=0;i<m;i++){
            scanf("%d",&knight[i]);
        }
//        qsort(dragon,n,sizeof(dragon[0]),cmp_int);
//        qsort(knight,m,sizeof(knight[0]),cmp_int);
        sort(dragon,dragon+n);
        sort(knight,knight+m);
        int count=0;
        int j=0;
        for(int i=0;i<m&&j<n;i++){
            if(knight[i]>=dragon[j]){
                j++;
                count+=knight[i];
            }
        }
        if(j==n){
            printf("%d\n",count);
        }
        else{
            printf("Loowater is doomed!\n");
        }
    }
    return 0;
}
