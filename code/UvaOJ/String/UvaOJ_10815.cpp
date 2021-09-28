#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAXN 5010
// #define LOCAL

char word[MAXN][210];
char temp[210];

int cmp_string(const void* _a, const void* _b){
  char* a = (char*) _a;
  char* b = (char*) _b;
  return strcmp(a,b);
}

int main(){
  int pointer = 0;
  char c;
  int count=0;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while((c=getchar())!=EOF){
    if(isalpha(c)){
      temp[count++]=tolower(c);
      // printf("%c",c);
    }
    else if(count!=0){
      // printf("%s\n",temp);
      if(pointer==0){
        strcpy(word[pointer],temp);
        pointer++;
      }
      else{
        int flag=1;
        for(int j=0;j<pointer;j++){
          if(strcmp(temp,word[j])==0){
            flag=0;
          }
        }
        if(flag){
          strcpy(word[pointer],temp);
          pointer++;
        }
      }
      memset(temp,'\0',sizeof(temp));
      count=0;
    }
  }

  qsort(word,pointer,sizeof(word[0]),cmp_string);

  for(int i=0;i<pointer;i++){
    printf("%s\n",word[i]);
  }
  return 0;
}
