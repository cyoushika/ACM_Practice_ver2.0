#include<stdio.h>
#include<string.h>

// char *s = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
// int main(){
//   int i,c;
//   while((c=getchar())!=EOF){
//     for(i=1;s[i] && s[i]!=c;i++);
//     if(s[i]){
//       putchar(s[i-1]);
//     }
//     else{
//       putchar(c);
//     }
//   }
// }

// int main(){
//   int c,q=1;
//   while((c=getchar())!=EOF){
//     if(c=='"'){
//       printf("%s",q?"``":"''");
//       q=!q;
//     }
//     else{
//       printf("%c",c);
//     }
//   }
//   return 0;
// }

int main(){
  char word[100];
  scanf("%s",word);
  int len = strlen(word);
  for(int i=1;i<=len;i++){
    if(len%i==0){
      int ok=1;
      for(int j=i;j<len;j++){
        if(word[j]!=word[j%i]){
          ok=0;
          break;
        }
      }
      if(ok){
        printf("%d\n",i);
        break;
      }
    }
  }
  return 0;
}
