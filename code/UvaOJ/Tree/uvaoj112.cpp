#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stack>
#include<ctype.h>
#define MAXN 50000
#define Min -99999999
//#define LOCAL
using namespace std;

typedef struct TNode
{
    int value;
    struct TNode *left, *right, *father;
} Node;

Node* root;
Node* current;
Node* fake;

Node* newnode()
{
    Node* u = (Node*) malloc(sizeof(Node));
    if(u!=NULL)
    {
        u->left = u->right = u->father = NULL;
    }
    return u;
}

void remove_tree(Node* u)
{
//    printf("Removing...\n");
    if(u==NULL) return;
    remove_tree(u->left);
    remove_tree(u->right);
    free(u);
}

bool DFS(Node* u, int sum, int target)
{
    if(u==NULL) return false;
    sum+=u->value;
    if(u->left==NULL&&u->right==NULL)
    {
        if(sum==target)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return DFS(u->left,sum,target)||DFS(u->right,sum,target);
    }
}

int main()
{
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    int target;
    stack<char> m;
    int count;
    char c;
    int cmark;
    int temp;
    char buf[MAXN];
    while(scanf("%d",&target)!=EOF)
    {
        count = 0;
        cmark = 1;
        temp = 0;
        memset(buf,'\0',sizeof(buf));
        root = NULL;
        while((c=getchar())!=EOF)
        {
            if(c=='(')
            {
                m.push(c);
                buf[count++]=c;
            }
            else if(c==')')
            {
                m.pop();
                buf[count++]=c;
                if(m.empty())
                {
                    break;
                }
            }
            else if(isdigit(c)||c=='-')
            {
                buf[count++]=c;
            }
        }
        if(count==2)
        {
            printf("no\n");
        }
        else
        {
//            printf("%s\n",buf);
            for(int i=0; i<count; i++)
            {
                if(buf[i]=='-')
                {
                    cmark=-1;
                }
                else if(isdigit(buf[i]))
                {
                    temp = temp*10+buf[i]-'0';
                    while(isdigit(buf[i+1]))
                    {
                        i++;
                        temp = temp*10+buf[i]-'0';
                    }
                    temp = temp*cmark;
                    fake = newnode();
                    if(root==NULL)
                    {
                        root = fake;
                        current = fake;
                        root->value = temp;
//                        printf("Root Value=%d\n",temp);
                    }
                    else
                    {
                        if(current->left==NULL)
                        {
                            current->left = fake;
                            current->left->value = temp;
                            current->left->father = current;
                            current = current->left;
//                            printf("Node Value=%d\n",temp);
                        }
                        else if(current->right==NULL)
                        {
                            current->right = fake;
                            current->right->value = temp;
                            current->right->father = current;
                            current = current->right;
//                            printf("Node Value=%d\n",temp);
                        }
                    }
                    temp=0;
                    cmark=1;
                }
                else if(buf[i]=='('&&buf[i+1]==')')
                {
//                    printf("Reached the Leaf Node\n");
                    i++;
                }
                else if(buf[i]==')')
                {
                    current = current->father;
//                    if(current!=NULL)
//                    {
//                        printf("Back to Father Node=%d\n",current->value);
//                    }
//                    else
//                    {
//                        printf("Reached The Root\n");
//                    }
                }
            }
            if(DFS(root,0,target))
            {
                printf("yes\n");
            }
            else
            {
                printf("no\n");
            }
            remove_tree(root);
        }
    }
    return 0;
}
