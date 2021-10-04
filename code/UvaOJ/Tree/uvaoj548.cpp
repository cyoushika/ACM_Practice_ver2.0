#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<algorithm>
#define MAXN 10010
//#define LOCAL
using namespace std;

struct Path{
    int sum;
    int node;
    Path(){
        sum=0;
        node=0;
    }

    bool operator < (const Path& p) const{
        if(sum==p.sum){
            return node < p.node;
        }
        else{
            return sum<p.sum;
        }
    }
};

int minimum = 10010;
int path_num = 0;
Path paths[MAXN];

void findLRleaf(int p, int l, int r, int sum, int* in, int* post, int* index)
{
    int root = post[p];
//    printf("Root=%d, ",root);
    sum+=root;
    int rid = (l+r)/2;
    bool visit_l=true, visit_r=true;
    if(in[rid]==root)
    {
        index[rid]=1;
    }
    else
    {
        int i = rid-1;
        int j = rid+1;
        int found = 0;
        while(i>=l)
        {
            if(in[i]==root)
            {
                index[i]=1;
                found=1;
                rid=i;
                break;
            }
            i--;
        }
        while(j<=r&&found==0)
        {
            if(in[j]==root)
            {
                index[j]=1;
                found=1;
                rid = j;
                break;
            }
            j++;
        }
    }
//    printf("Rid=%d\n",rid);
    if(rid-1>=l&&index[rid-1]==0)
    {
        visit_l=false;
//        printf("Left Unvisit!\n");
    }
    if(rid+1<=r&&index[rid+1]==0)
    {
        visit_r=false;
//        printf("Right Unvisit!\n");
    }
    if(visit_l&&visit_r)
    {
        paths[path_num].node = root;
        paths[path_num].sum = sum;
        path_num++;
        return;
    }
    else if(visit_l)
    {
        findLRleaf(p-1,rid+1,r,sum,in,post,index);
    }
    else if(visit_r)
    {
        int len_right = r-rid;
        findLRleaf(p-len_right-1,l,rid-1,sum,in,post,index);
    }
    else
    {
        int len_right = r-rid;
        findLRleaf(p-1,rid+1,r,sum,in,post,index);
        findLRleaf(p-len_right-1,l,rid-1,sum,in,post,index);
    }
}

int main()
{
#ifdef LOCAL
    freopen("C:\\Users\\cyous\\ACM\\input.txt","r",stdin);
    freopen("C:\\Users\\cyous\\ACM\\output.txt","w",stdout);
#endif // LOCAL
    int inorder[MAXN];
    int postorder[MAXN];
    int index[MAXN];
    char c;
    int temp=0;
    int n=0;
    int len=0;
    int flag=0;
    memset(inorder,0,sizeof(inorder));
    memset(postorder,0,sizeof(postorder));
    memset(index,0,sizeof(index));
    while((c=getchar())!=EOF)
    {
        if(isdigit(c))
        {
            temp = temp*10+c-'0';
            while(isdigit(c=getchar()))
            {
                temp = temp*10+c-'0';
            }
            if(flag==0)
            {
                inorder[n++]=temp;
            }
            else
            {
                postorder[n++]=temp;
            }
            if(c=='\n'&&flag==0)
            {
                flag=1;
                len=n;
                n=0;
            }
            else if(c=='\n'&&flag==1)
            {
                findLRleaf(len-1,0,len-1,0,inorder,postorder,index);
                sort(paths,paths+path_num);
                printf("%d\n",paths[0].node);
                n=0;
                flag=0;

//                for(int i=0;i<len;i++){
//                    printf("%d ",inorder[i]);
//                }
//                printf("\n");
//                for(int i=0;i<len;i++){
//                    printf("%d ",postorder[i]);
//                }
//                printf("\n");

                memset(inorder,0,sizeof(inorder));
                memset(postorder,0,sizeof(postorder));
                memset(index,0,sizeof(index));
                minimum = 10010;
                path_num = 0;
            }
            temp=0;
        }
    }
    return 0;
}
