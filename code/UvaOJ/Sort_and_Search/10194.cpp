#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
// #define LOCAL

typedef struct{
  char name[35];
  char lex[35];
  int point;
  int game;
  int win;
  int tie;
  int lose;
  int diff;
  int score;
  int against;
}Detail;

int cmp_struct(const void* _a, const void* _b){
  Detail a = *(Detail*) _a;
  Detail b = *(Detail*) _b;
  if(a.point!=b.point){
    return b.point-a.point;
  }
  else if(a.win!=b.win){
    return b.win-a.win;
  }
  else if(a.diff!=b.diff){
    return b.diff-a.diff;
  }
  else if(a.score!=b.score){
    return b.score-a.score;
  }
  else if(a.game!=b.game){
    return a.game-b.game;
  }
  else{
    return strcmp(a.lex,b.lex);
  }
}

int main(){
  int t;
  char title[110]="";
  int n;
  char c;
  int g;

  #ifdef LOCAL
  freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
  freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
  #endif

  scanf("%d",&t);
  getchar();
  while(t--){
    Detail teams[31];
    fgets(title,110,stdin);
    printf("%s",title);
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
      int count=0;
      while((c=getchar())!='\n'){
        teams[i].name[count]=c;
        if(isalpha(c)){
          teams[i].lex[count++]=toupper(c);
        }
        else{
          teams[i].lex[count++]=c;
        }
      }
      teams[i].name[count]='\0';
      teams[i].point=0;
      teams[i].game=0;
      teams[i].win=0;
      teams[i].tie=0;
      teams[i].lose=0;
      teams[i].diff=0;
      teams[i].score=0;
      teams[i].against=0;
    }
    scanf("%d",&g);
    getchar();
    for(int i=0;i<g;i++){
      char team1[35];
      char team2[35];
      int count=0;
      int point1=0;
      int point2=0;
      int flag1=1,flag2=1;
      while((c=getchar())!='#'){
        team1[count++]=c;
      }
      team1[count]='\0';
      while((c=getchar())!='@'){
        point1=point1*10+(c-'0');
      }
      while((c=getchar())!='#'){
        point2=point2*10+(c-'0');
      }
      count=0;
      while((c=getchar())!='\n'){
        team2[count++]=c;
      }
      team2[count]='\0';
      // printf("Team1:%s vs Team2:%s\n",team1,team2);
      for(int j=0;j<n;j++){
        if(flag1&&strcmp(teams[j].name,team1)==0){
          if(point1>point2){
            teams[j].point+=3;
            teams[j].win+=1;
          }
          else if(point1==point2){
            teams[j].point+=1;
            teams[j].tie+=1;
          }
          else{
            teams[j].lose+=1;
          }
          teams[j].game+=1;
          teams[j].score+=point1;
          teams[j].against+=point2;
          teams[j].diff=teams[j].score-teams[j].against;
          flag1=0;
        }
        else if(flag2&&strcmp(teams[j].name,team2)==0){
          if(point1<point2){
            teams[j].point+=3;
            teams[j].win+=1;
          }
          else if(point1==point2){
            teams[j].point+=1;
            teams[j].tie+=1;
          }
          else{
            teams[j].lose+=1;
          }
          teams[j].game+=1;
          teams[j].score+=point2;
          teams[j].against+=point1;
          teams[j].diff=teams[j].score-teams[j].against;
          flag2=0;
        }
        if(flag1==0&&flag2==0){
          break;
        }
      }
    }
    qsort(teams,n,sizeof(teams[0]),cmp_struct);
    for(int i=0;i<n;i++){
      printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i+1,teams[i].name,teams[i].point,teams[i].game,teams[i].win,teams[i].tie,teams[i].lose,teams[i].diff,teams[i].score,teams[i].against);
    }
    if(t>0){
      printf("\n");
    }
  }
}
