#include <stdio.h>


int main() {

    unsigned int characteristics = 0 ;
    // set with `characteristics |= (1 << 0);` and `characteristics |= (1 << 1);`

    for (int i = 0; i < 100; i++) {
        if (i % 3 == 0) { characteristics |= (1 << 0);}
        if (i % 5 == 0) { characteristics |= (1 << 1);}

        fprintf(stdout,"\nNUMBER : %i - ", i);

        if (characteristics & (1 << 0)) {
            fprintf(stdout,"FIZZ");
        }

        if (characteristics & (1 << 1)) {
            fprintf(stdout,"BUZZ");
        }

        // reset the bits for the next iteration
        characteristics &= ~(1 << 1);
        characteristics &= ~(1 << 0);
    }

    return 0;
}