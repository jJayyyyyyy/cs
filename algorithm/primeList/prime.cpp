#include <iostream>
#include <cmath>
#include <ctime>
#define MAXSIZE 1000001
using namespace std;

// 筛表法，找出MAXSIZE以内的素数，注意MAXSIZE应为奇数
int primeList[MAXSIZE] = {0, 0, 1};

void getPrimeList(){
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

int main(){
	clock_t begin, end;
	
	begin = clock();
	getPrimeList();
	end = clock();
	
	cout<<(end - begin)/CLOCKS_PER_SEC;
	return 0;
}
