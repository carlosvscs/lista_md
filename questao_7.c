#include <stdio.h>
 
int descobrir_inverso(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    int _x, _y;
    int gcd = descobrir_inverso(b % a, a, &_x, &_y);
 
    *x = _y - (b/a) * _x;
    *y = _x;
 
    return gcd;
}
 
int main()
{
    int a, b;

    scanf("%d %d", &a, &b);
 
    int x, y;
 
    descobrir_inverso(a, b, &x, &y);
    printf("O inverso é: %d\n", x);
 
    return 0;
}