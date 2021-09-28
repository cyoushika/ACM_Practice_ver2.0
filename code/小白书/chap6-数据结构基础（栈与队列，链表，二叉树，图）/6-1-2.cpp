#include<stdio.h>
#include<stack>
using namespace std;
#define LOCAL
const int MAXN = 1000+10;
int n, target[MAXN];

int main(){
  #ifdef LOCAL
    freopen("/Users/zhangzhihua/Desktop/project/ACM_Practice/code/input.txt","r",stdin);
    freopen("/Users/zhangzhihua/Desktop/project/ACM_Practice/code/output.txt","w",stdout);
  #endif

  while(scanf("%d",&n)==1){
    stack<int> s;
    int A=1,B=1;
    for(int i=1;i<=n;i++){
      scanf("%d",&target[i]);
    }
    int ok=1;
    while(B<=n){
      if(A==target[B]){
        A++;
        B++;
      }
      else if(!s.empty()&&s.top()==target[B]){
        s.pop();
        B++;
      }
      else if(A<=n){
        s.push(A++);
      }
      else{
        ok=0;
        break;
      }
    }
    printf("%s\n",ok?"Yes":"No");
  }
  return 0;
}
// int main(){
//   #ifdef LOCAL
//   freopen("/Users/zhangzhihua/Desktop/project/ACM_Practice/code/input.txt","r",stdin);
//   freopen("/Users/zhangzhihua/Desktop/project/ACM_Practice/code/output.txt","w",stdout);
//   #endif
//
//   while(scanf("%d",&n)==1){
//     // printf("%d",n);
//     int stack[MAXN],top=0;
//     int A=1, B=1;
//     for(int i=1;i<=n;i++){
//       scanf("%d",&target[i]);
//     }
//     int ok=1;
//     while(B<=n){
//       if(A==target[B]){
//         A++;
//         B++;
//       }
//       else if(top&&stack[top]==target[B]){
//         top--;
//         B++;
//       }
//       else if(A<=n){
//         stack[++top]=A++;
//       }
//       else{
//         ok=0;
//         break;
//       }
//     }
//     printf("%s\n",ok?"Yes":"No");
//   }
//   return 0;
// }
