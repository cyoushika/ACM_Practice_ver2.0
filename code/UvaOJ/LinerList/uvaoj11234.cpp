#include<stdio.h>
#include<string.h>
#define MAXN 10010
//#define LOCAL
using namespace std;

void findLRroot(int &l, int &r, char* str, int start)
{
    l=r=0;
    int upper=0;
    int lower=0;
    //Find Root of Right Child Tree
    for(int i=start-1; i>=0; i--)
    {
        if(str[i]>='A'&&str[i]<='Z')
        {
            upper++;
        }
        else
        {
            lower++;
        }
        if(upper+1==lower)
        {
            r = i+upper+lower-1; //Right Root
            start = i;
            break;
        }
    }
    //Find Root of Left Child Tree
    upper=lower=0;
    for(int i=start-1; i>=0; i--)
    {
        if(str[i]>='A'&&str[i]<='Z')
        {
            upper++;
        }
        else
        {
            lower++;
        }
        if(upper+1==lower)
        {
            l = i+upper+lower-1;
            break;
        }
    }
}

int main()
{
    int n,l,r;
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    scanf("%d",&n);
    char buf[MAXN];
    char ans[MAXN];
    int index[MAXN];
    while(n--)
    {
        memset(buf,'\0',sizeof(buf));
        memset(ans,'\0',sizeof(ans));
        memset(index,0,sizeof(index));
        scanf("%s",buf);
        int len = strlen(buf);
        int que = len-1;
        ans[len]='\0';
        if(len>0)
        {
            ans[que]=buf[len-1];
            index[que] = len-1;
            for(int i=len-1; i>=0; i--)
            {
                if(ans[i]>='A'&&ans[i]<='Z')
                {
                    findLRroot(l,r,buf,index[i]);

                    ans[--que]=buf[l];
                    index[que]=l;

                    ans[--que]=buf[r];
                    index[que]=r;
                }
            }
            printf("%s\n",ans);
        }
        else
        {
            printf("\n");
        }
    }
    return 0;
}
