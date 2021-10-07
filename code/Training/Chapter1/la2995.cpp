#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<cmath>
using namespace std;

#define MAXN 10

int n;
char pos[MAXN][MAXN][MAXN];
char view[MAXN][MAXN][MAXN];

char read_char()
{
    char ch;
    for(;;)
    {
        ch = getchar();
        if((ch>='A'&&ch<='Z')||ch=='.')
        {
            return ch;
        }
    }
}

void get(int k, int i,int j,int depth, int &x, int &y, int &z)
{
    if(k==0)
    {
        x=depth;
        y=j;
        z=i;
    }
    if(k==1)
    {
        x=n-1-j;
        y=depth;
        z=i;
    }
    if(k==2)
    {
        x=n-1-depth;
        y=n-1-j;
        z=i;
    }
    if(k==3)
    {
        x=j;
        j=n-1-depth;
        z=i;
    }
    if(k==4)
    {
        x=n-1-i;
        y=j;
        z=depth;
    }
    if(k==5)
    {
        x=i;
        y=j;
        z=n-1-depth;
    }
}

int main()
{
    while(scanf("%d",&n)==1&&n)
    {
        for(int i=0; i<n; i++)
        {
            for(int k=0; k<6; k++)
            {
                for(int j=0; j<n; j++)
                {
                    view[k][i][j]=read_char();
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                for(int k=0; k<n; k++)
                {
                    pos[i][j][k]='#';
                }
            }
        }

        for(int k=0; k<6; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(view[k][i][j]=='.')
                    {
                        for(int d=0; d<n; d++)
                        {
                            int x,y,z;
                            get(k,i,j,d,x,y,z);
                            pos[x][y][z]='.';
                        }
                    }
                }
            }
        }
        bool done=true;
        while(true){
            for(int k=0;k<6;k++){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(view[k][i][j]!='.'){
                            for(int d=0;d<n;d++){
                                int x,y,z;
                                get(k,i,j,d,x,y,z);
                                if(pos[x][y][z]=='.') continue;
                                if(pos[x][y][z]=='#'){
                                    pos[x][y][z] = view[k][i][j];
                                    break;
                                }
                                if(pos[x][y][z] == view[k][i][j]){
                                    break;
                                }
                                pos[x][y][z]='.';
                                done = false;
                            }
                        }
                    }
                }
            }
            if(done){
                break;
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(pos[i][j][k]!='.') ans++;
                }
            }
        }
        printf("Maximum weight: %d gram(s)\n",ans);
    }
    return 0;
}

