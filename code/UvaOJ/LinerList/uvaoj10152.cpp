#include<stdio.h>
#include<string.h>
//#define LOCAL

struct Turtle
{
    char name[85];
    int sorted;

    Turtle()
    {
        sorted=0;
    }
};

int main()
{
    int T,n;
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    scanf("%d",&T);
    while(T--)
    {
        Turtle turtles[210];
        Turtle sorted[210];
        scanf("%d",&n);
        getchar();
        for(int i=0; i<n; i++)
        {
            fgets(turtles[i].name,85,stdin);
            turtles[i].sorted=0;
        }
        for(int i=0; i<n; i++)
        {
            fgets(sorted[i].name,85,stdin);
            turtles[i].sorted=0;
        }
        for(int i=n-1,j=n-1; i>=0; i--)
        {
            if(!strcmp(turtles[i].name,sorted[j].name))
            {
                sorted[j].sorted=1;
                j--;
            }
        }
        for(int i=n-1; i>=0; i--)
        {
            if(!sorted[i].sorted)
            {
                printf("%s",sorted[i].name);
            }
        }
        printf("\n");
    }
    return 0;
}



