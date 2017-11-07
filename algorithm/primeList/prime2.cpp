#include <iostream>
#include <ctime>
#define MAXSIZE 1000001
using namespace std;

// 找出MAXSIZE以内的素数
// 如果一个数是素数，那么它前面所有的素数都不是它的因子。否则它不是素数
int primeList[MAXSIZE] = {2};

bool isPrime(int x, int len){
	for( int i = 0; i < len; i++ ){
		if( x % primeList[i] == 0 ){
			return false;
		}
	}
	return true;
}

void getPrimeList(){
	int len = 1;
	
	for( int x = 3; x < MAXSIZE; x++ ){
		if( true == isPrime(x, len) ){
			primeList[len++] = x;
		}
	}
}

int main() {
	clock_t begin, end;
	begin = clock();
	getPrimeList();
	end = clock();
	cout<<(end - begin)/CLOCKS_PER_SEC;
	return 0;
}

// 注意，写出来只是以防考试考到
// 该方法比筛表法至少慢两个数量级
