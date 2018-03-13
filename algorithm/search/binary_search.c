#include <stdio.h>

int a[] = {11, 24, 39, 41, 57, 86};

// 用于升序排列的数组
int binary_search(int left, int right, int key){
	if(left <= right){
		int mid = (left + right) / 2;
		if(key < a[mid]){
			return binary_search(left, mid-1, key);
		}else if(key > a[mid]){
			return binary_search(mid+1, right, key);
		}else{
			return mid;
		}
	}

	return -1;
}

int main(){
	int len = sizeof(a)/sizeof(a[0]);

	int index;
	printf("The array is:\n");
	for(index=0; index<len; index++){
		printf("%d\t", a[index]);
	}
	printf("\n");
	
	int key=0;
	printf("Please input the key: ");
	scanf("%d", &key);

	int index_of_key = binary_search(0, len-1, key);
	if(index_of_key >= 0){
		printf("\nThe index of the key is: %d\n", index_of_key);
	}else{
		printf("Error! Not found!\n");
	}
}
