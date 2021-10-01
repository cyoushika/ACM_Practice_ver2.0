#include<stdio.h>
#include<string.h>
#include<stack>
#define MAXN 50000
//#define LOCAL
using namespace std;

struct Toy
{
    int size;
    int sub;
    Toy() {};
    Toy(int s)
    {
        size = s;
        sub = 0;
    };
};

char buf[MAXN];
int a[MAXN];
stack<Toy> m;

int main()
{
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    while(fgets(buf,sizeof(buf),stdin)!=NULL)
    {
        char* p;
        p=buf;
        int count = 0;
        int n=0;
        int flag = 0;

        while(sscanf(p,"%d%n",&a[count],&n)==1)
        {
            count++;
            p+=n;
        }
        if(count%2==1)
        {
            printf(":-( Try again.\n");
            memset(buf,'\0',sizeof(buf));
            memset(a,0,sizeof(a));
            continue;
        }
        for(int i=0; i<count; i++)
        {
            if(a[i]<0)
            {
                m.push(Toy(-1*a[i]));
            }
            else
            {
                if(!m.empty())
                {
                    Toy t = m.top();
                    if(t.size==a[i])
                    {
                        if(t.size<=t.sub)
                        {
                            flag=1;
                            break;
                        }
                        m.pop();
                        if(!m.empty())
                        {
                            m.top().sub+=a[i];
                        }
                        else if(i!=count-1)
                        {
                            flag=1;
                            break;
                        }
                    }
                    else
                    {
                        flag=1;
                        break;
                    }
                }
                else
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
        {
            printf(":-( Try again.\n");
        }
        else
        {
            printf(":-) Matrioshka!\n");
        }
        memset(buf,'\0',sizeof(buf));
        memset(a,0,sizeof(a));
        while(!m.empty()){
            m.pop();
        }
    }
    return 0;
}
