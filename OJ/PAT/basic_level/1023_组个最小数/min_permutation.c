#include <stdio.h>
#define MAX 11

int main(){
	int us_num[MAX];
	int first_num=1;
	int i=0;

	for(i=0; i<10; i++){
		scanf("%d", &us_num[i]);
	}

	for(i=1; i<10; i++){
		if( us_num[i] ){
			first_num = i;
			us_num[i]--;
			break;
		}
	}

	printf("%d", first_num);
	for(i=0; i<10; i++){
		while( us_num[i] ){
			printf("%i", i);
			us_num[i]--;
		}
	}

	return 0;
}
