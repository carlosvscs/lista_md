#include <stdio.h>

void primo(int a[], int x, int y, int c, int i){  
    if (c == 51 || y == 0){
        return;
    }
    else{
        if(y == 1){
            a[i] = x; 
            c++;
            i++;

            primo(a, x+1, x, c, i);
        }
        else if(x % y == 0){
            primo(a, x+1, x, c, i);
        
        }
        else{
            primo(a, x, y-1, c, i);
        }
    }
}

int main(){
    
    int x, i = 0, prints = 0;
    int valores_primos[51] = {0};

    primo(valores_primos, 2, 1 , 0, 0);

    scanf("%d", &x);

    printf("O número %d decomposto em fatores primos é: ", x);
  
    while(x != 1 || i < 51){
        if(x % valores_primos[i] == 0){
            x /= valores_primos[i];
            prints == 0 ? printf("%d", valores_primos[i]) : printf("*%d", valores_primos[i]);
            prints++;
            while(x % valores_primos[i] == 0){
                printf("*%d", valores_primos[i]);
                x /= valores_primos[i];
            }
        }
        i++;
    }

    return 0;
}