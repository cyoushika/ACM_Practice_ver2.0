#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

#define MAXN 1000000

void stat_int(){
  int a[10] = {80,81,82,83,85,85,86,86,88,89};
  int q[110] = {};
  memset(q,0,sizeof(q));
  int max = 0;
  for(int i=0;i<10;i++){
    q[a[i]]++;
    if(q[a[i]]>max){
      max=q[a[i]];
    }
  }
  for(int i=0;i<=100;i++){
    if(q[i]==max){
      printf("%d ",i);
    }
  }
  printf("\n");
}

void stat_double(){
  double a[10] = {80.15,82.32,83.51,83.5,82.11,89.1,82.32,89.1,86.52,85.67};
  int q[110][110] = {};
  memset(q,0,sizeof(q));
  int max = 0;
  for(int i=0;i<10;i++){
    int m = (int) a[i];
    int n = ((int)(a[i]*100))%100;
    if(n%10==0){
      n=n/10;
    }
    q[m][n]++;
    if(q[m][n]>max){
      max=q[m][n];
    }
  }
  for(int i=0;i<=100;i++){
    for(int j=0;j<=100;j++){
      if(q[i][j]==max){
        printf("%d.%d ",i,j);
      }
    }
  }
  printf("\n");
}

void word(){
  char buf[MAXN]={"Hello,,, my friend,    my name is Zhang. "};
  char s[MAXN];
  // fgets(buf,sizeof(s),stdin);
  int count=0;
  int m=0;
  int n = strlen(buf);
  int flag=0;
  for(int i=0;i<n;i++){
    if(isalpha(buf[i])){
      s[m++]=buf[i];
      if(flag==0){
        flag=1;
        count++;
      }
    }
    else{
      flag=0;
    }
  }
  printf("Length:%d, Word:%d, Average:%lf\n",m,count,1.0*m/count);
}

void product(){
  char buf[MAXN]={"25 may , 41 dwadawf 14"};
  int n = strlen(buf);
  int result=1;
  int temp = 0;
  int flag = 0;

  for(int i=0;i<n;i++){
    if(isdigit(buf[i])){
      temp = temp*10+(buf[i]-'0');
      printf("temp:%d\n",temp);
      flag=1;
    }
    else{
      if(flag==1){
        result=result*temp;
        printf("result:%d\n",result);
      }
      temp=0;
      flag=0;
    }
  }

  if(flag==1){
    result = result*temp;
    flag=0;
    temp=0;
  }
  printf("Result:%d, Last 3 number:%d\n",result,result%1000);
}

void calculator(){
  char buf[MAXN]={"2-   5"};
  int temp=0;
  int x,y;
  char c;
  for(int i=0;i<strlen(buf);i++){
    if(isdigit(buf[i])){
      temp=temp*10+(buf[i]-'0');
    }
    else if(buf[i]=='+'||buf[i]=='-'||buf[i]=='*'){
      x = temp;
      c=buf[i];
      temp=0;
    }
  }
  y=temp;
  if(c=='+'){
    printf("%d\n",x+y);
  }
  else if(c=='-'){
    printf("%d\n",x-y);
  }
  else if(c=='*'){
    printf("%d\n",x*y);
  }
}

void rotate(){
  char buf[100][100] = {{'a','b','c','d','1'},{'e','f','g','h','2'},{'i','j','k','l','3'},{'m','n','o','p','4'},{'q','r','s','t','5'}};
  char map[100][100];
  memset(map,'-',sizeof(map));
  int n = strlen(buf[0]);
  int x,y,i,j;
  for(x=n-1;x>=0;x--){
    for(y=0;y<n;y++){
      map[i][j]=buf[y][x];
      j++;
    }
    j=0;
    i++;
  }
  for(int p=0;p<n;p++){
    for(int q=0;q<n;q++){
      printf("%c ", map[p][q]);
    }
    printf("\n");
  }
}

void base1(int b, int n){
  int m=0;
  int a[MAXN];
  while(n!=0){
    a[m++]=n%b;
    n = n/b;
  }
  for(;m>0;m--){
    printf("%d",a[m-1]);
  }
  printf("\n");
}

void base2(int b, int n){
  int t=0;
  int sum=0;
  while(n!=0){
    sum+=(n%10)*pow(b,t);
    n=n/10;
    t++;
  }
  printf("%d\n",sum);
}

int main(){
  stat_int();
  printf("\n");
  stat_double();
  printf("\n");
  word();
  printf("\n");
  product();
  printf("\n");
  calculator();
  printf("\n");
  rotate();
  printf("\n");
  base1(8,796);
  printf("\n");
  base2(2,1100);
  printf("\n");
}
