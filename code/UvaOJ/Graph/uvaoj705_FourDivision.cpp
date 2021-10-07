#include<stdio.h>
#include<string.h>
//#define LOCAL
#define MAXH 1000
#define MAXW 1000
using namespace std;

char map[MAXH][MAXW];

int kase=0;
int wmax,hmax;

int dh[4]= {0,0,1,-1};
int dw[4]= {1,-1,0,0};

int sdh[4] = {1,1,-1,-1};
int sdw[4] = {1,-1,-1,1};

void FourDivision(int x,int y,char ch)
{
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            map[x*2+i][y*2+j]=' ';
        }
    }

    if(ch=='/')
    {
        map[x*2][y*2+1]='#';
        map[x*2+1][y*2]='#';
    }
    else
    {
        map[x*2][y*2]='#';
        map[x*2+1][y*2+1]='#';
    }
}

bool canArrive(int x, int y, int dr, int dc)
{
    int r = x%2+dr;
    int c = y%2+dc;
    if(r>=0&&r<2&&c>=0&&c<2)
    {
        return false;
    }
    else if((r<0||r>=2)&&(c<0||c>=2))
    {
        return false;
    }
    else
    {
        return true;
    }
//    printf("\n");
}

int FloodFill(int x,int y)
{
    if(x<0||x>=hmax||y<0||y>=wmax)
    {
        return 0;
    }
    if(map[x][y]!=' ') return 0;
    map[x][y]='.';
    int sum=1;
    for(int i=0; i<4; i++)
    {
        sum+=FloodFill(x+dh[i],y+dw[i]);
    }
    for(int i=0; i<4; i++)
    {
        if(canArrive(x,y,sdh[i],sdw[i]))
        {
            sum+=FloodFill(x+sdh[i],y+sdw[i]);
        }
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
                FourDivision(i,j,ch);
            }
            getchar();
        }
        wmax = w*2;
        hmax = h*2;
        for(int i=0; i<hmax; i++)
        {
            FloodFill(i,0);
            FloodFill(i,wmax-1);
        }
        for(int i=0; i<wmax; i++)
        {
            FloodFill(0,i);
            FloodFill(hmax-1,i);
        }

        int max=0,sum=0;
        for(int i=0; i<hmax; i++)
        {
            for(int j=0; j<wmax; j++)
            {
                int result = FloodFill(i,j);
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
