#include <stdio.h>

//O(n^2), 升序
void insert_sort(int a[], int len){
    int i,j;
    int key;
    for(i=1; i<len; i++){
        j = i;
        key = a[j];
        while(j>0 && a[j-1]>key){
            a[j] = a[j-1];
            j--;
        }
        a[j]=key;
    }
}

int main(){
    int a[]={4, 2, 7, 1, 3};
    int len=sizeof(a)/sizeof(a[0]);

    insert_sort(a, len);

    int index;
    for(index=0; index<len; index++){
        printf("%d\t", a[index]);
    }
    printf("\n");
}
