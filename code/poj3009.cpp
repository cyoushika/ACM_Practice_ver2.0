#include<cstdio>
#include<iostream>
using namespace std;

int h,w;
int map[22][22];
int ans;
int cnt;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

void dfs(int y,int x){
  if(cnt>=10){
    return;
  }
  for(int i=0;i<4;i++){
    int yy=y+dy[i];
    int xx=x+dx[i];
    if(yy>=0&&yy<h&&xx>=0&&xx<w&&map[yy][xx]!=1){
      while(yy>=0&&yy<h&&xx>=0&&xx<w&&(map[yy][xx]==0||map[yy][xx]==2)){
        yy+=dy[i];
        xx+=dx[i];
      }
      if(yy<0||yy>=h||xx<0||xx>=w){
        //printf("nothing");
      }
      else if(map[yy][xx]==3){
        ans = min(ans,cnt+1);
      }
      else if(map[yy][xx]==1){
        map[yy][xx]=0;
        int py=yy-dy[i];
        int px=xx-dx[i];
        cnt++;
        dfs(py,px);
        cnt--;
        map[yy][xx]=1;
      }
    }
  }
}

int main(){
  while(true){
    scanf("%d%d",&w,&h);
    if(w==0&&h==0){
      break;
    }
    int sy,sx;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        scanf("%d",&map[i][j]);
        if(map[i][j]==2){
          sy=i;
          sx=j;
        }
      }
    }
    ans=999;
    cnt=0;
    dfs(sy,sx);
    if(ans==999){
      ans=-1;
    }
    printf("%d\n",ans);
  }
}
