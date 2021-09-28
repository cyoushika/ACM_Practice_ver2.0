#include<stdio.h>
#include<string.h>
#define MAXN 100
// #define LOCAL

char reverse(char c){
  if(c=='A'||c=='H'||c=='I'||c=='M'||c=='O'||c=='T'||c=='U'||c=='V'||c=='W'||c=='X'||c=='Y'||c=='1'||c=='8'){
    return c;
  }
  else if(c=='E'){ return '3'; }
  else if(c=='3'){ return 'E'; }
  else if(c=='J'){ return 'L'; }
  else if(c=='L'){ return 'J'; }
  else if(c=='S'){ return '2'; }
  else if(c=='2'){ return 'S'; }
  else if(c=='Z'){ return '5'; }
  else if(c=='5'){ return 'Z'; }
  else{
    return '?';
  }
}

bool is_palindrome(char *a){
  int len=strlen(a);
  int flag=1;
  for(int i=0,j=len-1;i<=j;i++,j--){
    if(a[i]!=a[j]){
      flag=0;
      break;
    }
  }
  if(flag==1){
    return true;
  }
  else{
    return false;
  }
}

bool is_mirrored(char *a){
  int len=strlen(a);
  char buf[MAXN];
  int count = 0;
  memset(buf,'\0',sizeof(buf));
  for(int i=0;i<len;i++){
    if(reverse(a[i])!='?'){
      buf[count++]=reverse(a[i]);
    }
    else{
      return false;
    }
  }
  int flag=1;
  for(int i=len-1,j=0;i>=0&&j<len;i--,j++){
    if(a[i]!=buf[j]){
      flag=0;
      break;
    }
  }
  if(flag==1){
    return true;
  }
  else{
    return false;
  }
}

int main(){
  char a[MAXN];
  bool palindrome,mirrored;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while(scanf("%s",a)!=EOF){
    palindrome = is_palindrome(a);
    mirrored = is_mirrored(a);
    if(palindrome&&mirrored){
      printf("%s -- is a mirrored palindrome.\n",a);
    }
    else if(palindrome){
      printf("%s -- is a regular palindrome.\n",a);
    }
    else if(mirrored){
      printf("%s -- is a mirrored string.\n",a);
    }
    else{
      printf("%s -- is not a palindrome.\n",a);
    }
    printf("\n");
  }
  return 0;
}
