#include<stdio.h>
#include<string.h>
#include<iostream>
#include<ctype.h>
#include<math.h>
using namespace std;
#define MAXN 90
//#define LOCAL

char map[MAXN][MAXN];
int row;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

void find_start(int &x, int &y)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<strlen(map[i]); j++)
        {
            if(map[i][j]=='*')
            {
                x=i;
                y=j;
                return;
            }
        }
    }
}

void DFS(int x, int y)
{
    map[x][y]='#';
    for(int i=0; i<4; i++)
    {
        int r = x+dr[i];
        int c = y+dc[i];
        if(map[r][c]==' ')
        {
            DFS(r,c);
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    int n;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        memset(map,'\0',sizeof(map));
        for(row=0;; row++)
        {
            gets(map[row]);
            if(map[row][0]=='_')
            {
                break;
            }
        }
        int x,y;
        find_start(x,y);
        DFS(x,y);
        for(int i=0; i<=row; i++)
        {
            printf("%s\n",map[i]);
        }
    }
    return 0;
}
