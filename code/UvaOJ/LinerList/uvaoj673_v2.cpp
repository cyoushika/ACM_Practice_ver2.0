#include<stdio.h>
#include<string.h>
#include<stack>
//#define LOCAL
using namespace std;

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
    while(T--)
    {
        stack<char> s;
        int flag=0;
        memset(buf,'\0',sizeof(buf));
        fgets(buf,sizeof(buf),stdin);
        int len = strlen(buf);
        for(int i=0; buf[i]!='\n'; i++)
        {
            if(buf[i]=='('||buf[i]=='[')
            {
                s.push(buf[i]);
            }
            else
            {
                if(s.empty())
                {
                    flag=1;
                    break;
                }
                else if((s.top()=='('&&buf[i]==')')||(s.top()=='['&&buf[i]==']'))
                {
                    s.pop();
                }
                else
                {
                    break;
                }
            }
        }
        if(s.empty()&&flag==0) printf("Yes\n");
        else printf("No\n");
        while(!s.empty()){
            s.pop();
        }
    }
    return 0;
}
