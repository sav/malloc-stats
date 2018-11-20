#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include <malloc-stats.h>

bool run(void)
{
    char *ptr[NSLOTS];
    int i, pgsz = getpagesize();

    for (i = 0; i < NSLOTS; ++i) {
        if ( !(ptr[i] = malloc(FACTOR * pgsz)))
            return false;
    }
    step("step1: %d chunks allocated (%d pages of %d bytes)\n",
            NSLOTS, NSLOTS * FACTOR, pgsz);

    for (i = 0; i < NSLOTS - 1; ++i) {
        free(ptr[i]);
    }
    step("step2: %d slots freed, one slot pending\n", NSLOTS - 1);

    (void) malloc_trim(0);
    step("step2b: try trim data section\n");

    free(ptr[NSLOTS - 1]);
    step("step3: last slot freed\n");

    (void) malloc_trim(0);
    step("step3b: data section trimmed\n");

    return true;
}

bool test(void)
{
    malloc_options_default();
    return run();
}

int main(void)
{
    return test();
}
