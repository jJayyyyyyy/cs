#include <stdio.h>
#include <stdlib.h>

typedef struct{
	double stock;
	double total_price;
	double unit_price;
}Cake;

Cake *init(Cake *cake, int us_N){
	int i=0;

	for( i=0; i<us_N; i++ )
		scanf("%lf", &cake[i].stock);

	for( i=0; i<us_N; i++ ){
		scanf("%lf", &cake[i].total_price);
		cake[i].unit_price = cake[i].total_price / cake[i].stock;
	}

	return cake;
}

int cmp(const void *p1, const void *p2){
	const Cake *a1 = (const Cake *)p1;
	const Cake *a2 = (const Cake *)p2;

	if( a1->unit_price > a2->unit_price )
		return -1;
	else if( a1->unit_price==a2->unit_price )
		return 0;
	else
		return 1;
}

int main(){
	int us_N=0, demand=0;
	double gross_price=0.0;
	Cake *cake;
	int i=0;

	scanf("%d%d", &us_N, &demand);
	cake = (Cake *)malloc( us_N*sizeof(Cake) );
	cake = init(cake, us_N);
	qsort(cake, us_N, sizeof(Cake), cmp);

	for( i=0; i<us_N; i++ ){
		if( demand>=cake[i].stock ){
			gross_price += cake[i].total_price;
			demand -= cake[i].stock;
		}else{
			gross_price += demand * cake[i].unit_price;
			break;
		}
	}

	printf("%.2lf\n", gross_price);

	free(cake);
	return 0;
}
