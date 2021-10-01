#include<stdio.h>
#include<stack>
#include<string.h>
#include<ctype.h>
#define MAXN 30
//#define LOCAL
using namespace std;

struct Matrix
{
    int row;
    int column;
} m[MAXN];

int main()
{
    int n;
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    scanf("%d",&n);
//    printf("N = %d\n",n);
    getchar();
    int row,column;
    char id;
    for(int i=0; i<n; i++)
    {
        scanf("%c",&id);
        scanf("%d%d",&row,&column);
//        scanf("%c %d %d",&id,&row,&column);
        getchar();
        m[id-'A'].row=row;
        m[id-'A'].column=column;
    }
    stack<Matrix> M;
    char buf[1000];
    while(scanf("%s",buf)!=EOF)
    {
        int len = strlen(buf);
        int count = 0;
        int flag = 0;
        if(len==1)
        {
            printf("0\n");
        }
        else
        {
            for(int i=0; i<len; i++)
            {
                if(isalpha(buf[i]))
                {
                    M.push(m[buf[i]-'A']);
                }
                else if(buf[i]==')')
                {
                    Matrix second = M.top();
                    M.pop();
                    Matrix first = M.top();
                    M.pop();
                    if(first.column!=second.row)
                    {
                        flag = 1;
                        printf("error\n");
                        break;
                    }
                    else
                    {
                        count+=first.row*first.column*second.column;
                        Matrix temp;
                        temp.row = first.row;
                        temp.column = second.column;
                        M.push(temp);
                    }
                }
            }
            if(flag==0)
            {
                printf("%d\n",count);
            }
            while(!M.empty()) M.pop();
        }
    }
    return 0;
}
