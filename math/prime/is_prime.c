#include <stdio.h>
#include <math.h>

int is_prime(int num){
	int divisor=1, up_bound=1;
	if( 2<num && num%2){
		up_bound = (int)sqrt(num);
		for(divisor=3; divisor<=up_bound; divisor+=2){
			if( 0 == num % divisor )
				return 0;
		}
		return 1;
	}else if( 2==num )
		return 1;
	else
		return 0;
}

int main(){
	int num;
	printf("Please input a number: ");
	scanf("%d", &num);
	(is_prime(num)==1)?printf("yes\n"):printf("no\n");

	return 0;
}
