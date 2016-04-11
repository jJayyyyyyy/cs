#include <stdio.h>

void insert_sort(int a[], int len);

int main(int argc, const char * argv[])
{
	int a[6] = {4, 1, 5, 8, 2, 1};
	int len = 6;

	insert_sort(a, len);
	for(int index=0; index<len; index++){
		printf("%d\t", a[index]);
	}
	printf("\n");
}

void insert_sort(int a[], int len){
	int i,j;
	int key;
	for(j=1; j<len; j++){
		i = j - 1;
		key = a[j];
		while(i>=0 && a[i]>key){
			a[i+1] = a[i];
			i--;
		}
		a[i+1] = key;
	}
}