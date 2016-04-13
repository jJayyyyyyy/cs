#include <stdio.h>

//从后往前，每次把最小的放到未排序部分的前面
void bubble_sort(int a[], int len){
    int i,j;
    for(i=0; i<len; i++)
        for(j=len-1; j>i; j--){
            if(a[j]<a[j-1]){
                int swap=a[j];
                a[j]=a[j-1];
                a[j-1]=swap;
            }
        }
}

int main(){
    int a[]={4, 2, 5, 1, 3, 2, 5, 1};
    int len=sizeof(a)/sizeof(a[0]);

    bubble_sort(a, len);

    int index;
    for(index=0; index<len; index++){
        printf("%d\t", a[index]);
    }
    printf("\n");
}
