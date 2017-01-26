#include <stdio.h>
#include <stdlib.h>

int cmp_inc( const void *p1, const void *p2 ){
	const char *a1 = (const char *)p1;
	const char *a2 = (const char *)p2;

	if( *a1<*a2 )
		return -1;
	else if( *a1==*a2)
		return 0;
	else
		return 1;
}

int cmp_dec( const void *p1, const void *p2 ){
	const char *a1 = (const char *)p1;
	const char *a2 = (const char *)p2;

	if( *a1>*a2 )
		return -1;
	else if( *a1==*a2)
		return 0;
	else
		return 1;
}

int do_kaprekar(char *num){
	char big[5], small[5];
	int result=0;

	while(1){
		qsort(num, 4, sizeof(char), cmp_dec);
		sprintf(big, "%s", num);
		qsort(num, 4, sizeof(char), cmp_inc);
		sprintf(small, "%s", num);

		result = 1000*(big[0]-small[0]) + 100*(big[1]-small[1]) + 10*(big[2]-small[2]) + (big[3]-small[3]);

		if(result<10){
			printf("%s - %s = 000%d\n", big, small, result);
			sprintf(num, "000%d", result);
		}else if(result<100){
			printf("%s - %s = 00%d\n", big, small, result);
			sprintf(num, "00%d", result);
		}else if(result<1000){
			printf("%s - %s = 0%d\n", big, small, result);
			sprintf(num, "0%d", result);
		}else if(result){
			printf("%s - %s = %d\n", big, small, result);
			sprintf(num, "%d", result);
		}
		if(result==6174)
			return 1;
	}
}

int main(){
	char num[5];
	int N=0;
	scanf("%d", &N);

	if(N<10){
		sprintf(num, "000%d", N);
	}else if(N<100){
		sprintf(num, "00%d", N);
	}else if(N<1000){
		sprintf(num, "0%d", N);
	}else{
		sprintf(num, "%d", N);
	}

	if( num[0]==num[1] && num[1]==num[2] && num[2]==num[3] ){
		printf("%s - %s = 0000\n", num, num);
		return 0;
	}

	do_kaprekar(num);

	return 0;
}
