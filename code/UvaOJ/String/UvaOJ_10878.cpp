#include <stdio.h>
#include <string.h>
// #define LOCAL

int c[] = { 0, 0, 64, 32, 16, 8, 0, 4, 2, 1, 0};

int main() {
    char str[15];
    int value,i;

    #ifdef LOCAL
    freopen("./Desktop/ACM_Practice/code/UvaOJ/input.txt","r",stdin);
    freopen("./Desktop/ACM_Practice/code/UvaOJ/output.txt","w",stdout);
    #endif

    fgets(str,sizeof(str),stdin);
    while(fgets(str,sizeof(str),stdin) && str[0] != '_'){
        value = 0;
        int len = strlen(str);
        for(i = 2;i < len;i++){
            if(str[i] == 'o'){
                value += c[i];
            }
        }
        printf("%c",value);
    }
}
