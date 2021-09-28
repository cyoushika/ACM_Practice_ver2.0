#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// #define LOCAL
#define MAXN 300

char vowel[]="AUEOI";
char consonant[]="JSBKTCLDMVNWFXGPYHQZR";
int vcount[5]={0};
int ccount[21]={0};
char v[MAXN],c[MAXN];

int cmp_char(const void* _a, const void* _b){
  char* a = (char*) _a;
  char* b = (char*) _b;
  return *a-*b;
}

int main(){
  int n;
  int l;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    int len=0;
    int vp=0;
    int cp=0;
    int vt=0;
    int ct=0;
    memset(vcount,0,sizeof(vcount));
    memset(ccount,0,sizeof(ccount));
    printf("Case %d: ",i);
    scanf("%d",&l);
    for(int j=1;j<=l;j++){
      if(j%2==1){
        if(vcount[vp]==21){
          vp++;
        }
        v[vt++]=vowel[vp];
        vcount[vp]++;
      }
      else{
        if(ccount[cp]==5){
          cp++;
        }
        c[ct++]=consonant[cp];
        ccount[cp]++;
      }
    }
    qsort(v,vt,sizeof(v[0]),cmp_char);
    if(ct>0){
      qsort(c,ct,sizeof(c[0]),cmp_char);
    }
    int p=0,q=0;
    while(true){
      if(p<vt){
        printf("%c",v[p]);
        p++;
      }
      if(q<ct){
        printf("%c",c[q]);
        q++;
      }
      if(p==vt&&q==ct){
        break;
      }
    }
    printf("\n");
  }
  return 0;
}
