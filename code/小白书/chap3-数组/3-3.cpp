#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define MAXN 5000+10

char buf[MAXN],s[MAXN];
int p[MAXN];

int main(){
  int n,m=0,max=0,x,y;
  fgets(buf,sizeof(s),stdin);
  n=strlen(buf);

  for(int i=0;i<n;i++){
    if(isalpha(buf[i])){
      p[m]=i;
      s[m]=toupper(buf[i]);
      m++;
    }
  }

  for(int i=0;i<m;i++){
    for(int j=0;i-j>=0&&i+j<m;j++){
      if(s[i-j]!=s[i+j]){
        break;
      }
      if(j*2+1>max){
        max=j*2+1;
        x=p[i-j];
        y=p[i+j];
      }
    }
    for(int j=0;i-j>=0&&i+j+1<m;j++){
      if(s[i-j]!=s[i+j+1]){
        break;
      }
      if(j*2+2>max){
        max=j*2+2;
        x=p[i-j];
        y=p[i+j+1];
      }
    }
  }
  for(int i=x;i<=y;i++){
    printf("%c",buf[i]);
  }
  printf("\n");
}

// int main(){
//   int n,m=0;
//   int max=0;
//   fgets(buf,sizeof(s),stdin);
//   n = strlen(buf);
//   for(int i=0;i<n;i++){
//     if(isalpha(buf[i])){
//       s[m]=toupper(buf[i]);
//       m++;
//     }
//   }
//   for(int i=0;i<m;i++){
//     for(int j=i;j<m;j++){
//       int flag=1;
//       for(int k=i,l=j;k<=j&&l>=i;k++,l--){
//         if(s[k]!=s[l]){
//           flag=0;
//         }
//       }
//       if(flag!=0 && j-i+1>max){
//         max=j-i+1;
//       }
//     }
//   }
//   printf("max=%d\n",max);
//   return 0;
// }

//Confuciuss say: Madam, I'm Adam.

// int main(){
//   int n,m=0,max=0;
//   int i,j,k;
//   fgets(buf,sizeof(s),stdin);
//   n = strlen(buf);
//   for(i=0;i<n;i++){
//     if(isalpha(buf[i])){
//       s[m++]=toupper(buf[i]);
//     }
//   }
//   for(i=0;i<m;i++){
//     for(j=i;j<m;j++){
//       int ok=1;
//       for(k=i;k<=j;k++){
//         if(s[k]!=s[i+j-k]){
//           ok=0;
//         }
//       }
//       if(ok && j-i+1>max){
//         max=j-i+1;
//       }
//     }
//   }
//   printf("max=%d\n",max);
//   return 0;
// }
