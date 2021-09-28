#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int n;
char word[2000][10];
char sorted[2000][10];

int cmp_string(const void* _a, const void* _b){
  char* a = (char*) _a;
  char* b = (char*) _b;
  return strcmp(a,b);
}

int cmp_char(const void* _a, const void* _b){
  char* a = (char*) _a;
  char* b = (char*) _b;
  return *a-*b;
}

int main(){
  n=0;
  for(;;){
    scanf("%s",word[n]);
    if(word[n][0]=='*') break;
    n++;
  }
  qsort(word,n,sizeof(word[0]),cmp_string);

  for(int i=0;i<n;i++){
    strcpy(sorted[i],word[i]);
    qsort(sorted[i],strlen(sorted[i]),sizeof(char),cmp_char);
  }

  char buf[10];
  while(scanf("%s",buf)==1){
    qsort(buf,strlen(buf),sizeof(char),cmp_char);
    int found=0;
    for(int i=0;i<n;i++){
      if(strcmp(buf,sorted[i])==0){
        printf("%s ",word[i]);
        found=1;
      }
    }
    if(found==0){
      printf(":(");
    }
    printf("\n");
  }
  return 0;
}


// int cmp_char(const void* _a, const void* _b){
//   char* a = (char*) _a;
//   char* b = (char*) _b;
//   return *a-*b;
// }
//
// int cmp_string(const void* _a, const void* _b){
//   char* a = (char*) _a;
//   char* b = (char*) _b;
//   return strcmp(a,b);
// }
//
// int cmp_int(const void* _a, const void* _b){
//   int* a = (int*) _a;
//   int* b = (int*) _b;
//   return (*a-*b);
// }
//
// int main(){
//   int a[] = {8,2,56,22};
//
//   qsort(a,4,sizeof(int),cmp_int);
//   for(int i=0;i<4;i++){
//     printf("%d ",a[i]);
//   }
//   printf("\n");
//   return 0;
// }

// int main(){
//   n=0;
//   for(;;){
//     scanf("%s",word[n]);
//     if(word[n][0]=="*"){
//       break;
//     }
//     n++;
//   }
//   qsort(word,n,sizeof(word[0]),cmp_string);
//
//   for(int i=0;i<n;i++){
//     strcpy(sorted[i],word[i]);
//     qsort(sorted[i],strlen(sorted[i]),sizeof(char),cmp_char);
//   }
//
//   char s[10];
//   while(scanf("%s",s)==1){
//     qsort(s,strlen(s),sizeof(s),cmp_char);
//     int found = 0;
//     for(int i=0;i<n;i++){
//       if(strcmp(sorted[i],s)==0){
//         found=1;
//         printf("%s ",word[i]);
//       }
//     }
//     if(!found){
//       printf(":(");
//     }
//     printf("\n");
//   }
//   return 0;
// }

// void qsort(char* a,int l, int r){
//   int m = (l+r)/2;
//   int i=l,j=r;
//   while(i<=j){
//     while(a[i]<a[m]) i++;
//     while(a[j]>a[m]) j--;
//     if(i<=j){
//       char t = a[i];
//       a[i] = a[j];
//       a[j] = t;
//       i++;
//       j--;
//     }
//   }
//   if(i<=r){
//     qsort(a,i,r);
//   }
//   if(j>=l){
//     qsort(a,l,j);
//   }
// }



// int get_next(int x){
//   int a,b,n;
//   char s[10];
//   sprintf(s,"%d",x);
//   n = strlen(s);
//   qsort(s,0,n-1);
//   sscanf(s,"%d",&b);
//   int i=0,j=n-1;
//   while(i<=j){
//     char t=s[i];
//     s[i] = s[j];
//     s[j] = t;
//     i++;
//     j--;
//   }
//   sscanf(s,"%d",&a);
//   return a-b;
// }
//
// int num[2000];
// int count=0;
//
// int main(){
//   int n;
//   scanf("%d",&num[count]);
//   printf("%d",num[count]);
//   count++;
//   while(true){
//     num[count] = get_next(num[count-1]);
//     printf(" -> %d",num[count]);
//     int found = 0;
//     for(int i=0;i<count;i++){
//       if(num[i]==num[count]){
//         found=1;
//         break;
//       }
//     }
//     if(found==1){
//       break;
//     }
//     count++;
//   }
//   printf("\n");
//   return 0;
// }

// int get_next(int x){
//   int a,b,n;
//   char s[10];
//   sprintf(s,"%d",x);
//   n = strlen(s);
//   for(int i=0;i<n;i++){
//     for(int j=i+1;j<n;j++){
//       if(s[i]>s[j]){
//         char t = s[i];
//         s[i] = s[j];
//         s[j] = t;
//       }
//     }
//   }
//   sscanf(s,"%d",&b);
//   for(int i=0;i<n/2;i++){
//     char t = s[i];
//     s[i] = s[n-1-i];
//     s[n-1-i] = t;
//   }
//   sscanf(s,"%d",&a);
//   return a-b;
// }
//
// int num[2000],count;
//
// int main(){
//   scanf("%d",&num[0]);
//   printf("%d",num[0]);
//   count=1;
//   for(;;){
//     num[count]=get_next[num[count-1]];
//     printf(" -> %d",num[count]);
//     int found = 0;
//     for(int i=0;i<count;i++){
//       if(num[i]==num[count]){
//         found=1;
//         break;
//       }
//     }
//     if(found) break;
//     count++;
//   }
//   printf("\n");
//
//   return 0;
// }
