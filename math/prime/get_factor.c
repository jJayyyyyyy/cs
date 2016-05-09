#include <stdio.h>

int get_factor(int num)
{
    int i = 2;
    while(1 != num){
        if(0 == num%i){
            num = num/i;
            printf("%d\t", i);
        }else{
            i++;
        }
    }

    return 1;
}

int main()
{
    int num;
    printf("Please input a number: ");
    scanf("%d", &num);
    printf("Factors: ");
    get_factor(num);
    printf("\n");
    return 1;
}
