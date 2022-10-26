#include <stdio.h>

int MDC(int a, int b)
{
    
    return a%b==0 ?  b /* MDC */ :

    MDC(b, a%b);
}

int main(){
int x, y;

scanf("%d %d", &x, &y);

printf("MDC(%d,%d) = %d\n", x, y, MDC(x, y));
}