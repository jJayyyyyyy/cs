#include <stdio.h>
#include <time.h>

static unsigned long last_clock = 0;
static unsigned long sample_clock = CLOCKS_PER_SEC;

int compute()
{
    unsigned long now_clock = clock();
    unsigned long clock_change = now_clock - last_clock;

    if(clock_change >= sample_clock){
        //do something
        printf("%g\n", (double)clock()/CLOCKS_PER_SEC);
        //
        last_clock = now_clock;
    }
}

int main(){
    while(1){
        compute();
    }
}
