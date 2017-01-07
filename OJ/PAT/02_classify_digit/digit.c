#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
	int us_N=0, i=0;
	int a=0, a1=0, a2=0, a3=0, a4=0, a5=0;
	int multi=1, cnt1=0, cnt2=0, cnt3=0, cnt4=0, cnt5=0;
	int *us_input;
	scanf("%d", &us_N);
	// us_input = (int *)malloc((us_N)*sizeof(int));
	if( (us_input = (int *)malloc((us_N)*sizeof(int))) == NULL){
		printf("no more memory!");
		exit(EXIT_FAILURE);
	}
	while(i<us_N && scanf("%d", &us_input[i])==1){
		a = us_input[i];
		if(0 == a%10){
			a1 += a;
			cnt1 += 1;
		}
		if(1 == a%5){
			a2 += multi*a;
			multi = -multi;
			cnt2 += 1;
		}
		if(2 == a%5){
			a3 += 1;
			cnt3 += 1;
		}
		if(3 == a%5){
			a4 += a;
			cnt4 += 1;
		}
		if(4 == a%5){
			if(a5 < a){
				a5 = a;
			}
			cnt5 += 1;
		}
		i++;
	}

	if(0 == cnt1){
		printf("N ");
	}else{
		printf("%d ", a1);
	}
	if(0 == cnt2){
		printf("N ");
	}else{
		printf("%d ", a2);
	}
	if(0 == cnt3){
		printf("N ");
	}else{
		printf("%d ", a3);
	}
	if(0 == cnt4){
		printf("N ");
	}else{
		printf("%.1f ", a4*1.0/cnt4);
	}
	if(0 == cnt5){
		printf("N");
	}else{
		printf("%d", a5);
	}

	free(us_input);
	return 0;
}
