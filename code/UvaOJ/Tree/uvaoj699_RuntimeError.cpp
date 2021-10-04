#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define MAXN 1000
//#define LOCAL
using namespace std;

char buf[MAXN];
int nodes[MAXN];
int answers[MAXN];

typedef struct TNode
{
    int location;
    int value;
    TNode *left, *right;
} Node;

Node* newnode()
{
    Node* u = (Node*)malloc(sizeof(Node));
    if(u!=NULL)
    {
        u->right=u->left=NULL;
    }
    return u;
}

Node* buildtree(Node* node, int* nodes, int &index, int location, int &most_left, int &most_right)
{
    if(node==NULL&&nodes[index]!=-1)
    {
        node = newnode();
        node->value = nodes[index++];
        node->location = location;
//        printf("Created a Note at %d, Value=%d\n",location,node->value);
        if(location<=0)
        {
            most_left = min(most_left,location);
        }
        if(location>=0)
        {
            most_right = max(most_right,location);
        }
        if(node->left==NULL)
        {
            node->left = buildtree(node->left,nodes,index,location-1,most_left,most_right);
        }
        if(node->right==NULL)
        {
            node->right = buildtree(node->right,nodes,index,location+1,most_left,most_right);
        }
    }
    else
    {
        index++;
//        printf("No Child\n");
        return NULL;
    }
}

void remove(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    remove(root->left);
    remove(root->right);
    free(root);
}

void DFS(Node* node, int* answers, int bias)
{
    if(node==NULL)
    {
        return;
    }
    answers[node->location+bias]+=node->value;
    if(node->left!=NULL)
    {
        DFS(node->left,answers,bias);
    }
    if(node->right!=NULL)
    {
        DFS(node->right,answers,bias);
    }
}

int main()
{
    char c;
    int value;
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    memset(buf,'\0',sizeof(buf));
    memset(nodes,-1,sizeof(nodes));
    memset(answers,0,sizeof(answers));
    int kase=1;
    while(fgets(buf,sizeof(buf),stdin))
    {
        if(strlen(buf)==3)
        {
            break;
        }
        char* p = buf;
        int n;
        int i=0;
        int flag=0;
        while(true)
        {
            while(sscanf(p,"%d%n",&nodes[i++],&n)==1)
            {
                if(i==1)
                {
                    flag+=2;
                }
                else
                {
                    if(nodes[i-1]>0)
                    {
                        flag=flag-1+2;
                    }
                    else
                    {
                        flag-=1;
                    }
                }
                p+=n;
            }
            if(flag==0)
            {
                break;
            }
            memset(buf,'\0',sizeof(buf));
            fgets(buf,sizeof(buf),stdin);
            p = buf;
            i=i-1;
        }
//        for(int j=0;j<i;j++){
//            printf("%d ",nodes[j]);
//        }
//        printf("\nCase %d:\n",kase++);

        printf("Case %d:\n",kase++);
        Node* root = NULL;
        int most_left = 0;
        int most_right = 0;
        int location = 0;
        int count=0;
        int index=0;
        root = buildtree(root,nodes,index,location,most_left,most_right);
        DFS(root,answers,most_left*-1);
        count = most_right-most_left;
        for(int i=0; i<count; i++)
        {
            printf("%d ",answers[i]);
        }
        printf("%d\n\n",answers[count]);
        memset(buf,'\0',sizeof(buf));
        memset(nodes,0,sizeof(nodes));
        memset(answers,0,sizeof(answers));
        remove(root);
    }
    return 0;
}
