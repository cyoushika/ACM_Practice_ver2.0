#include<stdio.h>
#include<string.h>
#define MAXN 53
//#define LOCAL

int count = 52;

struct Card
{
    char card_suit;
    char card_rank;
    Card() {};
    Card(char r,char s)
    {
        card_rank=r;
        card_suit=s;
    }

    int is_same(Card c)
    {
        return (c.card_suit==card_suit||c.card_rank==card_rank);
    }
};

struct Pile
{
    Pile* left;
    Pile* right;
    Card cards[MAXN];
    int top;

    Pile()
    {
        left=right=NULL;
        top=0;
    }

    void add(Card c)
    {
        cards[top++] = c;
    }

    Card pop()
    {
        return cards[--top];
    }

    int is_same(Pile* p)
    {
        return p->cards[p->top-1].is_same(cards[top-1]);
    }

    int is_empty()
    {
        return top==0;
    }
};

void del(Pile* p)
{
    if(p->left)
    {
        p->left->right = p->right;
    }
    if(p->right)
    {
        p->right->left = p->left;
    }
    count--;
    delete p;
}

int move(Pile* from, Pile* to)
{
    to->add(from->pop());
    if(from->is_empty())
    {
        del(from);
    }
    return 0;
}

int main()
{
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    while(true)
    {
        count = 52;
        char buf[3];
        Pile* current=NULL;
        Pile* head=NULL;
        Pile* tail=NULL;
        for(int i=0; i<52; i++)
        {
            scanf("%s",buf);
            if(!strcmp(buf,"#"))
            {
                return 0;
            }
            //printf("%s ",buf);
            Pile* p = new Pile();
            p->add(Card(buf[0],buf[1]));
            if(i==0)
            {
                head = p;
            }
            else if(i==51)
            {
                tail = p;
            }
            if(current)
            {
                current->right = p;
                p->left = current;
            }
            current = p;
        }
        while(true)
        {
            int flag=0;
            int result=0;
            current = head->right;
            for(; current; current=current->right)
            {
                if(current->left&&current->left->left&&current->left->left->left&&current->left->left->left->is_same(current))
                {
                    move(current,current->left->left->left);
                    flag=1;
                    break;
                }
                if(current->left&&current->left->is_same(current))
                {
                    move(current,current->left);
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                break;
            }
        }
        printf("%d pile",count);
        printf(count>1?"s":"");
        printf(" remaining:");
        for(Pile *p=head;p;p=p->right){
            printf(" %d",p->top);
        }
        putchar('\n');
    }
    return 0;
}
