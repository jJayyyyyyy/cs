#include <stdio.h>

int main(){
	int us_N=0, sigma=0, cnt=0, is_start=1, i=0, j=0;
	int ID[40]={0}, output_num[40]={0};
	char str_num[5];

	scanf("%d", &us_N);
	for(i=0; i<us_N; i++){
		scanf("%s", str_num);
		sigma = 0;
		for( j=0; str_num[j]!='\0'; j++ )
			sigma += str_num[j] - '0';
		ID[sigma] = 1;
	}

	for( i=1; i<40; i++ ){
		if( ID[i] )
			output_num[cnt++] = i;
	}

	printf("%d\n", cnt);
	for( i=0; i<cnt; i++ ){
		if( is_start ){
			printf("%d", output_num[i]);
			is_start = 0;
		}
		else
			printf(" %d", output_num[i]);
	}

	return 0;
}
