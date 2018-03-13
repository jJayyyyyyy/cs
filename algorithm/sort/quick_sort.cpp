#include <iostream>
#define MAXSIZE 16
using namespace std;

int a[MAXSIZE] = {4, 2, 6, 3, 1, 5, 7};

int partQuickSort(int left, int right){
	int i = left, j = right;
	int key = a[i];
	while( i < j ){
		while( i < j && a[j] > key ){
			j--;
		}
		
		if( i < j ){
			a[i++] = a[j];
		}

		while( i < j && a[i] < key ){
			i++;
		}
		
		if( i < j ){
			a[j--] = a[i];
		}
	}

	int mid = i;
	a[mid] = key;
	return mid;
}

/*
** 以a[left]为中轴key，把所有小于key的都放到它的左边，大的放到右边。
** 中轴的位置就固定了。
** 再对左边这一块和右边这一块，做同样的处理。
*/
int quickSort(int left, int right){
	if(left < right){
		int mid = partQuickSort(left, right);
		quickSort(left, mid-1);
		quickSort(mid+1, right);
	}
	return 0;
}

int main(){
	// int len = sizeof(a)/sizeof(int);
	int len = 7;

	quickSort(0, len-1);

	for( int i = 0; i < len; i++ ){
		cout<<a[i]<<' ';
	}

	return 0;
}