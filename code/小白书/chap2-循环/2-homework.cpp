#include<stdio.h>
#include<math.h>

void digit(int n){
  int count=0;
  while(n!=0){
    count++;
    n = n/10;
  }
  printf("%d\n",count);
}

void daffodil(){
  int a,b,c;
  int m,n;
  for(a=1;a<=9;a++){
    for(b=0;b<=9;b++){
      for(c=0;c<=9;c++){
        m = a*100+b*10+c;
        n = a*a*a+b*b*b+c*c*c;
        if(m==n){
          printf("%d\n",m);
        }
      }
    }
  }
}

void hanxin(){
  FILE *fin;
  fin = fopen("./Desktop/ACM_Practice/code/小白书/hanxin.in","rb");
  // fout = fopen("./Desktop/ACM_Practice/code/小白书/hanxin.out","wb")
  int a,b,c;
  if(fin==NULL){
    printf("File Not Exist!\n");
  }
  else{
    while(fscanf(fin,"%d%d%d",&a,&b,&c)==3){
      int p,x;
      int flag=0;
      for(p=3;3*p+a<=100;p++){
        x = 3*p+a;
        if(x%5==b and x%7==c){
          printf("%d\n",x);
          flag=1;
          break;
        }
      }
      if(flag==0){
        printf("No answer\n");
      }
    }
  }
}

void triangle(int n){
  int m = 2*n-1;
  int l = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
      printf(" ");
    }
    for(int j=0;j<m;j++){
      printf("#");
    }
    for(int j=0;j<i;j++){
      printf(" ");
    }
    printf("\n");
    m = m-2;
  }
}

void stat(){
  FILE *fin;
  fin = fopen("./Desktop/ACM_Practice/code/小白书/stat-2.in","rb");
  int n,m;
  int a[1000];
  while(fscanf(fin,"%d",&n)==1){
    int count=0;
    for(int i=0;i<n;i++){
      fscanf(fin,"%d",&a[i]);
    }
    fscanf(fin,"%d",&m);
    for(int i=0;i<n;i++){
      if(a[i]<m){
        count++;
      }
    }
    printf("%d\n",count);
  }
}

void harmony(int n){
  double H=0.0;
  for(int i=1;i<=n;i++){
    H+=1.0/i;
  }
  printf("%.3lf\n",H);
}

void approximation(){
  int i=1,j=1;
  double H = 0;
  while(1.0/i>=1E-6){
    H+=1.0/i*j;
    i+=2;
    j=j*(-1);
  }
  printf("%lf\n",H);
}

void subsequence(int n, int m){
  // long long int x;
  double item;
  double H=0.0;
  for(int i=n;i<=m;i++){
    // x = (long long int) i* (long long int) i;
    item = 1.0/i/i;
    H+=item;
  }
  printf("%.5lf\n",H);
}

void decimal(int a, int b, int c){
  double H = (double)a/b;
  double dec = H - int(H);
  int time = 1;
  double round = 0.5;

  for(int i=0;i<c;i++){
    time*=10;
    round/=10;
  }
  dec = (dec+round)*time;
  printf("%d.%d\n",int(H),int(dec));
}

void permutation(){
  int a,b,c,d,e,f,g,h,i;
  int count=0;
  for(a=1;a<=9;a++){
    for(b=1;b<=9;b++){
      if(b!=a){
        for(c=1;c<=9;c++){
          if(c!=a&&c!=b){
            for(d=1;d<=9;d++){
              if(d!=a&&d!=b&&d!=c){
                for(e=1;e<=9;e++){
                  if(e!=a&&e!=b&&e!=c&&e!=d){
                    for(f=1;f<=9;f++){
                      if(f!=a&&f!=b&&f!=c&&f!=d&&f!=e){
                        for(g=1;g<=9;g++){
                          if(g!=a&&g!=b&&g!=c&&g!=d&&g!=e&&g!=f){
                            for(h=1;h<=9;h++){
                              if(h!=a&&h!=b&&h!=c&&h!=d&&h!=e&&h!=f&&h!=g){
                                for(i=1;i<=9;i++){
                                  if(i!=a&&i!=b&&i!=c&&i!=d&&i!=e&&i!=f&&i!=g&&i!=h){
                                    int m,n,o;
                                    m = a*100+b*10+c;
                                    n = d*100+e*10+f;
                                    o = g*100+h*10+i;
                                    if(2*m==n && 3*m==o){
                                      count++;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  printf("%d\n", count);
}

int main(){
  digit(12735);
  printf("\n");
  daffodil();
  printf("\n");
  hanxin();
  printf("\n");
  triangle(5);
  printf("\n");
  stat();
  printf("\n");
  harmony(3);
  printf("\n");
  approximation();
  printf("\n");
  subsequence(65536,655360);
  printf("\n");
  decimal(1,6,8);
  printf("\n");
  permutation();
  printf("\n");
}
