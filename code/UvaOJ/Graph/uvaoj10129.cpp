#include<stdio.h>
#include<string.h>
#define MAXN 2000
//#define LOCAL

int t;
char buf[MAXN];
int n;

bool G[30][30];
bool exist[30];
int difference[30];
bool visit[30];

void Process(char* word);
bool MatchCondition();
int Search(int pos);

int main()
{
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    scanf("%d",&t);
    while(t--)
    {
        memset(G,false,sizeof(G));
        memset(exist,false,sizeof(exist));
        memset(visit,false,sizeof(visit));
        memset(difference,0,sizeof(difference));
        scanf("%d",&n);
        getchar();
        while(n--)
        {
            gets(buf);
            Process(buf);
        }
        int num_letter=0;
        for(int i=0; i<26; i++)
        {
            if(exist[i])
            {
                num_letter++;
            }
        }
        bool can_order = MatchCondition();
        if(can_order)
        {
            for(int i=0; i<26; i++)
            {
                if(exist[i])
                {
                    if(num_letter!=Search(i))
                    {
                        can_order=false;
                    }
                    break;
                }
            }
        }
        printf("%s\n",can_order?"Ordering is possible.":"The door cannot be opened.");
    }
    return 0;
}

void Process(char* word)
{
    int first = word[0]-'a';
    int last = word[strlen(word)-1]-'a';
    ++difference[first];
    --difference[last];
    G[first][last] = true;
    G[last][first] = true;
    exist[first] = true;
    exist[last] =true;
}

bool MatchCondition()
{
    int num_odd=0;
    int num[26];
    for(int i=0; i<26; i++)
    {
        if(difference[i])
        {
            num[num_odd++] = difference[i];
        }
    }
    if(num_odd==0)
    {
        return true;
    }
    if(num_odd!=2)
    {
        return false;
    }
    if((num[0]==-1&&num[1]==1)||(num[0]==1&&num[1]==-1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Search(int pos)
{
    if(visit[pos])
    {
        return 0;
    }
    visit[pos]=1;
    int sum =1;
    for(int i=0; i<26; i++)
    {
        if(G[pos][i])
        {
            sum+=Search(i);
        }
    }
    return sum;
}

