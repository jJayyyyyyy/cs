#include <stdio.h>

void bubble_sort(int a[], int len);

int main(int argc, const char * argv[])
{
    //init
    int a[] = {6, 12, 6, 14, 5, 7, 2};
    int len = sizeof(a)/sizeof(a[0]);
    int index=0;

    //sort
    bubble_sort(a, len);

    //print
    for(index=0; index<len; index++){
        printf("%d\t", a[index]);
    }
    printf("\n");
}

void bubble_sort(int a[], int len){
    int i,j;
    for(i=0; i<len; i++){
        for(j=len-1; j>i; j--){
            if(a[j] < a[j-1]){
                a[j] = a[j] ^ a[j-1];
                a[j-1] = a[j] ^ a[j-1];
                a[j] = a[j] ^ a[j-1];
            }
        }
    }
}
