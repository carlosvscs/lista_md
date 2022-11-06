
#include <vector>
#include <time.h>
#include <iostream>
using namespace std;


vector<int> primes;

int crivo(int i, int len){

    while(i < len){
        if(i == 2){
            primes.push_back(2);
            i++;
            continue;
        }
        for(int j = 0; j < primes.size(); j++){
            if(i % primes[j] == 0) break;
            if(primes[j]*primes[j] > i){
                primes.push_back(i);
                break;
            }
        }
        i++;
    }
    return primes.size();
}

int main()
{
    time_t init = time(NULL);
    while(time(NULL) - init < 60){
        crivo(2, 10e7);
    }
    cout << primes.size() << endl;
    /*
    for(int i = 0; i < primes.size(); i++){
        cout << primes[i] << " ";
    }
    */
    return 0;
}