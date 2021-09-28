#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
// #define LOCAL
#define MAXN 100010

char dic[MAXN][100];
// int counter[MAXN];

const char pTable[] = {
	'2', '2', '2', '3', '3', '3',
	'4', '4', '4', '5', '5', '5',
	'6', '6', '6', '7', '*', '7',
	'7', '8', '8', '8', '9', '9',
	'9', '*' };

int cmp_string(const void* _a, const void* _b){
  char* a = (char*) _a;
  char* b = (char*) _b;
  return strcmp(a,b);
}

int main(){
  int t;
  int n;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  scanf("%d",&t);
  char temp[100];
  while(t--){
    memset(dic,0,sizeof(dic));
    // memset(counter,0,sizeof(counter));

    scanf("%d",&n);
    int pointer=0;
    for(int i=0;i<n;i++){
      scanf("%s",temp);
      char buf[10];
      int count=0;
      for(int j=0;j<strlen(temp);j++){
        if(isalpha(temp[j])){
          buf[count++]=pTable[temp[j]-'A'];
          if(count==3){
            buf[count++]='-';
          }
        }
        else if(isdigit(temp[j])){
          buf[count++]=temp[j];
          if(count==3){
            buf[count++]='-';
          }
        }
      }
      strcpy(dic[i],buf);
      // printf("%s -> %s\n",temp,buf);
    }
    qsort(dic,n,sizeof(dic[0]),cmp_string);
    int flag=1;
    for(int i=0;i<n;i++){
      int count=1;
      int j=1;
      while(i+1<n&&strcmp(dic[i+1],dic[i])==0){
        count++;
        flag=0;
        i++;
      }
      if(count>1){
        printf("%s %d\n",dic[i],count);
      }
    }
    if(flag){
      printf("No duplicates.\n");
    }
    if(t>0){
      printf("\n");
    }
  }
  return 0;
}

// int qsearch(char a[MAXN][100],int l, int r, char* target){
//   if(l<r){
//     int m = (l+r)/2;
//     char* temp = a[m];
//     int flag = strcmp(temp,target);
//     if(flag>0){
//       return qsearch(a,l,m-1,target);
//     }
//     else if(flag<0){
//       return qsearch(a,m+1,r,target);
//     }
//     else{
//       return m;
//     }
//   }
//   else if(l==r){
//     char* temp = a[l];
//     int flag = strcmp(temp,target);
//     if(flag==0){
//       return l;
//     }
//     else{
//       return -1;
//     }
//   }
//   return -1;
// }

// void qsort(char a[MAXN][100], int* b,int l,int r){
//   int m=(l+r)/2;
//   char mid[MAXN];
//   strcpy(mid,a[m]);
//
//   int i=l, j=r;
//   char temp[MAXN];
//   int gtemp=0;
//
//   while(i<=j){
//     while(strcmp(a[i],mid)<0) i++;
//     while(strcmp(a[j],mid)>0) j--;
//     if(i<=j){
//       strcpy(temp,a[i]);
//       strcpy(a[i],a[j]);
//       strcpy(a[j],temp);
//
//       gtemp=b[i];
//       b[i]=b[j];
//       b[j]=gtemp;
//
//       i++;
//       j--;
//     }
//   }
//   if(i<r) qsort(a,b,i,r);
//   if(j>l) qsort(a,b,l,j);
//   return;
// }
