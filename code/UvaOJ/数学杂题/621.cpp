#include<stdio.h>
#include<string.h>
// #define LOCAL

int main(){
  int n,i;
  char s[200]="";

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  scanf("%d",&n);
  while(n--){
    memset(s,'\0',sizeof(s));
    scanf("%s",s);
    if((s[0]=='1'&&s[1]=='\0')||(s[0]=='4'&&s[1]=='\0')||(s[0]=='7'&&s[1]=='8'&&s[2]=='\0')){
      printf("+\n");
    }
    else{
      i = strlen(s);
      if(s[i-2]=='3'&&s[i-1]=='5'){
        printf("-\n");
      }
      else if(s[0]=='9'&&s[i-1]=='4'){
        printf("*\n");
      }
      else if(s[0]=='1'&&s[1]=='9'&&s[2]=='0'){
        printf("?\n");
      }
      else{
        printf("?\n");
      }
    }
  }
  return 0;
}
