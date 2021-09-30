#include<stdio.h>
#include<string.h>
//#define LOCAL

int main()
{
    int T;
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    scanf("%d",&T);
    getchar();
    char buf[150];
    char temp[150];
    while(T--)
    {
        memset(buf,'\0',sizeof(buf));
        memset(temp,'\0',sizeof(temp));
        int top=0;
        int flag=0;
        fgets(buf,sizeof(buf),stdin);
        for(int i=0; buf[i]!='\n'; i++)
        {
            if(buf[i]=='('||buf[i]=='[')
            {
                temp[++top]=buf[i];
            }
            else
            {
                if(top==0)
                {
                    flag=1;
                    break;
                }
                else if((temp[top]=='('&&buf[i]==')')||(temp[top]=='['&&buf[i]==']'))
                {
                    top--;
                }
                else
                {
                    break;
                }
            }
        }
        if(top==0&&flag==0)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
