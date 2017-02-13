#include <stdio.h>

void merge_array(int a[], int left, int mid, int right, int temp[]){
    int i=left, j=mid+1;
    int k=0;

    while(i<=mid && j<=right){
        if(a[i]<a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
        }
    }

    while(i <= mid){
        temp[k++] = a[i++];
    }
    while(j <= right){
        temp[k++] = a[j++];
    }

    for(i=0; i<k; i++){
        a[left+i] = temp[i];
    }
}

void merge_sort(int a[], int left, int right, int temp[]){
    if(left < right){
        int mid = (left + right) / 2;

        merge_sort(a, left, mid, temp);
        merge_sort(a, mid+1, right, temp);
        merge_array(a, left, mid, right, temp);
    }
}


int main(){
    int a[]={4, 2, 7, 10, 3, 1, 3};
    int len=sizeof(a)/sizeof(a[0]);

    int temp[len];
    merge_sort(a, 0, len-1, temp);

    int index;
    for(index=0; index<len; index++){
        printf("%d\t", a[index]);
    }
    printf("\n");
}
