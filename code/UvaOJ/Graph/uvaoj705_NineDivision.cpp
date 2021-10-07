#include<stdio.h>
#include<string.h>
#define MAXH 1000
#define MAXW 1000
//#define LOCAL
using namespace std;

char map[MAXH][MAXH];
int w_max, h_max;
int kase=0;

int dw[4] = {0,0,1,-1};
int dh[4] = {1,-1,0,0};

void nine_division(int x,int y,char ch)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            map[x*3+i][y*3+j]=' ';
        }
    }
    if(ch=='/')
    {
        map[x*3][y*3+2]='#';
        map[x*3+1][y*3+1]='#';
        map[x*3+2][y*3]='#';
    }
    else
    {
        map[x*3][y*3]='#';
        map[x*3+1][y*3+1]='#';
        map[x*3+2][y*3+2]='#';
    }
}

int FloodFill(int x, int y)
{
    if(x<0||x>=h_max||y<0||y>=w_max) return 0;
    if(map[x][y]!=' ') return 0;
    map[x][y]='#';
    int sum=1;
    for(int i=0; i<4; i++)
    {
        sum+=FloodFill(x+dh[i],y+dw[i]);
    }
    return sum;
}

int main()
{
    int w,h;
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    while(scanf("%d%d",&w,&h)==2&&w)
    {
        getchar();
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                char ch = getchar();
                nine_division(i,j,ch);
            }
            getchar();
        }
        w_max = w*3;
        h_max = h*3;

        for(int i=0; i<h_max; i++)
        {
            FloodFill(i,0);
            FloodFill(i,w_max-1);
        }

        for(int i=0; i<w_max; i++)
        {
            FloodFill(0,i);
            FloodFill(h_max-1,i);
        }

        int max=0,sum=0;
        for(int i=0; i<h_max; i++)
        {
            for(int j=0; j<w_max; j++)
            {
                int result = FloodFill(i,j)/3;
                if(result)
                {
                    max = result>max?result:max;
                    sum++;
                }
            }
        }

        printf("Maze #%d:\n",++kase);
        if(sum)
        {
            printf("%d Cycles; the longest has length %d.\n",sum,max);
        }
        else
        {
            printf("There are no cycles.\n");
        }
        printf("\n");
    }
    return 0;
}
