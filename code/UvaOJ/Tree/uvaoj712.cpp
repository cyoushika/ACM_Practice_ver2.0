#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define LOCAL
using namespace std;

typedef struct TNode
{
    int id;
    int value;
    int depth;
    TNode *left,*right;
} Node;

Node* newnode()
{
    Node* u = (Node*)malloc(sizeof(Node));
    if(u!=NULL)
    {
        u->left=u->right=NULL;
        u->value = -99;
    }
    return u;
}

Node* buildtree(Node* node, int depth, int &leaf_id, int max_depth,int* order, char* leaf)
{
    if(depth==max_depth)
    {
        node=newnode();
        node->value = leaf[leaf_id++]-'0';
        node->left = node->right = NULL;
        node->depth = max_depth;
//        printf("Depth=%d\n",depth);
//        printf("Leaf Node: %d\n",node->value);
        return node;
    }
    else
    {
        if(node==NULL)
        {
            node=newnode();
            node->id = order[depth];
            node->depth = depth;
//            printf("Depth=%d\n",depth);
        }
        if(node->left==NULL)
        {
            node->left = buildtree(node->left,depth+1,leaf_id,max_depth,order,leaf);
        }
        if(node->right==NULL)
        {
            node->right = buildtree(node->right,depth+1,leaf_id,max_depth,order,leaf);
        }
    }
    return node;
}

void DFS(Node* node, char* str, int max_depth)
{
    if(node->depth==max_depth)
    {
        printf("%d",node->value);
        return;
    }
    else
    {
        if(str[node->id-1]=='0')
        {
            DFS(node->left,str,max_depth);
        }
        else
        {
            DFS(node->right,str,max_depth);
        }
    }
}

void remove(Node* tree)
{
    if(tree==NULL)
    {
        return;
    }
    remove(tree->left);
    remove(tree->right);
    free(tree);
}

int main()
{
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    int n;
    int order[10];
    char leaf[200];
    char buf[10];
    int K = 0;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        char c;
        int id=0;
        K++;
        printf("S-Tree #%d:\n",K);
        memset(order,0,sizeof(order));
        memset(buf,'\0',sizeof(buf));
        memset(leaf,'\0',sizeof(leaf));
        getchar();
        while((c=getchar())!='\n')
        {
            if(c=='x')
            {
                c=getchar();
                order[id++]=c-'0';
//                printf("c=%d\n",c-'0');
            }
        }

        scanf("%s",leaf);
        int index=0;
        Node* root = NULL;
        root = buildtree(root,0,index,n,order,leaf);
        int kase;
        scanf("%d",&kase);
        for(int i=0; i<kase; i++)
        {
            scanf("%s",buf);
            DFS(root,buf,n);
        }
        printf("\n\n");
        remove(root);
    }
    return 0;
}
