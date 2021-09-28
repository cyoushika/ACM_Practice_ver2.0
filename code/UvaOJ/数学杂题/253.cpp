#include<stdio.h>
#include<string.h>
// #define LOCAL

int arr[6][6]={
  {1,2,3,4,5,6},
  {2,6,3,4,1,5},
  {3,6,5,2,1,4},
  {4,6,2,5,1,3},
  {5,6,4,3,1,2},
  {6,5,3,4,2,1}
};

void swap(char *b, int i, int j){
  char c=b[i];
  b[i]=b[j];
  b[j]=c;
}

bool solve(char* a, char*b){
  // printf("%s vs %s\n",a,b);
  if(strcmp(a,b)==0){
    return true;
  }

  char temp[7];
  strcpy(temp,b);
  swap(temp,1,2);
  swap(temp,2,4);
  swap(temp,3,4);
  // printf("%s vs %s\n",a,temp);
  if(strcmp(a,temp)==0){
    return true;
  }

  strcpy(temp,b);
  swap(temp,1,3);
  swap(temp,2,3);
  swap(temp,3,4);
  // printf("%s vs %s\n",a,temp);
  if(strcmp(a,temp)==0){
    return true;
  }

  strcpy(temp,b);
  swap(temp,1,4);
  swap(temp,2,3);
  // printf("%s vs %s\n",a,temp);
  if(strcmp(a,temp)==0){
    return true;
  }

  return false;
}



int main(){
  char a[7];
  char b[7];
  char s[20];
  int i,j;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while(scanf("%s",s)!=EOF){
    for(i=0;i<6;i++){
      a[i]=s[i];
    }
    a[i]='\0';
    for(i=6;i<12;i++){
      b[i-6]=s[i];
    }
    b[i-6]='\0';
    int flag=0;
    for(i=0;i<6;i++){
      char temp[7];
      for(j=0;j<6;j++){
        // printf("%d ",arr[i][j]);
        temp[j]=b[arr[i][j]-1];
      }
      // printf("\n");
      temp[j]='\0';
      // printf("%s\n",temp);
      if(solve(a,temp)){
        printf("TRUE\n");
        flag=1;
        break;
      }
    }
    if(flag==0){
      printf("FALSE\n");
    }
  }
}
