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
    int a, b, m, m_final, s1, aux, cong, mp1;
    int a2, b2, m2, s2, mp2;
    int a3, b3, m3, s3, mp3;

    scanf("%d %d %d", &a, &b, &m);
    scanf("%d %d %d", &a2, &b2, &m2);
    scanf("%d %d %d", &a3, &b3, &m3);

    m_final = m * m2 * m3;

    mp1 = m_final/m;
    mp2 = m_final/m2;
    mp3 = m_final/m3;
    
    descobrir_s(mp1, m, &s1, &aux);
    descobrir_s(mp2, m2, &s2, &aux);
    descobrir_s(mp3, m3, &s3, &aux);
    
    cong = (mp1*b*s1) + (mp2*b2*s2) + (mp3*b3*s3) % m_final;
    
    while(cong > m_final){
        cong -= m_final;
    }

    if(euclides(m, m2) == 1 && euclides(m2, m3) == 1 && euclides(m, m3) == 1){
        printf("A solução única é: %d\n", cong);
    }
    else{
        printf("Não foi possível encontrar uma solução única\n");
    }

    return 0;


}