#include<stdio.h>
#include<string.h>//rand(), srand()
#include<stdlib.h>//time()
#include<time.h>
using namespace std;

int n=100,m=100000;

//Generate random number between 0~1
// double random(){
//   double result = (double)rand() / RAND_MAX;
//   return result;
// }

//Generate randon number between 0~m-1
int random(int m){
  return (int)((double)rand()/RAND_MAX*(m-1)+0.5);
}

int main(){
  srand(time(NULL));
  printf("%d %d\n",n,m);
  for(int i=0;i<m;i++){
    if(rand()%2==0){
      printf("A");
    }
    else{
      printf("B");
    }
    int X,Y;
    for(;;){
      X=random(n)+1;
      Y=random(n)+1;
      if(X!=Y){
        break;
      }
    }
    printf(" %d %d\n",X,Y);
  }
  return 0;
}
