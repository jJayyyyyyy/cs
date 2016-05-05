#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
    clock_t t1, t2;
    time_t current_time;

    t1 = clock();
    printf("%ld\n", t1);
    time(&current_time);
    printf("%ld\n", current_time);

    while(1){
        t2 = clock() - t1;
        if(t2 > CLOCKS_PER_SEC){
            printf("%ld\n", clock());
            time(&current_time);
            printf("%ld\n", current_time);
            break;
        }
    }
}
