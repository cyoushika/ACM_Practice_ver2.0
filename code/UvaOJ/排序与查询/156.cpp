#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
// #define LOCAL
#define MAXN 1010

char dic[MAXN][30];
char sorted[MAXN][30];
char result[MAXN][30];

int cmp_char(const void* _a, const void* _b){
    char* a = (char*) _a;
    char* b = (char*) _b;
    return *a-*b;
}

int cmp_string(const void* _a, const void* _b){
  char* a = (char*) _a;
  char* b = (char*) _b;
  return strcmp(a,b);
}

int main(){
  char c;
  int count=0;
  int num=0;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while((c=getchar())!='#'){
    if(isalpha(c)){
      dic[num][count]=c;
      sorted[num][count++]=toupper(c);
    }
    else if(c=='\n'||c==' '){
      if(count!=0){
        dic[num][count]='\0';
        sorted[num][count]='\0';
        qsort(sorted[num],count,sizeof(sorted[0][0]),cmp_char);
        // printf("%s -> %s\n",dic[num],sorted[num]);
        num++;
        count=0;
      }
    }
  }
  if(count!=0){
    dic[num][count]='\0';
    sorted[num][count]='\0';
    qsort(sorted[num],count,sizeof(sorted[0][0]),cmp_char);
    // printf("%s -> %s\n",dic[num],sorted[num]);
    num++;
    count=0;
  }
  int ans=0;
  for(int i=0;i<num;i++){
    int flag=1;
    for(int j=0;j<num;j++){
      // printf("%s vs %s\n",sorted[i],sorted[j]);
      if(i!=j&&strcmp(sorted[i],sorted[j])==0){
        flag=0;
        break;
      }
    }
    if(flag){
      strcpy(result[ans],dic[i]);
      ans++;
    }
  }
  qsort(result,ans,sizeof(result[0]),cmp_string);
  for(int i=0;i<ans;i++){
    printf("%s\n",result[i]);
  }
  return 0;
}
