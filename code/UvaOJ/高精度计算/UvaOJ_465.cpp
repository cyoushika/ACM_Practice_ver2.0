#include<stdio.h>
#include<string.h>
#define MAXN 1000000
// #define LOCAL

char a[MAXN],b[MAXN];
int c[MAXN],d[MAXN];
int result[MAXN];
int temp[MAXN];
int max[] = {7,4,6,3,8,4,7,4,1,2};

// 2147483686
// 2147483647

void add(int* x, int* y, int lena, int lenb, int* result){
  int count=0;
  int i,j;
  for(i=0,j=0;i<lena&&j<lenb;i++,j++){
    // printf("X: %d, Y: %d\n",x[i],y[j]);
    result[count]+=x[i]+y[j];
    // printf("After: %d\n",result[count]);
    count++;
  }
  while(i<lena){
    result[count]+=x[i];
    i++;
    count++;
  }
  while(j<lenb){
    result[count]+=y[j];
    count++;
    j++;
  }
  for(int i=0;i<count;i++){
    result[i+1]+=result[i]/10;
    result[i]%=10;
  }
  // for(int i=count+1;i>=0;i--){
  //   printf("%d",result[i]);
  // }
  // printf("\n");
}

void multiple(int* a, int* b, int lena, int lenb, int* result){
  int i,j;
  for(i=0;i<lena;i++){
    for(j=0;j<lenb;j++){
      result[i+j]+=a[i]*b[j];
    }
  }
  for(i=0;i<lena+lenb;i++){
    result[i+1]+=result[i]/10;
    result[i]%=10;
  }
}

bool toobig(int* target, int len){
  if(len>10){
    return true;
  }
  else if(len<10){
    return false;
  }
  else{
    for(int i=len-1;i>=0;i--){
      // printf("Target: %d, Max: %d\n",target[i],max[i]);
      if(target[i]>max[i]){
        return true;
      }
      else if(target[i]<max[i]){
        return false;
      }
    }
    return false;
  }
}

int main(){
  char op;
  int lena,lenb;
  int i,j;
  int len;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  while(scanf("%s %c %s",a,&op,b)==3){
    lena=strlen(a);
    lenb=strlen(b);

    printf("%s %c %s\n",a,op,b);

    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    memset(result,0,sizeof(result));

    for(i=0;i<lena;i++){
      c[i]=(a[lena-1-i]-'0');
    }
    for(i=0;i<lenb;i++){
      d[i]=(b[lenb-1-i]-'0');
    }
    while(c[lena-1]==0){
      lena--;
    }
    while(d[lenb-1]==0){
      lenb--;
    }

    if(lena<0) lena=1;
    if(lenb<0) lenb=1;

    if(op=='+'){
      add(c,d,lena,lenb,result);
    }
    else if(op=='*'){
      multiple(c,d,lena,lenb,result);
    }

    len=lena+lenb;
    while(len>=0&&result[len]==0){
      len--;
    }
    if(len<0) len=1;

    // printf("len: %d\n",len);

    // printf("First\n");
    if(toobig(c,lena)){

      printf("first number too big\n");
    }
    // printf("Second\n");
    if(toobig(d,lenb)){
      printf("second number too big\n");
    }
    // printf("Result\n");
    if(toobig(result,len+1)){
      printf("result too big\n");
    }

    memset(a,'\0',sizeof(a));
    memset(b,'\0',sizeof(b));
  }
  return 0;
}
