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
    return a%b == 0 ? b : euclides(b, a%b);
}


void ler(int n, int a[], int b[], int m[], int i, int* m_final)
{
    if(i >= n)
    {
        return;
    }

    scanf("%d %d %d", &a[i], &b[i], &m[i]);

    *m_final *= m[i];

    ler(n, a, b, m, i+1, m_final); 
}

int mdc(int i_fixo, int i_variavel, int m[], int limite){
    if(i_fixo >= limite){
        return 1;
    }
    else{
        if(i_variavel >= limite){
            mdc(i_fixo+1, 0, m, limite);
        }
        else{
            if(i_fixo == i_variavel){
                mdc(i_fixo, i_variavel+1, m, limite);
            }
            else if(euclides(m[i_fixo], m[i_variavel]) != 1){
                return 0;
            }
            else{
                mdc(i_fixo, i_variavel+1, m, limite);
            }
        }
    }
}

int main() {

    int n, i = 0, m_final = 1, aux = 0, den_cong = 0, cong = 0;
    scanf("%d", &n);
    int a[n], b[n], m[n], m_parcial[n], s[n];
    ler(n, a, b, m, 0, &m_final);

    while(i < n){
        m_parcial[i] = m_final/m[i];
        i++;
    }
    i = 0;

    while(i < n){
        descobrir_s(m_parcial[i], m[i], &s[i], &aux);
        i++;
    }
    i = 0;

    while(i < n){
    den_cong += m_parcial[i]*b[i]*s[i];
    i++;
    }

    cong = den_cong % m_final;

    while(cong > m_final){
        cong -= m_final;
    }

    if(mdc(0, 0, m, n) == 1){
        printf("A solução única é: %d\n", cong);
    }
    
    else{
        printf("Não foi possível encontrar uma solução única");
    }

    return 0;
}