#include <cstdio>
#define MAX 100004
using namespace std;

int main(){
	double sigma=0.0, num=0.0;
	int n, i;
	scanf("%d", &n);

	for( i=1; i<=n; i++ ){
		scanf("%lf", &num);
		sigma += num*i*(n-i+1);
	}

	printf("%.2f\n", sigma);
	return 0;
}

// 0.2*1*4 + 0.3*2*3 + 0.4*3*2
