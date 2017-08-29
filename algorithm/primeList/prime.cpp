#include <cmath>
#define MAXSIZE 10005

int primeList[MAXSIZE] = {0, 0, 1};

void init(){
    int i, j;
	for( i = 3; i < MAXSIZE; i += 2 ){
		primeList[i] = 1;
		primeList[i + 1] = 0;
	}

	int upperBound = (int) sqrt(MAXSIZE);
	for( i = 3; i < upperBound; i += 2 ){
		if( 1 == primeList[i] ){
			for( j= i + i; j < MAXSIZE; j += i ){
				primeList[j] = 0;
			}
		}
	}
}
