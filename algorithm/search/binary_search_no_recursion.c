#include <stdio.h>

//increased a[]
int binary_search(int a[], int left, int right, int key)
{
    while(left <= right){
        int mid = (left+right) / 2;
        if(key < a[mid])
            right = mid - 1;
        else if(key > a[mid])
            left = mid + 1;
        else
            return mid;
    }

    return -1;
}

int main()
{
    int a[] = {11, 24, 39, 41, 57, 86};
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

    int index_of_key = binary_search(a, 0, len-1, key);
    if(index_of_key >= 0){
        printf("\nThe index of the key is: %d\n", index_of_key);
    }else{
        printf("Error! Not found!\n");
    }
}
