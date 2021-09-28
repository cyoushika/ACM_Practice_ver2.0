#include<stdio.h>
#include<string.h>
#include<ctype.h>

// #define LOCAL

int multiple(int* a, int* b, int lena, int lenb, int* result){
  int i,j;
  // printf("A:");
  // for(i=lena-1;i>=0;i--){
  //   printf("%d",a[i]);
  // }
  // printf("\n");
  // printf("B:");
  // for(i=lenb-1;i>=0;i--){
  //   printf("%d",b[i]);
  // }
  // printf("\n");
  for(i=0;i<lena;i++){
    for(j=0;j<lenb;j++){
      // printf("A:%d B:%d\n",a[i],b[j]);
      result[i+j]+=a[i]*b[j];
      // printf("Result[%d]: %d\n",i+j,result[i+j]);
    }
  }
  for(i=0;i<lena+lenb;i++){
    result[i+1]+=result[i]/10;
    result[i]%=10;
  }
  i=lena+lenb-1;
  while(i>=0&&result[i]==0) i--;
  if(i==-1) i=0;
  lenb=i+1;
  return lenb;
}

int main(){
  int lena,lenb;
  int i,j;
  char a[200];
  int c[200]={0};
  int d[200]={0};
  int temp[200]={0};
  int dec=0;
  int n;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while(scanf("%s%d",a,&n)==2){
    if(n==0){
      printf("1.\n");
    }
    else{
      lena=strlen(a);
      lenb=0;
      int flag=1;
      dec=0;
      memset(c,0,sizeof(c));
      memset(d,0,sizeof(d));
      memset(temp,0,sizeof(temp));
      while(a[lena-1]=='0'){
        lena--;
      }

      for(i=0;i<lena;i++){
        if(isdigit(a[lena-1-i])){
          c[lenb]=(a[lena-1-i]-'0');
          // printf("%d\n",c[lenb]);
          temp[lenb]=c[lenb];
          lenb++;
          if(flag==1){
            dec++;
          }
        }
        else if(a[lena-1-i]=='.'){
          flag=0;
        }
      }
      lena=lenb;
      // printf("DEC: %d\n",dec);
      dec=dec*n;
      while(n>1){
        lenb = multiple(c,temp,lena,lenb,d);
        memset(temp,0,sizeof(temp));
        for(i=0;i<lenb;i++){
          temp[i]=d[i];
        }
        memset(d,0,sizeof(d));
        // lenb = multiple(c,temp,lena,lenb,d);
        n--;
      }
      if(dec>=lenb){
        printf(".");
        for(i=0;i<dec-lenb;i++){
          printf("0");
        }
        for(i=lenb-1;i>=0;i--){
          printf("%d",temp[i]);
        }
      }
      else{
        for(i=lenb-1;i>=0;i--){
          printf("%d",temp[i]);
          if(i==dec){
            printf(".");
          }
        }
      }
      printf("\n");
    }
  }
  return 0;
}
