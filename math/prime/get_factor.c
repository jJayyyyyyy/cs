#include <stdio.h>

int get_factor(int num){
	int factor = 2;
	while(1 != num){
		if(0 == num%factor){
			printf("%d\t", factor);
			num = num/factor;
		}else{
			break;
		}
	}

	factor = 3;
	while(1 != num){
		if(0 == num%factor){
			printf("%d\t", factor);
			num = num/factor;
		}else{
			factor += 2;
		}
	}

	return 0;
}

int main()
{
	int num;
	printf("Please input a number: ");
	scanf("%d", &num);
	get_factor(num);
	printf("\n");

	return 0;
}
