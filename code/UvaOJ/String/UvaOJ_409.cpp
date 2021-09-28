#include<stdio.h>
#include<string.h>
#include<ctype.h>
// #define LOCAL

char keywords[30][80];
char excuses[30][80];
char buf[80];
int bad[30];

int main(){
  int k,e;
  int set = 0;
  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while(scanf("%d%d",&k,&e)==2){
    set++;
    printf("Excuse Set #%d\n",set);
    for(int i=0;i<21;i++){
      memset(keywords[i],'\0',sizeof(keywords[0]));
      memset(excuses[i],'\0',sizeof(excuses[0]));
    }
    for(int i=0;i<k;i++){
      scanf("%s",keywords[i]);
    }
    getchar();
    int max=-100;

    memset(bad,0,sizeof(bad));

    for(int i=0;i<e;i++){
      memset(excuses[i],'\0',sizeof(excuses[i]));
      // fgets(excuses[i],sizeof(excuses[i]),stdin);
      int pointer = 0;
      int temp = 0;
      int count=0;
      char c;
      int occurs=0;

      memset(buf,'\0',sizeof(buf));

      while((c=getchar())!='\n' && c != EOF){
        excuses[i][temp++]=c;
        if(isalpha(c)){
          buf[count++]=tolower(c);
          // printf("%c",c);
        }
        else if(count!=0){
          for(int p=0;p<k;p++){
            if(strcmp(keywords[p],buf)==0){
              occurs++;
            }
          }
          count=0;
          memset(buf,'\0',sizeof(buf));
        }
      }
      if(count!=0){
        for(int p=0;p<k;p++){
          if(strcmp(keywords[p],buf)==0){
            occurs++;
          }
        }
        count=0;
        memset(buf,'\0',sizeof(buf));
      }
      if(occurs>max){
        max=occurs;
      }
      bad[i]=occurs;
      // printf("\n");
      // printf("Pointer=%d\n",pointer);
    }
    for(int i=0;i<e;i++){
      if(bad[i]==max){
        printf("%s\n",excuses[i]);
      }
    }
    printf("\n");
  }
  return 0;
}
