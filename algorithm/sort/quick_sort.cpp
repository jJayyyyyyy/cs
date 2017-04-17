#include <iostream>
#include <cstdio>

int partQuickSort(int a[], int left, int right)
{
	int i=left, j=right;
	int key = a[i];
	while( i < j ){
		while( i<j && a[j]>key )	j--;
		
		if( i < j )	a[i++] = a[j];

		while( i<j && a[i]<key )	i++;
		
		if( i < j )	a[j--] = a[i];
	}

	a[i] = key;
	return i;
}

int quickSort(int a[], int left, int right)
{
	if(left < right){
		int mid = partQuickSort(a, left, right);
		quickSort(a, left, mid-1);
		quickSort(a, mid+1, right);
	}
	return 0;
}

int main(){
	int a[] = {4, 2, 4, 3, 1, 5, 7};
	int len = sizeof(a)/sizeof(int);

	quickSort(a, 0, len-1);

	for(int i=0; i<len; i++){
		printf("%d ", a[i]);
	}

	return 0;
}