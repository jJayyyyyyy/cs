#include <stdio.h>

int is_prime(int num)
{
    int i, num_remainder;
    for(i=2; i<num; i++){
        num_remainder = num % i;
        if(0 == num_remainder){
            return 0;
        }
    }

    return 1;
}

int main()
{
    int num;
    printf("Please input a number: ");
    scanf("%d", &num);
    (is_prime(num)==1)?printf("yes\n"):printf("no\n");

    return 1;
}
