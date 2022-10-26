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
    
    int x, y, i = 0;
    int valores_primos[51] = {0};
    int expoente_numero_1[51] = {0};
    int expoente_numero_2[51] = {0};
    int expoentes_mmc[51] = {0};
    int expoentes_mdc[51] = {0};

    primo(valores_primos, 2, 1 , 0, 0);

    scanf("%d %d", &x, &y);

    while(x != 1 || i < 51){
        if(x % valores_primos[i] == 0){
            x /= valores_primos[i];
            expoente_numero_1[i] += 1;

            while(x % valores_primos[i] == 0){
                expoente_numero_1[i] += 1;
                x /= valores_primos[i];
            }
        }
        i++;
    }

    i = 0;

    while(y != 1 || i < 51){
        if(y % valores_primos[i] == 0){
            y /= valores_primos[i];
            expoente_numero_2[i] += 1;

            while(y % valores_primos[i] == 0){
                expoente_numero_2[i] += 1;
                y /= valores_primos[i];
            }
        }
        i++;
    }

    i = 0;

    while(i < 51){
        expoentes_mmc[i] = (expoente_numero_1[i] >= expoente_numero_2[i]) ? expoente_numero_1[i] : expoente_numero_2[i];
        i++;
    }

    i = 0;

    while(i < 51){
        expoentes_mdc[i] = (expoente_numero_1[i] <= expoente_numero_2[i]) ? expoente_numero_1[i] : expoente_numero_2[i];
        i++;
    }

    i = 0;
    printf("MMC = ");
    while(i < 51){
        if(expoentes_mmc[i] > 0){
            printf("%d^%d ", valores_primos[i], expoentes_mmc[i]);
        }
        i++;
    }

    i = 0;

    printf("\nMDC = ");
    while(i < 51){
        if(expoentes_mdc[i] > 0){
            printf("%d^%d ", valores_primos[i], expoentes_mdc[i]);
        }
        i++;
    }

    printf("\n");

    return 0;
}