#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define LOCAL
using namespace std;

bool isEqual;

typedef struct TNode
{
    int weight;
    TNode *left, *right;
} Node;

Node* newnode()
{
    Node *u = (Node*)malloc(sizeof(Node));
    if(u!=NULL)
    {
        u->left=u->right=NULL;
        u->weight=0;
    }
    return u;
}

Node* buildtree(Node* node)
{
    int wl,dl,wr,dr;
    scanf("%d%d%d%d",&wl,&dl,&wr,&dr);
    node = newnode();
    if(wl==0)
    {
        node->left = buildtree(node->left);
        wl=node->left->weight;
    }
    if(wr==0)
    {
        node->right = buildtree(node->right);
        wr=node->right->weight;
    }
    if(wl*dl!=wr*dr)
    {
        isEqual=false;
    }
    node->weight = wl+wr;
    return node;
}

int Mobile()
{
    int wl,dl,wr,dr;
    scanf("%d%d%d%d",&wl,&dl,&wr,&dr);
    wl = wl==0?Mobile():wl;
    wr = wr==0?Mobile():wr;
    if(wl*dl!=wr*dr)
    {
        isEqual=false;
    }
    return wl+wr;
}

int main()
{
    int n;
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    scanf("%d",&n);
    int kase = 0;
    while(n--)
    {
        Node* root = NULL;
        isEqual=true;
        root = buildtree(root);
//        Mobile();
        if(isEqual)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        if(n!=0)
        {
            printf("\n");
        }
    }
    return 0;
}


