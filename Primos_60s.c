#include <stdio.h>
#include <time.h>

int primes[1000000000];

int testPrimes(int i,  int j){
    time_t init = time(NULL);
    //printf("%d", time(NULL) - init);
    int p = 0;
    while(time(NULL) - init < 60){
        printf("%d\n", time(NULL) - init);
        if(i == 2){
            primes[j] = i;
            //printf("%d ", i);
            i++;
            j++;
            continue;
        }
        for(int k = 0; k < j; k++){
            if(i % primes[k] == 0) break;
            if(primes[k]*primes[k] > i){
                //printf("%d ", i);
                primes[j] = i;
                j++;
                break;
            }
        }
        i++;
        p++;
    }
    return j;
}



int main()
{
	int size = testPrimes(2, 0);
	printf("\nForam achados: %d primos", size);
	return 0;
}