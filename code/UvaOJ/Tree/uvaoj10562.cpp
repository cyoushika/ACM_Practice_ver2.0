#include<stdio.h>
#include<string.h>
#include<iostream>
#include<ctype.h>
#define MAXN 200000
//#define LOCAL
using namespace std;

char disk[205][205];

bool isNode(char c)
{
    return isprint(c)&&c!='|'&&c!=' '&&c!='-'&&c!='#';
}

void DFS(int n, int row, int l, int r, int ok)
{
    if(ok&&row<n)
    {
        printf("(");
        for(int i=l; i<r&&i<strlen(disk[row]); i++)
        {
            if(isNode(disk[row][i]))
            {
                printf("%c",disk[row][i]);
                if(row+1<n&&i<strlen(disk[row+1])&&disk[row+1][i]=='|')
                {
                    DFS(n,row+2,i,i,0);
                }
                else{
                    printf("()");
                }
            }
        }
        printf(")");
    }
    else if(!ok&&row<n)
    {
        int j,k;
        for(j=l; j>0; j--)
        {
            if(disk[row][j-1]!='-')
            {
                break;
            }
        }
        for(k=l; k<strlen(disk[row]); k++)
        {
            if(disk[row][k]!='-')
            {
                break;
            }
        }
        DFS(n,row+1,j,k,1);
    }
}

int main()
{
    int n,pointer=0;
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        memset(disk,'\0',sizeof(disk));
        pointer = 0;
        while(fgets(disk[pointer],sizeof(disk[pointer]),stdin))
        {
            if(disk[pointer][0]=='#')
            {
                break;
            }
            pointer++;
        }
        int j=0;
        while(disk[j][0]=='\0')
        {
            j++;
        }

//        for(int p = 0;p<pointer;p++){
//            printf("%s\n",disk[p]);
//        }
        if(j==pointer)
        {
            printf("()");
        }
        else
        {
            DFS(pointer,j,0,strlen(disk[j]),1);
        }
        printf("\n");
    }
    return 0;
}
