#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
	int us_input_size=0, us_input_i=0;
	int *us_input_arr;
	// int a=0, a1=0, a2=0, a3=0, a4=0, a5=0;
	// a[0]%10 is 0, a[1] is a1, a[i] is ai
	int a[6] = {0, 0, 0, 0, 0, 0};
	// int multi=1, cnt1=0, cnt2=0, cnt3=0, cnt4=0, cnt5=0;
	// cnt[0] is multiplier
	int cnt[6] = {1, 0, 0, 0, 0, 0};

	scanf("%d", &us_input_size);
	/*
	us_input_arr = (int *)malloc((us_input_size)*sizeof(int));
	if(us_input_arr == NULL){
		printf("Memory allocation failed!");
		exit(EXIT_FAILURE);
	}
	*/
	if( (us_input_arr = (int *)malloc((us_input_size)*sizeof(int))) == NULL ){
		printf("no more memory!");
		exit(EXIT_FAILURE);
	}

	while(us_input_i<us_input_size){
		if(scanf("%d", &us_input_arr[us_input_i])==1){
			a[0] = us_input_arr[us_input_i];
			if(0 == a[0]%10){
				a[1] += a[0];
				cnt[1] += 1;
			}
			if(1 == a[0]%5){
				a[2] += cnt[0]*a[0];
				cnt[0] = -cnt[0];
				cnt[2] += 1;
			}
			if(2 == a[0]%5){
				a[3] += 1;
				cnt[3] += 1;
			}
			if(3 == a[0]%5){
				a[4] += a[0];
				cnt[4] += 1;
			}
			if(4 == a[0]%5){
				if(a[5] < a[0]){
					a[5] = a[0];
				}
				cnt[5] += 1;
			}
			us_input_i++;
		}
	}

	if(0 == cnt[1]){
		printf("N ");
	}else{
		printf("%d ", a[1]);
	}
	if(0 == cnt[2]){
		printf("N ");
	}else{
		printf("%d ", a[2]);
	}
	if(0 == cnt[3]){
		printf("N ");
	}else{
		printf("%d ", a[3]);
	}
	if(0 == cnt[4]){
		printf("N ");
	}else{
		printf("%.1f ", a[4]*1.0/cnt[4]);
	}
	if(0 == cnt[5]){
		printf("N");
	}else{
		printf("%d", a[5]);
	}

	free(us_input_arr);

	return 0;
}
