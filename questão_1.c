#include <stdio.h>

int primo(int x, int y){
    if(y == 1){
        return 1; //primo
    }
    if(x == 1 || x % y == 0){
        return 0; //não é
    }
    primo(x, y-1);
}

int main(){
    int a;

    scanf("%d", &a);

    printf("%s\n", primo(a, a-1) == 1 ? "É um número primo" : "Não é um número primo");

    return 0;
}