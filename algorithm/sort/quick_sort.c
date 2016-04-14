#include <stdio.h>

int quick_sort_part(int a[], int left, int right)
{
	int i=left, j=right;
	int key = a[i];
	while(i < j){
		while(i<j && a[j]>key){
			j--;
		}
		if(i<j){
			a[i] = a[j];
			i++;
		}

		while(i<j && a[i]<key){
			i++;
		}
		if(i<j){
			a[j] = a[i];
			j--;
		}
	}

	a[i] = key;
	return i;
}

void quick_sort(int a[], int left, int right)
{
	if(left < right){
		int mid = quick_sort_part(a, left, right);
		quick_sort(a, left, mid-1);
		quick_sort(a, mid+1, right);
	}
}

int main(){
	int a[] = {4, 2, 4, 3, 1, 5, 7};
	int len = sizeof(a)/sizeof(a[0]);

	quick_sort(a, 0, len-1);

	int index;
	for(index=0; index<len; index++){
		printf("%d\t", a[index]);
	}
	printf("\n");

}