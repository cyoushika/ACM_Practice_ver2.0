#include<stdio.h>
#include<string.h>
//#define LOCAL

struct Node
{
    int value;
    Node* left;
    Node* right;
    Node() {};
    Node(int v)
    {
        value=v;
        left=NULL;
        right=NULL;
    }
};

int N=20;

void del(Node* n)
{
    if(n->right)
    {
        n->right->left = n->left;
    }
    if(n->left)
    {
        n->left->right = n->right;
    }
    N--;
    delete n;
}

int main()
{
    int k,m;
    Node* head=NULL;
    Node* tail=NULL;
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif
    while(true)
    {
        scanf("%d%d%d",&N,&k,&m);
        Node* current=NULL;
        if(N==0&&k==0&&m==0)
        {
            break;
        }
        for(int i=1; i<=N; i++)
        {
            Node* n = new Node(i);
            if(i==1)
            {
                head = n;
            }
            if(i==N)
            {
                tail = n;
            }
            if(current)
            {
                current->right=n;
                n->left = current;
            }
            current = n;
        }
        tail->right = head;
        head->left = tail;
        Node* first = head;
        Node* second = tail;
        while(N>0)
        {
            for(int i=1; i<k; i++)
            {
                first = first->right;
            }
            for(int i=1; i<m; i++)
            {
                second = second->left;
            }
            if(first->value==second->value)
            {
                printf("%3d",first->value);
                Node* temp = first;
                first = first->right;
                second = second->left;
                del(temp);
            }
            else
            {
                printf("%3d%3d",first->value,second->value);
                Node* temp = first;
                Node* temp2 = second;
                do
                {
                    first = first->right;
                }
                while(first->value==temp2->value&&N>2);

                do
                {
                    second = second->left;
                }
                while(second->value==temp->value&&N>2);
                del(temp);
                del(temp2);
            }
            if(N>0)
            {
                printf(",");
            }
        }
        printf("\n");
    }
    return 0;
}
