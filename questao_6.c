#include <stdio.h>
 
int descobrir_s_e_t_(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    int _x, _y;
    int gcd = descobrir_s_e_t_(b % a, a, &_x, &_y);
 
    *x = _y - (b/a) * _x;
    *y = _x;
 
    return gcd;
}
 
int main()
{
    int a, b;

    scanf("%d %d", &a, &b);
 
    int x, y;
 
    descobrir_s_e_t_(a, b, &x, &y);
    printf("MDC(%d, %d) = %d * %d + %d * %d\n", a, b, x, a, y, b);
 
    return 0;
}