#ifndef MALLOCSTATSH
#define MALLOCSTATSH

#include <malloc.h>
#include <mcheck.h>

#define NSLOTS 1204
#define FACTOR 10

#define step(...) do { \
    printf(__VA_ARGS__); \
    (void) getc(stdin); \
    malloc_stats(); \
} while(0)

#define malloc_options_default() do { \
    mallopt(M_MXFAST, 64 * sizeof(size_t) / 4); \
    mallopt(M_ARENA_MAX, 0); \
    mallopt(M_ARENA_TEST, 2); \
    mallopt(M_MMAP_THRESHOLD, 128 * 1024); \
    mallopt(M_TOP_PAD, 128 * 1024); \
} while(0)

#define malloc_options_mmaponly() do { \
    mallopt(M_MXFAST, 0); \
    mallopt(M_ARENA_MAX, 0); \
    mallopt(M_MMAP_THRESHOLD, 1); \
    mallopt(M_TOP_PAD, 0); \
    mallopt(M_ARENA_TEST, 0); \
} while(0)

#endif /* MALLOCSTATSH */
