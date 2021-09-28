#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<iostream>

// #define LOCAL

using namespace std;

char buf[1000][11];

int cmp_string(const void* _a, const void* _b){
  char* a = (char*) _a;
  char* b = (char*) _b;
  return strlen(a)-strlen(b);
}

bool isPrefix(char* a, char* b){
  for(int i=0;i<strlen(a);i++){
    if(a[i]!=b[i]){
      return false;
    }
  }
  return true;
}

int main(){
  char c;
  int count=0;
  int l=0;
  int t=0;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while((c=getchar())!=EOF){
    if(c!='\n'&&c!='9'){
      buf[count][l++]=c;
    }
    else if(c=='\n'){
      buf[count][l]='\0';
      count++;
      l=0;
    }
    else if(c=='9'){
      getchar();
      t++;
      qsort(buf,count,sizeof(buf[0]),cmp_string);
      int flag=1;
      for(int i=0;i<count;i++){
        for(int j=i+1;j<count;j++){
          if(isPrefix(buf[i],buf[j])){
            flag=0;
            break;
          }
        }
        if(flag==0){
          break;
        }
      }
      if(flag==0){
        printf("Set %d is not immediately decodable\n",t);
      }
      else{
        printf("Set %d is immediately decodable\n",t);
      }
      for(int p=0;p<count;p++){
        memset(buf[p],'\0',sizeof(buf[p]));
      }
      count=0;
    }
  }
  return 0;
}
