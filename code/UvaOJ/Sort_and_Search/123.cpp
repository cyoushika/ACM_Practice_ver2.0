#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
// #define LOCAL

char ignore[55][15]={""};
char titles[210][310]={""};
typedef struct{
  char keyword[310];
  char title[310];
  int id;
  int pos;
}Key;

Key keys[100010];

int cmp_string(const void* _a, const void* _b){
    char* a = (char*) _a;
    char* b = (char*) _b;
    return strcmp(a,b);
}

int cmp_struct(const void* _a, const void* _b){
  Key a = *(Key*) _a;
  Key b = *(Key*) _b;
  if(strcmp(a.keyword,b.keyword)!=0){
    return strcmp(a.keyword,b.keyword);
  }
  else if(a.id!=b.id){
    return a.id-b.id;
  }
  else{
    return a.pos-b.pos;
  }
}

int main(){
  int ig=0;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  memset(ignore,'\0',sizeof(ignore));
  while(scanf("%s",ignore[ig])&&strcmp(ignore[ig],"::")!=0){
    ig++;
  }
  qsort(ignore,ig,sizeof(ignore[0]),cmp_string);

  int tg=0;
  getchar();
  char c;
  int count=0;
  int kp=0;

  while((c=getchar())!=EOF){
    if(isalpha(c)){
      titles[tg][count++]=tolower(c);
    }
    else if(c==' '){
      titles[tg][count++]=c;
    }
    else if(c=='\n'){
      if(count!=0){
        titles[tg][count]='\0';
        tg++;
        count=0;
      }
    }
  }
  if(count!=0){
    titles[tg][count]='\0';
    tg++;
    count=0;
  }

  // for(int i=0;i<tg;i++){
  //   printf("%s\n",titles[i]);
  // }

  count=0;
  char temp[20];
  for(int i=0;i<tg;i++){
    int len = strlen(titles[i]);
    memset(temp,'\0',sizeof(temp));
    for(int j=0;j<=len;j++){
      // printf("%c",titles[i][j]);
      if(isalpha(titles[i][j])){
        temp[count++]=titles[i][j];
      }
      else if(titles[i][j]==' '||titles[i][j]=='\0'){
        temp[count]='\0';
        int flag=1;
        // printf("Temp: %s\n",temp);
        for(int k=0;k<ig;k++){
          if(strcmp(ignore[k],temp)==0){
            flag=0;
          }
        }
        if(flag){
          // printf("%s is not ignored\n",temp);
          int start = j-count;
          int end = j;
          strcpy(keys[kp].keyword,temp);
          int pp=0;
          for(int k=0;k<start;k++){
            keys[kp].title[pp++]=titles[i][k];
          }
          for(int k=start;k<end;k++){
            keys[kp].title[pp++]=toupper(titles[i][k]);
          }
          for(int k=end;k<len;k++){
            keys[kp].title[pp++]=titles[i][k];
          }
          keys[kp].id=i;
          keys[kp].pos=start;
          kp++;
        }
        count=0;
      }
    }
  }
  qsort(keys,kp,sizeof(keys[0]),cmp_struct);
  for(int i=0;i<kp;i++){
    printf("%s\n",keys[i].title);
  }
  return 0;
}
