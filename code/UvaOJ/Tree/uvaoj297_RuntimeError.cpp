#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#define MAXN 1100
//#define LOCAL
using namespace std;

char buf[MAXN];

typedef struct TNode
{
    int depth;
    int id;
    int value;
    TNode *father, *left1,*left2, *right1, *right2;
    TNode()
    {
        father=left1=left2=right1=right2=NULL;
    }
} Node;

Node* newnode()
{
    Node* u = (Node*)malloc(sizeof(Node));
    if(u!=NULL)
    {
        u->father = u->left1 = u->left2 = u->right1 = u->right2 = NULL;
    }
//    else{
//        printf("can not create a mode");
//    }
    return u;
}

void remove_tree(Node* u)
{
    if(u==NULL)
    {
        return;
    }
    remove_tree(u->left1);
    remove_tree(u->left2);
    remove_tree(u->right1);
    remove_tree(u->right2);
    free(u);
}

int single_calculate(Node* tree,int sum)
{
    Node* p = tree;
    if(p->value == -1)
    {
        sum += single_calculate(p->left1,sum)+single_calculate(p->left2,sum)+single_calculate(p->right1,sum)+single_calculate(p->right2,sum);
    }
    else if(p->value==0)
    {
        sum+=0;
    }
    else if(p->value==1)
    {
        sum+=(1024/pow(4,p->depth));
    }
    return sum;
}

int calculate_blacks(Node* tree1, Node* tree2)
{
    Node *p1, *p2;
    p1 = tree1;
    p2 = tree2;
    if(p1->value==-1&&p2->value==-1)
    {
        return calculate_blacks(p1->left1,p2->left1)+calculate_blacks(p1->left2,p2->left2)+calculate_blacks(p1->right1,p2->right1)+calculate_blacks(p1->right2,p2->right2);
    }
    else if(p1->value==-1&&p2->value==0)
    {
        return single_calculate(p1,0);
    }
    else if(p1->value==0&&p2->value==-1)
    {
        return single_calculate(p2,0);
    }
    else if(p1->value==0&&p2->value==0)
    {
        return 0;
    }
    else if(p1->value==1||p2->value==1)
    {
        return 1024/pow(4,p1->depth);
    }
}



int main()
{
    int n;
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    scanf("%d",&n);
//    getchar();
    while(n--)
    {
        Node *root1, *root2, *current, *temp;
        root1 = root2 = current = NULL;
        for(int t=0; t<2; t++)
        {
            memset(buf,'\0',sizeof(buf));
            scanf("%s",buf);
            int len = strlen(buf);
            int depth=0;
            for(int i=0; i<len; i++)
            {
                temp = newnode();
                temp->depth = depth;
                if(current==NULL)
                {
                    current = temp;
                    if(root1==NULL&&t==0)
                    {
                        root1=temp;
//                        printf("Create Root 1, ");
                    }
                    else if(root2==NULL&&t==1)
                    {
                        root2=temp;
//                        printf("Create Root 2, ");
                    }
                    if(buf[i]=='p')
                    {
                        temp->value = -1;
//                        printf("The Node is p\n");
                    }
                    else if(buf[i]=='f')
                    {
                        temp->value = 1;
//                        printf("The Node is f\n");
                    }
                    else if(buf[i]=='e')
                    {
                        temp->value = 0;
//                        printf("The Node is e\n");
                    }
                }
                else
                {
                    if(current->left1==NULL)
                    {
                        current->left1 = temp;
//                        printf("Add Note to Left 1, ");
                    }
                    else if(current->left2==NULL)
                    {
                        current->left2 = temp;
//                        printf("Add Note to Left 2, ");
                    }
                    else if(current->right1==NULL)
                    {
                        current->right1 = temp;
//                        printf("Add Note to Right 1, ");
                    }
                    else if(current->right2==NULL)
                    {
                        current->right2 = temp;
//                        printf("Add Note to Right 2, ");
                    }
                    temp->father = current;
                    temp->depth = depth+1;

                    if(buf[i]=='p')
                    {
                        temp->value = -1;
                        current = temp;
                        depth++;
//                        printf("The Node is p\n");
                    }
                    else if(buf[i]=='f')
                    {
                        temp->value = 1;
//                        printf("The Node is f\n");
                    }
                    else if(buf[i]=='e')
                    {
                        temp->value = 0;
//                        printf("The Node is e\n");
                    }

                    while(current&&current->right2)
                    {
                        current = current->father;
                        depth--;
                    }
                }
            }
        }
        printf("There are %d black pixels.\n",calculate_blacks(root1, root2));
        remove_tree(root1);
        remove_tree(root2);
    }
    return 0;
}


