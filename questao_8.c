#include <stdio.h>

int descobrir_s(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    int _x, _y;
    int gcd = descobrir_s(b % a, a, &_x, &_y);
 
    *x = _y - (b/a) * _x;
    *y = _x;
 
    return gcd;
}

int euclides(int a, int b)
{  
    return a%b==0 ? b : euclides(b, a%b);
}

int main()
{
    int a, b, m, s, x, aux, mdc, repeticoes;
    scanf("%d %d %d", &a, &b, &m);
    
    descobrir_s(a, m, &s, &aux);
    
    mdc = euclides(a, m);

    while(s < 0){
        s += (m/mdc);
    }

    x = (s*b)/mdc;
    repeticoes = mdc-1;
    
    if(x == (s*b)/mdc){
        while(x > m/mdc){
            x -= m/mdc;
        }
        printf("As soluções são: %d", x);
        while(repeticoes > 0){
            x += m/mdc;
            repeticoes--;
            printf(", %d", x);
        }
        printf("\n");
    }
    else{
        printf("Não foi possível encontrar uma solução\n");
    }

    return 0;


}