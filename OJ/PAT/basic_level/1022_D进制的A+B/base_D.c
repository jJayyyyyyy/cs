#include <stdio.h>
#define MAX 40

int main(){
	int us_a=0, us_b=0, us_D=2;
	int sigma=0, remain=0;
	int output[MAX], i=0;

	scanf("%d%d%d", &us_a, &us_b, &us_D);
	if(us_D<2){
		us_D = 2;
	}else if(us_D>10){
		us_D = 10;
	}

	sigma = us_a + us_b;
	if( 0==sigma ){
		printf("0");
		return 0;
	}

	if( 10==us_D ){
		printf("%d\n", sigma);
		return 0;
	}

	while( sigma!=0 ){
		remain = sigma % us_D;
		sigma /= us_D;
		output[i++] = remain;
	}

	while( i!=0 ){
		i--;
		printf("%d", output[i]);
	}

	return 0;
}
