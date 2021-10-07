#include<stdio.h>
#include<string.h>
#define MAXN 110
//#define LOCAL

char map[MAXN][MAXN];
int h[MAXN][MAXN];
int count;
int dm[8] = {-1,1,0,0,-1,-1,1,1};//up,down,left,right
int dn[8] = {0,0,-1,1,-1,1,-1,1};

void DFS(int row,int col,int m,int n)
{
    h[row][col]=1;
    for(int i=0; i<8; i++)
    {
        if(row+dm[i]>=0&&row+dm[i]<m&&col+dn[i]>=0&&col+dn[i]<n&&map[row+dm[i]][col+dn[i]]=='@'&&h[row+dm[i]][col+dn[i]]==0)
        {
            DFS(row+dm[i],col+dn[i],m,n);
        }
    }
    return;
}

int main()
{
    int m,n;
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    while(scanf("%d %d",&m,&n)!=EOF&&m!=0)
    {
        memset(map,'\n',sizeof(map));
        memset(h,0,sizeof(h));
        count=0;
        getchar();
        for(int i=0; i<m; i++)
        {
            fgets(map[i],sizeof(map[i]),stdin);
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(map[i][j]=='@'&&h[i][j]==0)
                {
                    count++;
                    DFS(i,j,m,n);
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
