#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAXN 20000
//#define LOCAL
using namespace std;

typedef struct TNode
{
    int color;
    int depth;
    TNode *child[4];
} Node;

Node* newnode()
{
    Node* u = (Node*)malloc(sizeof(Node));
    if(u!=NULL)
    {
        for(int i=0; i<4; i++)
        {
            u->child[i]=NULL;
        }
    }
    return u;
}

Node* buildtree(Node* node,char* str,int d, int &id)
{
    if(id==strlen(str))
    {
        return NULL;
    }

    char c = str[id++];

    if(node==NULL)
    {
        node = newnode();
        node->depth = d;
    }

    if(c=='p')
    {
        for(int i=0; i<4; i++)
        {
            node->child[i]=buildtree(node->child[i],str,d+1,id);
        }
    }
    else if(c=='f')
    {
        node->color = 1;
    }
    return node;
}

void DFS(Node* tree, int &sum)
{
    if(tree->color==1)
    {
        sum+=1024/pow(4,tree->depth);
    }
    else if(tree->child[0]!=NULL)
    {
        for(int i=0; i<4; i++)
        {
            DFS(tree->child[i],sum);
        }
    }
}

int main()
{
    int n;
    char buf[MAXN];
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    scanf("%d",&n);
    while(n--)
    {
        memset(buf,'\0',sizeof(buf));
        scanf("%s",buf);
        int depth=0;
        int index=0;
        Node* root = NULL;
        root = buildtree(root,buf,depth,index);
        memset(buf,'\0',sizeof(buf));
        scanf("%s",buf);
        index = 0;
        root = buildtree(root,buf,depth,index);
        int ans=0;
        DFS(root,ans);
        printf("There are %d black pixels.\n",ans);
    }
    return 0;
}
