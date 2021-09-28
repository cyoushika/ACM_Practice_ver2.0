#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
using namespace std;

#define MAXN 3000
int f[MAXN];

struct bign{
  int len,s[MAXN];
  bign(){
    memset(s,0,sizeof(f));
    len = 1;
  }

  bign operator = (const char* num){
    len = strlen(num);
    for(int i=0;i<len;i++){
      s[i]=num[len-i-1]-'0';
    }
    return *this;
  }

  bign operator = (int num){
    char s[MAXN];
    sprintf(s,"%d",num);
    *this = s;
    return *this;
  }

  bign(int num){
    *this = num;
  }

  bign(const char* num){
    *this = num;
  }

  bign operator + (const bign& b) const{
    bign c;
    c.len = 0;
    for(int i=0,g=0;g||i<max(len,b.len);i++){
      int x=g;
      if(i<len) x+=s[i];
      if(i<b.len) x+=b.s[i];
      c.s[c.len++] = x%10;
      g = x/10;
    }
    return c;
  }

  bign operator += (const bign& b){
    *this = *this + b;
    return *this;
  }

  bool operator < (const bign& b) const{
    if(len!=b.len) return len<b.len;
    for(int i=len-1;i>=0;i--){
      if(s[i]!=b.s[i]){
        return s[i]<b.s[i];
      }
    }
    return false;
  }

  bool operator > (const bign& b) const{
    return b < *this;
  }

  bool operator <= (const bign& b) const{
    return !(b < *this);
  }

  bool operator >= (const bign& b) const{
    return !(*this<b);
  }

  bool operator != (const bign& b) const{
    return (b < *this)||(*this<b);
  }

  bool operator == (const bign& b) const{
    return !(b < *this) && !(*this<b);
  }

  string str() const{
    string res = "";
    for(int i=0;i<len;i++){
      res = (char)(s[i]+'0')+res;
    }
    if(res==""){
      res="0";
    }
    return res;
  }
};

istream& operator >> (istream &in, bign& x){
  string s;
  in >> s;
  x = s.c_str();
  return in;
}

ostream& operator << (ostream &out, const bign& x){
  out << x.str();
  return out;
}

int main(){
  int a,b;
  while(scanf("%d%d",&a,&b)==2){
    if(a==0&&b==0){
      break;
    }
    int count=0;
    int sum=0;
    int mul=1;
    int result=0;
    while(true){
      int p = a%10;
      int q = b%10;
      int r = p+q+count;
      if(r>=10){
        count = 1;
        result++;
        r = r%10;
      }
      else{
        count = 0;
      }
      a = a/10;
      b = b/10;
      sum = sum+r*mul;
      mul*=10;
      if(a==0&&b==0){
        if(count==1){
          sum = sum+count*mul;
        }
        break;
      }
    }
    printf("%d %d\n",sum, result);
  }
  return 0;
}

// int main(){
//   int i,j,n;
//   scanf("%d",&n);
//   memset(f,0,sizeof(f));
//   f[0]=1;
//   for(i=2;i<=n;i++){
//     int c = 0;
//     for(j=0;j<MAXN;j++){
//       int s = f[j]*i+c;
//       f[j]=s%10;
//       c=s/10;
//     }
//   }
//   for(j=MAXN-1;j>=0;j--){
//     if(f[j]!=0){
//       break;
//     }
//   }
//   for(i=j;i>=0;i--){
//     printf("%d",f[i]);
//   }
//   printf("\n");
//   return 0;
// }

// int main(){
//   int i,j,n;
//   scanf("%d",&n);
//   memset(f,0,sizeof(f));
//   f[0]=1;
//   for(i=2;i<=n;i++){
//     int c = 0;
//     for(j=0;j<MAXN;j++){
//       int s = f[j]*i+c;
//       f[j] = s%10;
//       c = s/10;
//     }
//   }
//   for(j=MAXN-1;j>=0;j--){
//     if(f[j]){
//       break;
//     }
//   }
//   for(i=j;i>=0;i--){
//     printf("%d",f[i]);
//   }
//   printf("\n");
//   return 0;
// }
